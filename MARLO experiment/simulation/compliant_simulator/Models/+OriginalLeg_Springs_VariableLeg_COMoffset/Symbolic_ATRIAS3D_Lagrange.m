% function Symbolic_ATRIAS3D_Lagrange.m
%
% Revision History:
%   30/01/2012, KAH and BGB
%       Changed Mtotal and mTotal to 55 kg by scaling all masses.
%
%   2014-12-31, BGB
%       Improved code generation workflow.
%
%   2015-09-29, Ross H.
%       Made slight improvements. Modified the impact map foot coordinate
%       to the beginning of q (instead of the end)

clc
clear
close all

%% Model Options
ModelIndices        = [1,2];          % Indices of models to build (subset of [1, 2, ..., 5])

EnableSprings       = 1;            % 0: no springs
MotorModel          = 2;            % 0: None;  1: Complete;  2: Spong's simplified model
PositionsOnly       = true;         % If true, do not compute dynamic terms
CompileScriptPrefix = 'compileMex';
AppendToScript      = false;        % If true, compilation directives are appended to an existing script file
SelectedModel       = 'OriginalLeg'; % 'OriginalLeg'; % 
FunctionFolderName  = 'build_sim';

%% Model Names

ModelNames = {'Stance_RightLegZero' 'Stance_LeftLegZero'  ...
    'StanceRightImpactLeft' 'StanceLeftImpactRight' ...
    'TorsoXYZ'};  % add to list as needed

ModelNamesShort = {'Right', 'Left', 'StanceRight', 'StanceLeft', 'Hip'};

disp '..........................................................................................'
disp ' Symbolic code generator developed by : Chi and Grizzle, University of Michigan'
disp ''
disp ' Following models will be generated:'
for k=ModelIndices
    fprintf(' [%d] %s\n', k, ModelNames{k});
end
disp ''
disp '..........................................................................................'
clear k


%% Anonymous functions to facilitate creating arguments for symbolicToMex().
% The second and third arguments should be cell arrays with symbolic
% variables in the first column and strings in the second column. These
% anonymous functions create such cell arrays by getting the name of the
% input arguments. Note that this only works if the symbolic expression is
% a single symbolic variable; it will not work if the symbolic expression
% is something like jacobian(pcm,q) or Jcm*dq.
% The call to reshape handles the special case where no arguments are 
% provided, ensuring that the result is a 0 x 2 cell array instead of a 
% 0 x 0 cell array.
gatherVariables = @(varargin) [reshape(varargin,[],1) arrayfun(@inputname, (1:nargin).', 'Unif', 0)];
inputs  = gatherVariables; % Just an alias
outputs = gatherVariables; % Just an alias


%% Basic rotational matrices & skew symmetric operations
Rx = @(t) [1 0 0 ; 0 cos(t) -sin(t); 0 sin(t) cos(t)];
Ry = @(t) [cos(t) 0 sin(t); 0 1 0 ; -sin(t) 0 cos(t)];
Rz = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];

Ss = @(t) [0 -x(3) x(2); x(3) 0 -x(1); -x(2) x(1) 0];   % packing to a skew-symmetric matrix. Here, x is a 3-dim vector
Us = @(t) [x(3,2); x(1,3); x(2,1)];                     % unpacking skew-symmetric matrix operation. Here, x is a 3 x 3 matrix


%% Create directory for temp files
MatFolder = fullfile('.', FunctionFolderName, 'Mat');
if ~exist(MatFolder, 'dir')
    mkdir(MatFolder);
end

%% Generate selected models
KeepVariables = [who(); 'KeepVariables'; 'iterator'];

for iterator = ModelIndices
    
    % Start clean
    clearvars('-except', KeepVariables{:});
    
    % Get name and short name (used in generated file names) for current
    % model
    Model = ModelNames{iterator};  %choose which model to build
    ModelShort = ModelNamesShort{iterator};
    TempMatFile = fullfile(MatFolder, ['TempSymbolicData' ModelShort]);
        
    disp '..........................................................................................'
    disp ''
    disp(Model);
    disp ''
    disp '..........................................................................................'
    
    % Initialize script for building mex files
    ScriptName = sprintf('%s%s.m', CompileScriptPrefix, ModelShort);
    symbolicToMex('',{},{}, ...
        'AutogenPath', FunctionFolderName, ...
        'ScriptName', ScriptName, ...
        'BaseFileName', ['ATRIAS3D_<FNAME>_' ModelShort], ...
        'AppendToScript', AppendToScript ...
        );
    
    tic;
    physic = ATRIAS3D_Physic(SelectedModel);
    digits(16); % precision of physical parameters.
    
    %% Model parameters
    syms L1 L2 L3 L4 LT m1 m2 m3 m4 m5 m6 
    syms ellhcm1 ellhcm2 ellhcm3 ellhcm4 
    syms ellvcm1 ellvcm2 ellvcm3 ellvcm4 
    syms Jcm1 Jcm2 Jcm3 Jcm4 
    syms Jcmx1 Jcmx2 Jcmx3 Jcmx4 Jcmy1 Jcmy2 Jcmy3 Jcmy4  %% Jcmxi = Jcmyi = Jcmi
    syms Jcmz1 Jcmz2 Jcmz3 Jcmz4 
    
    syms g W mH JcmH ellhcmH ellvcmH JcmxH JcmyH JcmzH 
    syms LT mT JcmT ellhcmT ellvcmT JcmxT JcmyT JcmzT 
    
    syms Jrotor1 Jrotor2 Jrotor3 Jgear1 Jgear2 Jgear3 r1 r2 r3 

    
    % Revised by Ali and Kaveh to generate symmetric model for center of mass
    % coordinates (05/02/2012). We introduce a matrix S to obtain the correct vaules of the
    % center of mass for the right and left legs. We do not revise the physical
    % parameters of the robot. The parameters in ATRIAS3D_physics were obtained for the right leg.
    
    % Variable leg length (RH - 10/10/2016)
    syms leg_length torso_com_offset_x torso_com_offset_y torso_com_offset_z
    extra_vars = [leg_length; torso_com_offset_x; torso_com_offset_y; torso_com_offset_z];
    
    S = diag([-1 1 1]);
    
    g  = vpa(9.81);
    m1 = vpa(physic.shin.mass);
    m2 = vpa(physic.thigh.mass);
    m3 = vpa(physic.four_bar_link.mass);
    m4 = vpa(physic.lower_leg.mass);
    m5 = vpa(physic.shinspring.mass);
    m6 = vpa(physic.thighspring.mass);
    mT = vpa(physic.torso.mass);
    mH = vpa(physic.hip.mass);
    L1 = vpa(physic.shin.length);
    L2 = vpa(physic.thigh.length);
    L3 = vpa(physic.four_bar_link.length);
    L4 = extra_vars(1); %vpa(physic.lower_leg.length);
    LT = vpa(physic.torso.length);
    W  = vpa(physic.hip.length);
    Jrotor1 = vpa(physic.Jrotor1);
    Jrotor2 = vpa(physic.Jrotor2);
    Jrotor3 = vpa( physic.Jrotor3);
    Jgear1  = vpa(physic.Jgear1);
    Jgear2  = vpa(physic.Jgear2);
    Jgear3  = vpa(physic.Jgear3);
    r1 = vpa(physic.r1);
    r2 = vpa(physic.r2);
    r3 = vpa(physic.r3);
    % K1 = vpa(physic.K1);
    % K2 = vpa(physic.K2);
    
    Mtotal = mT + 2*(mH + m1 + m2 + m3 + m4 + m5 + m6);
    
    % Inertia matrices
    % syms IcmT IcmH Icm1 Icm2 Icm3 Icm4 Icm5 Icm6
    IcmT = vpa(physic.torso.I);
    IcmH = vpa(physic.hip.I);
    Icm1 = vpa(physic.shin.I);
    Icm2 = vpa(physic.thigh.I);
    Icm3 = vpa(physic.four_bar_link.I);
    Icm4 = vpa(physic.lower_leg.I);
    Icm5 = vpa(physic.shinspring.I);
    Icm6 = vpa(physic.thighspring.I);
    
    Igr1 = [Jgear1 0 0; 0 0 0; 0 0 0];
    Igr2 = [Jgear2 0 0; 0 0 0; 0 0 0];
    Igr3 = [0 0 0; 0 Jgear3 0; 0 0 0];
    
    Imot1 = [Jrotor1 0 0; 0 0 0; 0 0 0];
    Imot2 = [Jrotor2 0 0; 0 0 0; 0 0 0];
    Imot3 = [0 0 0; 0 Jrotor3 0; 0 0 0];
    
%     symbolicToMex('FixedParameters', inputs(), ...
%         outputs(Mtotal, g, m1, m2, m3, m4, m5, m6, mT, mH, L1, L2, L3, L4, LT, W, Jrotor1, Jrotor2, Jrotor3, r1, r2, r3, ...
%         IcmT, IcmH, Icm1, Icm2, Icm3, Icm4, Icm5, Icm6, Igr1, Igr2, Igr3, Imot1, Imot2, Imot3));
    
    
    %% Generalized coordinates
    syms xT yT zT qzT qyT qxT        %% torso translational and rotational coordinates
    syms dxT dyT dzT dqzT dqyT dqxT 
   
    syms q1R q2R q3R q1L q2L q3L     %% right & left leg joint angles
    syms dq1R dq2R dq3R dq1L dq2L dq3L 
    
    syms x0 y0 z0 qz0 qy0 qx0        %% right foot position and rotational angles
    syms dx0 dy0 dz0 dqz0 dqy0 dqx0 
    
    syms qgr1R qgr2R  dqgr1R dqgr2R     %gear reducer coordinates; are probably better numerically
    syms qgr1L qgr2L  dqgr1L dqgr2L    %than the motor coordinates, due to the low inertia of the rotors

    
    switch Model           %add cases as needed
        
        case {'TorsoXYZ'}  % Standard SS Model
            if EnableSprings
                q = [xT; yT; zT; qzT; qyT; qxT; q1R; q2R; q1L; q2L; qgr1R; qgr2R; q3R; qgr1L; qgr2L; q3L];
                dq= [dxT; dyT; dzT; dqzT; dqyT; dqxT; dq1R; dq2R; dq1L; dq2L; dqgr1R; dqgr2R; dq3R; dqgr1L; dqgr2L; dq3L];
                disp('Building Flight Phase Model with Springs and with Cartesian Frame Attached to the Base of Torso')
            else
                qgr1R=q1R; qgr2R=q2R; qgr1L=q1L; qgr2L=q2L;
                dqgr1R=dq1R; dqgr2R=dq2R; dqgr1L=dq1L; dqgr2L=dq2L;
                q = [xT; yT; zT; qzT; qyT; qxT; q1R; q2R; q3R; q1L; q2L; q3L];
                dq= [dxT; dyT; dzT; dqzT; dqyT; dqxT; dq1R; dq2R; dq3R; dq1L; dq2L; dq3L];
                disp('Building Flight Phase Model without Springs and with Cartesian Frame Attached to the Base of Torso')
            end
        otherwise
            if EnableSprings
                q = [qzT; qyT; qxT; q1R; q2R; q1L; q2L; qgr1R; qgr2R; q3R; qgr1L; qgr2L; q3L];
                dq= [dqzT; dqyT; dqxT; dq1R; dq2R; dq1L; dq2L; dqgr1R; dqgr2R; dq3R; dqgr1L; dqgr2L; dq3L];
                disp('Building a Single Support Model with Springs')
            else
                qgr1R=q1R; qgr2R=q2R; qgr1L=q1L; qgr2L=q2L;
                dqgr1R=dq1R; dqgr2R=dq2R; dqgr1L=dq1L; dqgr2L=dq2L;
                %
                q = [qzT; qyT; qxT; q1R; q2R; q3R; q1L; q2L; q3L];
                dq= [dqzT; dqyT; dqxT; dq1R; dq2R; dq3R; dq1L; dq2L; dq3L];
                disp('Building a Single Support Model without Springs')
            end
    end
    
    %  motor and gear coordinates
    qm1R = r1*qgr1R; qm2R = r2*qgr2R;  qgr3R =q3R; qm3R = r3*qgr3R;
    qm1L = r1*qgr1L; qm2L = r2*qgr2L;  qgr3L =q3L; qm3L = r3*qgr3L;
    
    dqm1R = r1*dqgr1R; dqm2R = r2*dqgr2R;  dqgr3R =dq3R; dqm3R = r3*dqgr3R;
    dqm1L = r1*dqgr1L; dqm2L = r2*dqgr2L;  dqgr3L =dq3L; dqm3L = r3*dqgr3L;
    
    
    %% Rotation matrices and angular velocities
    disp('Step 1: Compute rotation matrices and angular velocities');
    
    RA = [1 0 0; 0 1 0; 0 0 1];    % Reference coordinate RA at Right Foot
    R0 = RA;
    
    w0 = R0(:,3)*dqzT; 
    R0 = R0*Rz(qzT); % Rotation about yaw
    
    w0 = w0 + R0(:,2)*dqyT;
    R0 = R0*Ry(qyT); % Rotation about roll
    
    w0 = w0 + R0(:,1)*dqxT;      w0 = simplify(w0);     % torso angular velocity
    R0 = R0*Rx(qxT); % Rotation about pitch             % torso rotational matrix
    
    if 0  %% same result
        dR0 = diff(R0,'qzT')*dqzT + diff(R0,'qyT')*dqyT + diff(R0,'qxT')*dqxT;
        S0 = transpose(R0)*dR0;
        S0 = simplify(S0);
        Omega0 = [S0(3,2); S0(1,3); S0(2,1)];
        simplify(R0*Omega0- w0)
    end
    
    wHR = w0 + R0(:,2)*dq3R;     wHR = simplify(wHR); % right hip angular velocity
    R3 = R0*Ry(q3R); % Right hip rotational matrix
    R3m3 = R0*Ry(qm3R);
    R3gr3 = R0*Ry(qgr3R);
    
    if 0  %% same result
        dR3 = diff(R3,'qzT')*dqzT + diff(R3,'qyT')*dqyT + diff(R3,'qxT')*dqxT + diff(R3, 'q3R')*dq3R;
        S3 = transpose(R3)*dR3;
        S3 = simplify(S3);
        Omega3 = [S3(3,2); S3(1,3); S3(2,1)];
        simplify(R3*Omega3-wHR)
    end
    
    %Right Side of Robot
    w1R = wHR + R3(:,1)*dq1R;    w1R = simplify(w1R);
    w4R = w1R;
    R1 = R3*Rx(q1R);
    R1m1 = R3*Rx(qm1R);
    R1gr1 = R3*Rx(qgr1R);
    

    w2R = wHR + R3(:,1)*dq2R;    w2R = simplify(w2R);
    w3R = w2R;
    R2 = R3*Rx(q2R);
    R2m2 = R3*Rx(qm2R);
    R2gr2 = R3*Rx(qgr2R);
    
    %Motors and Gears on Right Side
    wm3R = w0 + R0(:,2)*dqm3R;     wm3R = simplify(wm3R);
    wgr3R = w0 + R0(:,2)*dqgr3R;   wgr3R = simplify(wgr3R);
    
    wm1R =  wHR + R3(:,1)*dqm1R;     wm1R = simplify(wm1R);
    wgr1R =  wHR + R3(:,1)*dqgr1R;   wgr1R = simplify(wgr1R);
    
    wm2R =  wHR + R3(:,1)*dqm2R ;    wm2R = simplify(wm2R);
    wgr2R =  wHR + R3(:,1)*dqgr2R;   wgr2R = simplify(wgr2R);
    
    %Left Side of Robot
    wHL = w0 - R0(:,2)*dq3L;     wHL = simplify(wHL);
    R4 = R0*Ry(-q3L);
    R4m3 = R0*Ry(-qm3L);
    R4gr3 = R0*Ry(-qgr3L);
    
    w1L = wHL + R4(:,1)*dq1L;    w1L = simplify(w1L);
    w4L = w1L;
    R5 = R4*Rx(q1L);
    R5m1 = R4*Rx(qm1L);
    R5gr1 = R4*Rx(qgr1L);
    
    w2L = wHL + R4(:,1)*dq2L;    w2L = simplify(w2L);
    w3L = w2L;
    R6 = R4*Rx(q2L);
    R6m2 = R4*Rx(qm2L);
    R6gr2 = R4*Rx(qgr2L);
    
    %Motors and Gears on Left Side
    wm3L = w0 + R0(:,2)*dqm3L;     wm3L = simplify(wm3L);
    wgr3L = w0 + R0(:,2)*dqgr3L;   wgr3L = simplify(wgr3L);
    
    wm1L =  wHL + R4(:,1)*dqm1L;     wm1L = simplify(wm1L);
    wgr1L =  wHL + R4(:,1)*dqgr1L;   wgr1L = simplify(wgr1L);
    
    wm2L =  wHL + R4(:,1)*dqm2L;     wm2L = simplify(wm2L);
    wgr2L =  wHL + R4(:,1)*dqgr2L;   wgr2L = simplify(wgr2L);
    
    toc, tic
    save(TempMatFile)
    
    %% Positions and velocities
    disp('Step 2: Compute joint position vectors & CoM positions & velocities');
    
    % compute the right foot position
    p0 = [xT; yT; zT];
    % Set XYZ coordinate position. Leave angles at the torso
    switch Model            %add cases as needed
        case {'Stance_RightLegZero'}  % Standard Stance on Right Leg
            pHR = p0 + R3*[W; 0; 0];
            p1R = pHR + R1*[0; 0; L1];
            p2R = pHR + R2*[0; 0; L2];
            p3R = p1R + R2*[0; 0; L3];
            p4R = p2R + R1*[0; 0; L4];
            p0 = p0-p4R;                    p0 = simplify(p0);   %p0(1)=p0(1)+2*W;
            disp('Building Model with Cartesian position of Right Foot = [0;0;0]')

        case {'Stance_LeftLegZero'}  % Standard Stance on Left Leg
            pHL = p0 + R4*[-W; 0; 0];
            p1L = pHL + R5*[0; 0; L1];
            p2L = pHL + R6*[0; 0; L2];
            p3L = p1L + R6*[0; 0; L3];
            p4L = p2L + R5*[0; 0; L4];
            p0 = p0-p4L;                    p0 = simplify(p0);
            disp('Building Model with Cartesian position of Left Foot = [0;0;0]')

        case {'StanceRightImpactLeft'}
            syms xR yR zR dxR dyR dzR
            q=[xR; yR; zR; q]; dq=[dxR; dyR; dzR; dq];
            pHR = p0 + R3*[W; 0; 0];
            p1R = pHR + R1*[0; 0; L1];
            p2R = pHR + R2*[0; 0; L2];
            p3R = p1R + R2*[0; 0; L3];
            p4R = p2R + R1*[0; 0; L4];
            p0 = p0-p4R;                    p0 = simplify(p0);   p0 = p0 + [xR; yR; zR];
            disp('Building Model with Cartesian Frame [xR; yR; zR] Attached to the foot of the Right Leg')

        case {'StanceLeftImpactRight'}
            syms xL yL zL dxL dyL dzL
            q=[xL; yL; zL; q]; dq=[dxL; dyL; dzL; dq];
            pHL = p0 + R4*[-W; 0; 0];
            p1L = pHL + R5*[0; 0; L1];
            p2L = pHL + R6*[0; 0; L2];
            p3L = p1L + R6*[0; 0; L3];
            p4L = p2L + R5*[0; 0; L4];
            p0 = p0-p4L;                    p0 = simplify(p0);  p0 = p0 + [xL; yL; zL];
            disp('Building Model with Cartesian Frame [xL; yL; zL] Attached to the foot of the Left Leg')

       otherwise
            disp('Building flight phase model')
    end
    
    % compute the biped center and torso com position
    p0T = p0 + R0*[0; 0; LT];                 p0T = simplify(p0T);
        
    pcmT = p0 + R0*(physic.torso.com + extra_vars(2:4));          pcmT = simplify(pcmT);
    vcmT = jacobian(pcmT,q)*dq;               vcmT = simplify(vcmT);
    
    % compute the right leg's joint & com positions
    pHR = p0 + R3*[W; 0; 0];                     pHR = simplify(pHR);
    pcmHR = p0 + R3*physic.hip.com;              pcmHR = simplify(pcmHR);
    vcmHR = jacobian(pcmHR,q)*dq;                vcmHR = simplify(vcmHR);
    
    p1R = pHR + R1*[0; 0; L1];                   p1R = simplify(p1R);
    pcm1R = pHR + R1*physic.shin.com;            pcm1R = simplify(pcm1R);
    vcm1R = jacobian(pcm1R,q)*dq;                vcm1R = simplify(vcm1R);
    
    p2R = pHR + R2*[0; 0; L2];                   p2R = simplify(p2R);
    pcm2R = pHR + R2*physic.thigh.com;           pcm2R = simplify(pcm2R);
    vcm2R = jacobian(pcm2R,q)*dq;                vcm2R = simplify(vcm2R);
    
    p3R = p1R + R2*[0; 0; L3];                   p3R = simplify(p3R);
    pcm3R = p1R + R2*physic.four_bar_link.com;   pcm3R = simplify(pcm3R);
    vcm3R = jacobian(pcm3R,q)*dq;                vcm3R = simplify(vcm3R);
    
    p4R = p2R + R1*[0; 0; L4];                   p4R = simplify(p4R);
    pcm4R = p2R + R1*physic.lower_leg.com;       pcm4R = simplify(pcm4R);
    vcm4R = jacobian(pcm4R,q)*dq;                vcm4R = simplify(vcm4R);
    
    pcm5R = pHR + R1gr1*physic.shinspring.com;            pcm5R = simplify(pcm5R);
    vcm5R = jacobian(pcm5R,q)*dq;                vcm5R = simplify(vcm5R);
    
    pcm6R = pHR + R2gr2*physic.thighspring.com;            pcm6R = simplify(pcm6R);
    vcm6R = jacobian(pcm6R,q)*dq;                vcm6R = simplify(vcm6R);
    
    % compute the left leg's joint & com positions
    pHL = p0 + R4*[-W; 0; 0];                    pHL = simplify(pHL);
    pcmHL = p0 + R4*S*physic.hip.com;              pcmHL = simplify(pcmHL);
    vcmHL = jacobian(pcmHL,q)*dq;                vcmHL = simplify(vcmHL);
    
    p1L = pHL + R5*[0; 0;L1];                    p1L = simplify(p1L);
    pcm1L = pHL + R5*S*physic.shin.com;            pcm1L = simplify(pcm1L);
    vcm1L = jacobian(pcm1L,q)*dq;                vcm1L = simplify(vcm1L);
    
    p2L = pHL + R6*[0; 0; L2];                   p2L = simplify(p2L); 
    pcm2L = pHL + R6*S*physic.thigh.com;           pcm2L = simplify(pcm2L);
    vcm2L = jacobian(pcm2L,q)*dq;                vcm2L = simplify(vcm2L);
    
    p3L = p1L + R6*[0; 0; L3];                   p3L = simplify(p3L);
    pcm3L = p1L + R6*S*physic.four_bar_link.com;   pcm3L = simplify(pcm3L);
    vcm3L = jacobian(pcm3L,q)*dq;                vcm3L = simplify(vcm3L);
    
    p4L = p2L + R5*[0; 0; L4];                   p4L = simplify(p4L);
    pcm4L = p2L + R5*S*physic.lower_leg.com;       pcm4L = simplify(pcm4L);
    vcm4L = jacobian(pcm4L,q)*dq;                vcm4L = simplify(vcm4L);
    
    pcm5L = pHL + R5gr1*S*physic.shinspring.com;            pcm5L = simplify(pcm5L);
    vcm5L = jacobian(pcm5L,q)*dq;                vcm5L = simplify(vcm5L);
    
    pcm6L = pHL + R6gr2*S*physic.thighspring.com;            pcm6L = simplify(pcm6L);
    vcm6L = jacobian(pcm6L,q)*dq;                vcm6L = simplify(vcm6L);
    
    
    pcm = (mT*pcmT + mH*(pcmHR+pcmHL) + m1*(pcm1R+pcm1L) + m2*(pcm2R+pcm2L) + m3*(pcm3R+pcm3L) + m4*(pcm4R+pcm4L) + ...
        m5*(pcm5R+pcm5L) + m6*(pcm6R+pcm6L))/Mtotal;
    
    % Compute Foot yaw w.r.t. world frame
    p4R_yaw = atan(R1(2,1)/R1(1,1));
    p4L_yaw = atan(R5(2,1)/R5(1,1));
    
    v0    = jacobian(p0,q)*dq;
    v0T   = jacobian(p0T,q)*dq;
    vHL   = jacobian(pHL,q)*dq;
    vHR   = jacobian(pHR,q)*dq;
    vcm   = jacobian(pcm,q)*dq;
    J_cm  = jacobian(pcm,q);
    dJ_cm = jacobian(J_cm*dq,q);
    
    J4R   = simplify(jacobian(p4R,q)); % Right Foot
    dJ4R  = simplify(jacobian(J4R*dq,q)*dq); 
    J4L   = simplify(jacobian(p4L,q)); % Left Foot
    dJ4L  = simplify(jacobian(J4L*dq,q)*dq);
    
    Jp4R_yaw  = simplify(jacobian(w4R(3),dq)); % Right Foot Yaw 
    dJp4R_yaw  = simplify(jacobian(Jp4R_yaw*dq,q)*dq);
    Jp4L_yaw  = simplify(jacobian(w4L(3),dq)); % Left Foot Yaw
    dJp4L_yaw  = simplify(jacobian(Jp4L_yaw*dq,q)*dq);
    
    switch Model
        case {'StanceRightImpactLeft','StanceLeftImpactRight'}
            Jac_wStance=0*J_cm; Jac_wSwing=0*J_cm; dJac_wStance= 0*dJ_cm; dJac_wSwing=0*dJ_cm;
            disp('Step 2a: Generate ATRIAS3D_points.m for joint positions');
            symbolicToMex('PrimaryPointsAnim', inputs(q), outputs(pcm,p0,p0T,pHR,p1R,p2R,p3R,p4R,pHL,p1L,p2L,p3L,p4L));

        otherwise
            disp('Step 2a: Generate ATRIAS3D_points.m for joint positions');
            outputs(pcm,p0,p0T,pHR,p1R,p2R,p3R,p4R,pHL,p1L,p2L,p3L,p4L);
            symbolicToMex('Positions', inputs(q,extra_vars), outputs(pcm,p0,p0T,pHR,p1R,p2R,p3R,p4R,pHL,p1L,p2L,p3L,p4L));

%             disp('Step 2b: Generate ATRIAS3D_points.m for CoM positions');
%             symbolicToMex('COMPositions', inputs(q,leg_length), outputs(pcm,pcmT,pcmHR,pcm1R,pcm2R,pcm3R,pcm4R,pcmHL,pcm1L,pcm2L,pcm3L,pcm4L));

            disp('Step 2c: Generate Velocities and Jacobians for GRF');
%             symbolicToMex('COMJacob', inputs(q, dq, leg_length), outputs(J_cm, dJ_cm));
            symbolicToMex('VelocitiesAccel', inputs(q, dq, extra_vars), outputs(vcm, J_cm, dJ_cm, v0T, vHL, vHR, v0));

%             disp('Step 2d: Generate ATRIAS3D_spring_points.m for CoM positions');
%             symbolicToMex('PositionsSpringCOM', inputs(q, leg_length), outputs(pcm5R, pcm6R, pcm5L, pcm6L));
%             
%             symbolicToMex('RightFootJacobian', inputs(q, leg_length), outputs(J4R));
%             symbolicToMex('LeftFootJacobian', inputs(q, leg_length), outputs(J4L));
%             symbolicToMex('FootPositionJacobians', inputs(q, dq, leg_length), outputs(J4R, J4L, dJ4R, dJ4L));
%             symbolicToMex('FootYawJacobians', inputs(q, dq, leg_length), outputs(Jp4R_yaw, Jp4L_yaw, dJp4R_yaw, dJp4L_yaw));
%             symbolicToMex('FootYaw', inputs(q, leg_length), outputs(p4R_yaw, p4L_yaw));

    end

%     switch Model
%         case {'Stance_RightLegZero', 'StanceRightImpactLeft'}
%             pSwing = p4L;
%             symbolicToMex('HipPosVel', inputs(q, dq), outputs(p0,v0,pSwing));
% 
%         case {'Stance_LeftLegZero', 'StanceLeftImpactRight'}
%             pSwing = p4R;
%             symbolicToMex('HipPosVel', inputs(q, dq), outputs(p0,v0,pSwing));
%     end
            
    if PositionsOnly
        toc, tic
        save(TempMatFile)
        continue  % Stop after writing the points file
    end
    
    %% Additional terms for special purposes
    
    % KAH  Boom Model
    % Added by Kaveh to consider the effects of adding boom
    % When we want to add the boom dynamics to the ATRIAS3D model, we first
    % augment the state vector of ATRIAS3D with the states of the boom.
    % Then, we consider the holonomic constraints representing the
    % attachment of ATRIAS3D and the boom. The holonomic constraints are
    % defined for the position, yaw and roll
    % angles at the top of the robot.
    
%     pTorso = [qzT; qyT; p0T];
%     
%     % Thus, dim(pTosro) = 5. Now, the restricted system has
%     % 13 + 2 - 5 = 10 DOFs. This section calculates the Jacobians of these
%     % constraints.
%     jacob_pTorso = jacobian(pTorso,q);
%     jacob_pTorso = simplify(jacob_pTorso);
%     
%     jacob_jacob_pTorso = jacobian(jacob_pTorso*dq,q)*dq;
%     jacob_jacob_pTorso = simplify(jacob_jacob_pTorso);
%     
%     switch Model
%         case {'Stance_RightLegZero', 'Stance_LeftLegZero', 'StanceRightImpactLeft', 'StanceLeftImpactRight'}
%             symbolicToMex('JacobianTop', inputs(q, dq), outputs(pTorso, jacob_pTorso, jacob_jacob_pTorso));
%     end
%     
%     % BGB  Alternative boom model (kinematic constraint ignoring boom dynamics)
%     syms xB yB zB
%     pB  = [xB; yB; zB];
%     pB0 = p0 + R0*[xB; yB; zB];                 pB0 = simplify(pB0);
%     jacob_pB0 = simplify(jacobian(pB0,q));
%     
%     jacob_jacob_pB0 = jacobian(jacob_pB0*dq,q)*dq;
%     jacob_jacob_pB0 = simplify(jacob_jacob_pB0);
%     
%     symbolicToMex('BoomPosition', inputs(q, pB), outputs(pB0));
%     symbolicToMex('BoomJacob', inputs(q, dq, pB), outputs(jacob_pB0, jacob_jacob_pB0));
%     % END BGB
%     
%     % BGB  Pseudo-VPP with parametrized position along the torso vertical axis
%     syms LVPP
%     pVPP = p0 + R0*[0; 0; LVPP];                 pVPP = simplify(pVPP);
%     jacob_pVPP = simplify(jacobian(pVPP,q));
%     symbolicToMex('PseudoVPP', inputs(q, LVPP), outputs(jacob_pVPP));
    % END BGB    
    
    % BGB 2014-03-07
    %{
    J0 = simplify(jacobian(p0, q));
    v0 = J0*dq;
    fcn_name = ['HipPosVel',Model,Params];
    if strcmpi(Model, 'Left')
        StringVarVector = 'p0,v0,p4R';
    elseif strcmpi(Model, 'Right')
        StringVarVector = 'p0,v0,p4L';
    end
    generate_mfun;
    continue;
    %}
    % BGB 2014-03-07 (END)
    
    
    % BGB 2014-03-08
    %{
    J0 = simplify(jacobian(p0, q));
    fcn_name = ['HipSwingJacob',Model,Params];
    if strcmpi(Model, 'Left')
        J4 = simplify(jacobian(p4R, q));
    elseif strcmpi(Model, 'Right')
        J4 = simplify(jacobian(p4L, q));
    end
    StringVarVector = 'J0,J4';
    generate_mfun;
    continue;
    %}
    % BGB 2014-03-08 (END)
    
    % BGB 2014-03-18
    %{
    J0 = simplify(jacobian(p0, q));
    if strcmpi(ModelShort, 'Left')
        J4 = simplify(jacobian(p4R, q));
    elseif strcmpi(ModelShort, 'Right')
        J4 = simplify(jacobian(p4L, q));
    end
    dJ4 = simplify(jacobian(J4*dq, q));
    symbolicToMex('SwingFootJacobians', inputs(q, dq), outputs(J4, dJ4));
    continue;
    %}
    % BGB 2014-03-11 (END)
    
    
    % Added by Kaveh to obtain the Jacobian of the vertical component of
    % the swing leg end during the right stance. We will make use of this
    % during perturbation to calculate the Jacobian of the restricted
    % Poincare return map. To make this notion more precise, we should note
    % that the Poincare map is defined from S into S. Thus, we will need the
    % Jacobain jacobian_p4L_v for projection map.
%     jacobian_p4L_v = jacobian(p4L(3),q);
%     
%     
%     % BGB
%     vcm_sagittal = simplify(subs(vcm,{qzT, dqzT},{0, 0}));
%     % END BGB
%     
%     
%     % CoM in the frontal plane
%     pcm_h_fr = cos(qzT) * pcm(1) + sin(qzT) * pcm(2);
%     pcm_h_fr = simple(pcm_h_fr);
%     pcm_v_fr = pcm(3);
%     
%     % Swing leg end in the frontal plane
%     switch Model
%         case {'Stance_RightLegZero', 'StanceRightImpactLeft'}
%             pswing = p4L;
%             
%         case {'Stance_LeftLegZero', 'StanceLeftImpactRight'}
%             pswing = p4R;
%     end
% 
%     switch Model
%         case {'Stance_RightLegZero', 'Stance_LeftLegZero', 'StanceRightImpactLeft', 'StanceLeftImpactRight'}
% 
%             pswing_h_fr = cos(qzT) * pswing(1) + sin(qzT) * pswing(2);
%             pswing_h_fr = simple(pswing_h_fr);
%             pswing_v_fr = pswing(3);
% 
%             % Jacobians
%             jacob_pcm_h_fr = jacobian(pcm_h_fr,q);
%             jacob_pcm_h_fr = simple(jacob_pcm_h_fr);
%             jacob_jacob_pcm_h_fr = jacobian(jacob_pcm_h_fr,q);
%             jacob_jacob_pcm_h_fr = simple(jacob_jacob_pcm_h_fr);
% 
%             jacob_pcm_v_fr = jacobian(pcm_v_fr,q);
%             jacob_pcm_v_fr = simple(jacob_pcm_v_fr);
%             jacob_jacob_pcm_v_fr = jacobian(jacob_pcm_v_fr,q);
%             jacob_jacob_pcm_v_fr = simple(jacob_jacob_pcm_v_fr);
% 
%             jacob_pswing_h_fr = jacobian(pswing_h_fr,q);
%             jacob_pswing_h_fr = simple(jacob_pswing_h_fr);
%             jacob_jacob_pswing_h_fr = jacobian(jacob_pswing_h_fr,q);
%             jacob_jacob_pswing_h_fr = simple(jacob_jacob_pswing_h_fr);
% 
%             jacob_pswing_v_fr = jacobian(pswing_v_fr,q);
%             jacob_pswing_v_fr = simple(jacob_pswing_v_fr);
%             jacob_jacob_pswing_v_fr = jacobian(jacob_pswing_v_fr,q);
%             jacob_jacob_pswing_v_fr = simple(jacob_jacob_pswing_v_fr);
% 
%             fcn_name = ['variables_in_fp',Model];
%             symbolicToMex('SwingFootJacobiansFrontal', inputs(q, dq), outputs(jacob_pswing_v_fr, jacob_pswing_h_fr, jacob_jacob_pswing_v_fr, jacob_jacob_pswing_h_fr));
%             symbolicToMex('COMJacobiansFrontal', inputs(q, dq), outputs(jacob_pcm_v_fr, jacob_pcm_h_fr, jacob_jacob_pcm_v_fr, jacob_jacob_pcm_h_fr));
%     end
%     
    disp('Key positions and velocities computed')
    
    %% Yaw constraints and torques
    
    % Added by Kaveh to consider the friction about the stance leg end. The
    % variables obatined here can also be used to restrict the yaw motion
    % about the stance leg end.
    switch Model
        case {'Stance_RightLegZero'}
            w_stance = w4R(3);
                 
        case {'Stance_LeftLegZero'}
            w_stance = w4L(3);
            
        case {'StanceRightImpactLeft'}
            positionSwingFoot = p4L;
            w_zSwingFoot      = w4L(3);
            
        case {'StanceLeftImpactRight'}
            positionSwingFoot = p4R;
            w_zSwingFoot      = w4R(3);
    end
    
    switch Model
        case {'Stance_RightLegZero', 'Stance_LeftLegZero'}
            E = jacobian(w_stance,dq);
            jacob_Edq_dq = jacobian(E*dq,q)*dq;
            symbolicToMex('StanceYaw', inputs(q, dq), outputs(E, jacob_Edq_dq));
            
        case {'StanceRightImpactLeft', 'StanceLeftImpactRight'}                    
            E1 = [jacobian(positionSwingFoot,q); jacobian(w_zSwingFoot,dq)];
            E2 = jacobian(positionSwingFoot,q);
    end
    
    
    %{
    WhichFrame='inertial';
    switch Model
        case {'Stance_RightLegZero'}
            switch WhichFrame
                case {'body'}
                    w4RBody=transpose(R1)*w4R;
                    Jac_wStance=jacobian(w4RBody,dq);  %only need z-component
                    dJac_wStance=jacobian(Jac_wStance*dq,q); % but write all three for size
                    w4LBody=transpose(R5)*w4L;    %compatibility with Jcm, etc.
                    Jac_wSwing=jacobian(w4LBody,dq);
                    dJac_wSwing=jacobian(Jac_wSwing*dq,q);
                case {'inertial'}
                    Jac_wStance=jacobian(w4R,dq);
                    dJac_wStance=jacobian(Jac_wStance*dq,q);
                    Jac_wSwing=jacobian(w4L,dq);
                    dJac_wSwing=jacobian(Jac_wSwing*dq,q);
            end
        case {'Stance_LeftLegZero'}
            switch WhichFrame
                case {'body'}
                    w4LBody=transpose(R5)*w4L;
                    Jac_wStance=jacobian(w4LBody,dq);
                    dJac_wStance=jacobian(Jac_wStance*dq,q);
                    w4RBody=transpose(R1)*w4R;
                    Jac_wSwing=jacobian(w4RBody,dq);
                    dJac_wSwing=jacobian(Jac_wSwing*dq,q);
                case {'inertial'}
                    Jac_wStance=jacobian(w4L,dq);
                    dJac_wStance=jacobian(Jac_wStance*dq,q);
                    Jac_wSwing=jacobian(w4R,dq);
                    dJac_wSwing=jacobian(Jac_wSwing*dq,q);
            end
    end
    %}
    
    %% Foot models
    %------------------------------------------------------------------------
    % Determine location of points on the nontrivial foot (Added by Kevin)
    %Foot geometry (in meters)
    %Coordinates of foot points in "body frame", or relative to a frame
    %attached to the ankle point, with z axis normal to base of foot and y
    %axis along the foot. p5 is the "left toe", p6 is the "right toe", p7 is the
    % "right heel", and p8 is the "left heel".
    % p9 was added by Kevin on 23JAN13, to denote a single toe point along
    % the centerline of the foot.
    %{
    foot_height=0;
    syms foot_length length_behind_heel heel_width toe_width
    syms y_dist_ankle_to_toe z_dist_ankle_to_toe
    
    p5 = [-toe_width/2; foot_length-length_behind_heel; -foot_height];
    p6 = [toe_width/2; foot_length-length_behind_heel; -foot_height];
    p7 = [heel_width/2; -length_behind_heel; -foot_height];
    p8 = [-heel_width/2; -length_behind_heel; -foot_height];
    p9 = [0; y_dist_ankle_to_toe; z_dist_ankle_to_toe];
    
    % Adjustment parameters for the right foot. We assume that any adjustment
    % about Z-axis or Y-axis is symmetric (i.e. mirror) for the left.
    syms footX footY footZ
    R_Foot2ShinR = Rz(footZ)*Ry(footY)*Rx(footX); %The rotation matrix that takes us from right foot frame to right shin frame
    R_Foot2ShinL = Rz(-footZ)*Ry(-footY)*Rx(footX); %The rotation matrix that takes us from left foot frame to left shin frame
    
    R1_flipped = R1*Rx(pi); %Rotate by pi around the x axis so that the z axis of R1 is positive up the leg. (More intuitive for applying the foot adjustment)
    R5_flipped = R5*Rx(pi); %Rotate by pi around the x axis so that the z axis of R5 is positive up the leg. (More intuitive for applying the foot adjustment)
    
    R_Foot2WorldR = R1_flipped*R_Foot2ShinR;
    R_Foot2WorldL = R5_flipped*R_Foot2ShinL;
    
    %Coordinates of foot points in world frame
    p5R = p4R + R_Foot2WorldR*p5;           p5R = simplify(p5R);
    p6R = p4R + R_Foot2WorldR*p6;           p6R = simplify(p6R);
    p7R = p4R + R_Foot2WorldR*p7;           p7R = simplify(p7R);
    p8R = p4R + R_Foot2WorldR*p8;           p8R = simplify(p8R);
    p9R = p4R + R_Foot2WorldR*p9;           p9R = simplify(p9R);
    p5L = p4L + R_Foot2WorldL*p5;           p5L = simplify(p5L);
    p6L = p4L + R_Foot2WorldL*p6;           p6L = simplify(p6L);
    p7L = p4L + R_Foot2WorldL*p7;           p7L = simplify(p7L);
    p8L = p4L + R_Foot2WorldL*p8;           p8L = simplify(p8L);
    p9L = p4L + R_Foot2WorldL*p9;           p9L = simplify(p9L);
    %}
    
    
    % BGB 2014
    %
    % A more flexible way to handle non-trivial feet is to consider an
    % arbitraty point rigidly attached to the end of the leg with relative
    % position pToeRel = [xToeRel; yToeRel; zToeRel] (expressed in the R1
    % frame). The position of this point in the world frame is then given
    % by
    %   pToeR = p4R + R1_flipped*pToeRel
    % and the Jacobian is given by
    %   jacobian(pToeR, q) = jacobian(p4R, q)
    %                        + jacobian(R1(:,1), q) * xToeRel
    %                        + jacobian(R1(:,2), q) * yToeRel
    %                        + jacobian(R1(:,3), q) * zToeRel
    
    R1Col = [R1(:,1); R1(:,2); R1(:,3)];
    R5Col = [R5(:,1); R5(:,2); R5(:,3)];
    
    J4R    = simplify(jacobian(p4R,q));
    J4L    = simplify(jacobian(p4L,q));
    JR1Col = simplify(jacobian(R1Col,q));
    JR5Col = simplify(jacobian(R5Col,q));
    
%     symbolicToMex('ShinRotationMatrices', inputs(q), outputs(R1, R5));
    symbolicToMex('FootPointPosJacob', inputs(q,extra_vars), outputs(p4R, R1, J4R, JR1Col, p4L, R5, J4L, JR5Col));
    
    toc, tic
    save(TempMatFile)
    
    %% Rotational kinetic energy
    disp('Step 3: Compute the rotational kinetic energy');
    
    disp('Step 3a: Compute the link rotational kinetic energy');
    RKET =  (1/2)*dot(w0',R0*IcmT*transpose(R0)*w0);     RKET = simplify(RKET);
    RKEHR = (1/2)*dot(wHR',R3*IcmH*transpose(R3)*wHR);   RKEHR = simplify(RKEHR);
    RKE1R = (1/2)*dot(w1R',R1*Icm1*transpose(R1)*w1R);   RKE1R = simplify(RKE1R);
    RKE2R = (1/2)*dot(w2R',R2*Icm2*transpose(R2)*w2R);   RKE2R = simplify(RKE2R);
    RKE3R = (1/2)*dot(w3R',R2*Icm3*transpose(R2)*w3R);   RKE3R = simplify(RKE3R);
    RKE4R = (1/2)*dot(w4R',R1*Icm4*transpose(R1)*w4R);   RKE4R = simplify(RKE4R);
    RKE5R = (1/2)*dot(wgr1R',R1gr1*Icm5*transpose(R1gr1)*wgr1R);   RKE5R = simplify(RKE5R);
    RKE6R = (1/2)*dot(wgr2R',R2gr2*Icm6*transpose(R2gr2)*wgr2R);   RKE6R = simplify(RKE6R);
    
    RKEHL = (1/2)*dot(wHL',R4*S*IcmH*S'*transpose(R4)*wHL);   RKEHL = simplify(RKEHL);
    RKE1L = (1/2)*dot(w1L',R5*S*Icm1*S'*transpose(R5)*w1L);   RKE1L = simplify(RKE1L);
    RKE2L = (1/2)*dot(w2L',R6*S*Icm2*S'*transpose(R6)*w2L);   RKE2L = simplify(RKE2L);
    RKE3L = (1/2)*dot(w3L',R6*S*Icm3*S'*transpose(R6)*w3L);   RKE3L = simplify(RKE3L);
    RKE4L = (1/2)*dot(w4L',R5*S*Icm4*S'*transpose(R5)*w4L);   RKE4L = simplify(RKE4L);
    RKE5L = (1/2)*dot(wgr1L',R5gr1*S*Icm5*S'*transpose(R5gr1)*wgr1L);   RKE5L = simplify(RKE5L);
    RKE6L = (1/2)*dot(wgr2L',R6gr2*S*Icm6*S'*transpose(R6gr2)*wgr2L);   RKE6L = simplify(RKE6L);
    
    
    RKE_Links =              RKET + RKEHR + RKEHL;
    RKE_Links = RKE_Links  + RKE1R + RKE2R + RKE3R + RKE4R + RKE5R + RKE6R;
    RKE_Links = RKE_Links  + RKE1L + RKE2L + RKE3L + RKE4L + RKE5L + RKE6L;
    
    RKE_Links = simplify(RKE_Links);
    
    
    disp('Step 3b: Compute motor and gear rotational kinetic energy');
    
    %Motors and Gear Reducers
    switch MotorModel
        case 1
            disp('    Using the complete motor model.')
            RKEm3R =  (1/2)*transpose(wm3R)*R3m3*Imot3*transpose(R3m3)*wm3R;      RKEm3R = simplify(RKEm3R);
            RKEgr3R = (1/2)*transpose(wgr3R)*R3gr3*Igr3*transpose(R3gr3)*wgr3R;   RKEgr3R = simplify(RKEgr3R);
            RKEm3L =  (1/2)*transpose(wm3L)*R4m3*Imot3*transpose(R4m3)*wm3L;      RKEm3L = simplify(RKEm3L);
            RKEgr3L = (1/2)*transpose(wgr3L)*R4gr3*Igr3*transpose(R4gr3)*wgr3L;   RKEgr3L = simplify(RKEgr3L);
            
            RKEm2R =  (1/2)*transpose(wm2R)*R2m2*Imot2*transpose(R2m2)*wm2R;      RKEm2R = simplify(RKEm2R);
            RKEgr2R = (1/2)*transpose(wgr2R)*R2gr2*Igr2*transpose(R2gr2)*wgr2R;   RKEgr2R = simplify(RKEgr2R);
            RKEm2L =  (1/2)*transpose(wm2L)*R6m2*Imot2*transpose(R6m2)*wm2L;      RKEm2L = simplify(RKEm2L);
            RKEgr2L = (1/2)*transpose(wgr2L)*R6gr2*Igr2*transpose(R6gr2)*wgr2L;   RKEgr2L = simplify(RKEgr2L);
            
            RKEm1R =  (1/2)*transpose(wm1R)*R1m1*Imot1*transpose(R1m1)*wm1R;      RKEm1R = simplify(RKEm1R);
            RKEgr1R = (1/2)*transpose(wgr1R)*R1gr1*Igr1*transpose(R1gr1)*wgr1R;   RKEgr1R = simplify(RKEgr1R);
            RKEm1L =  (1/2)*transpose(wm1L)*R5m1*Imot1*transpose(R5m1)*wm1L;      RKEm1L = simplify(RKEm1L);
            RKEgr1L = (1/2)*transpose(wgr1L)*R5gr1*Igr1*transpose(R5gr1)*wgr1L;   RKEgr1L = simplify(RKEgr1L);
            
            RKE_MotorsGears =                   RKEm3R + RKEgr3R + RKEm3L + RKEgr3L;
            RKE_MotorsGears = RKE_MotorsGears + RKEm2R + RKEgr2R + RKEm2L + RKEgr2L;
            RKE_MotorsGears = RKE_MotorsGears + RKEm1R + RKEgr1R + RKEm1L + RKEgr1L;
            
            RKE_MotorsGears = simplify(RKE_MotorsGears);
            
        case 2
            disp('    Using Spong''s simplified motor model.')
            RKEm3R =  (1/2)*dqm3R*Jrotor3*dqm3R;
            RKEgr3R = (1/2)*dqgr3R*Jgear3*dqgr3R;
            RKEm3L =  (1/2)*dqm3L*Jrotor3*dqm3L;
            RKEgr3L = (1/2)*dqgr3L*Jgear3*dqgr3L;
            
            RKEm2R =  (1/2)*dqm2R*Jrotor2*dqm2R;
            RKEgr2R = (1/2)*dqgr2R*Jgear2*dqgr2R;
            RKEm2L =  (1/2)*dqm2L*Jrotor2*dqm2L;
            RKEgr2L = (1/2)*dqgr2L*Jgear2*dqgr2L;
            
            RKEm1R =  (1/2)*dqm1R*Jrotor1*dqm1R;
            RKEgr1R = (1/2)*dqgr1R*Jgear1*dqgr1R;
            RKEm1L =  (1/2)*dqm1L*Jrotor1*dqm1L;
            RKEgr1L = (1/2)*dqgr1L*Jgear1*dqgr1L;
            
            RKE_MotorsGears =                   RKEm3R + RKEgr3R + RKEm3L + RKEgr3L;
            RKE_MotorsGears = RKE_MotorsGears + RKEm2R + RKEgr2R + RKEm2L + RKEgr2L;
            RKE_MotorsGears = RKE_MotorsGears + RKEm1R + RKEgr1R + RKEm1L + RKEgr1L;
            
            RKE_MotorsGears = simplify(RKE_MotorsGears);
        otherwise
            disp('    No motor model (rotor rotation does not contribute to kinetic energy).')
            RKE_MotorsGears=0;
    end
    
    %RKE Total
    RKE=RKE_Links + RKE_MotorsGears; RKE=simple(RKE);
    
    toc, tic
    save(TempMatFile)
    
    
    %% Translational kinetic energy
    disp('Step 4: Compute the translational kinetic energy');
    
    TKET = (1/2)*mT*(dot(vcmT',vcmT));      TKET = simplify(TKET);
    
    TKEHR = (1/2)*mH*(dot(vcmHR',vcmHR));   TKEHR = simplify(TKEHR);
    TKE1R = (1/2)*m1*(dot(vcm1R',vcm1R));   TKE1R = simplify(TKE1R);
    TKE2R = (1/2)*m2*(dot(vcm2R',vcm2R));   TKE2R = simplify(TKE2R);
    TKE3R = (1/2)*m3*(dot(vcm3R',vcm3R));   TKE3R = simplify(TKE3R);
    TKE4R = (1/2)*m4*(dot(vcm4R',vcm4R));   TKE4R = simplify(TKE4R);
    TKE5R = (1/2)*m5*(dot(vcm5R',vcm5R));   TKE5R = simplify(TKE5R);
    TKE6R = (1/2)*m6*(dot(vcm6R',vcm6R));   TKE6R = simplify(TKE6R);
    
    TKEHL = (1/2)*mH*(dot(vcmHL',vcmHL));   TKEHL = simplify(TKEHL);
    TKE1L = (1/2)*m1*(dot(vcm1L',vcm1L));   TKE1L = simplify(TKE1L);
    TKE2L = (1/2)*m2*(dot(vcm2L',vcm2L));   TKE2L = simplify(TKE2L);
    TKE3L = (1/2)*m3*(dot(vcm3L',vcm3L));   TKE3L = simplify(TKE3L);
    TKE4L = (1/2)*m4*(dot(vcm4L',vcm4L));   TKE4L = simplify(TKE4L);
    TKE5L = (1/2)*m5*(dot(vcm5L',vcm5L));   TKE5L = simplify(TKE5L);
    TKE6L = (1/2)*m6*(dot(vcm6L',vcm6L));   TKE6L = simplify(TKE6L);
    
    TKE = TKET + TKEHR + TKEHL;
    TKE = TKE  + TKE1R + TKE2R + TKE3R + TKE4R + TKE5R + TKE6R;
    TKE = TKE  + TKE1L + TKE2L + TKE3L + TKE4L + TKE5L + TKE6L;
    
    TKE = simplify(TKE);
    
    KE = RKE + TKE;
    
    toc, tic
    save(TempMatFile)
    
    %% Potential energy
    disp('Step 5: Compute the potential energy');
    PE = Mtotal*g*pcm(3);
    
    %% Lagrange model
    
    % B: Input matrix
    toc,tic
    disp('Step 6: Compute the input matrix B');
    
    qa = [qm1R; qm2R; qm3R; qm1L; qm2L; qm3L];
    B  = jacobian(qa, q);
    B  = B.'
    
    % G: Gravity vector
    disp('Step 7: Compute the gravity vector G');
    G = jacobian(PE,q).';
    
    disp( 'G = ' );
    for i=1:length(q)
        G(i)=simplify(G(i));
        disp(['G(',num2str(i),')= ',char(G(i))])
    end
    
    toc, tic
    save(TempMatFile)
    
    % D: Inertia matrix
    disp('Step 8: Compute the inertia matrix D');
    
    Jac_KE_dq = jacobian(KE,dq);
    D = jacobian(Jac_KE_dq,dq);
    
    disp( 'D = ' );
    for i=1:length(q)
        for j=i:length(q)
            D(i,j)=simplify(D(i,j));
            D(j,i)=D(i,j);
            disp(['D(',num2str(i),',',num2str(j),')= ',char(D(i,j))])
        end
    end
    toc, tic
    save(TempMatFile)
    
    % C: Coriolis and centrifugal terms
    switch Model
        case {'StanceRightImpactLeft','StanceLeftImpactRight'}
            disp('Step 9: Generate impact model matrices D, E');
            symbolicToMex('Impact_withYawConstraint', inputs(q), outputs(D, E1));
            symbolicToMex('Impact', inputs(q), outputs(D, E2));
            
        otherwise
            if 0
                disp('Step 9: Compute the vector Cdq of Coriolis and centrifugal terms');
                for k=1:length(q)
                    for j=1:length(q)
                        C(k,j)=0;
                        for i=1:length(q)
                            C(k,j)=C(k,j)+(1/2)*(diff(D(k,j),q(i))+diff(D(k,i),q(j))-diff(D(i,j),q(k)))*dq(i);
                        end
                    end
                end
                % Simplify C and display it
                for i=1:length(q)
                    for j=1:length(q)
                        C(i,j)=simplify(C(i,j));
                        disp(['C(',num2str(i),',',num2str(j),')= ',char(C(i,j))])
                    end
                end
            else
                disp('Step 9: Compute the vector Cdq of Coriolis and centrifugal terms');
                CC=jacobian(KE,dq).';
                CC=jacobian(CC,q)-(1/2)*jacobian(D*dq,q).';
                CC=simplify(CC);
                Cdq=CC*dq;
                disp('Cdq computed; now simplify and display it.')
                toc, tic
                save(TempMatFile)
                for i=1:length(q)
                    Cdq(i)=simplify(Cdq(i));
                    disp(['Cdq(',num2str(i),')= ',char(Cdq(i))])
                end
                
            end
            toc, tic
            save(TempMatFile)
            
            
            disp('Step 10: Generate Lagrange model terms D, Cdq, G, B');
            symbolicToMex('Lagrange', inputs(q, dq, extra_vars), outputs(D, Cdq, G, B));
            symbolicToMex('D', inputs(q, extra_vars), outputs(D));
            symbolicToMex('Cdq', inputs(q, dq, extra_vars), outputs(Cdq));
            symbolicToMex('G', inputs(q, extra_vars), outputs(G));
            symbolicToMex('B', inputs(q), outputs(B));
    end
    
    save(TempMatFile)
    toc
    fprintf('%s model generation complete.\n', Model);
    
end


