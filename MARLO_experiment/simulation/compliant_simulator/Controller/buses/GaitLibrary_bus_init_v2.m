%% Script to initialize the Gait Library Bus

MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary_Variable-COM-LegLength\mat\GaitLibrary_v5\';

% Build up 2D Walking Library
WalkInPlace = load([MAT_PATH,'ControlParams_2step_0x_0y_00gH']);
Walking.ControlParams_RightStance = WalkInPlace.ControlParams1;
Walking.ControlParams_LeftStance = WalkInPlace.ControlParams2;

Walking.SetY = [-1.0,-0.8,-0.6,-0.4,-0.2,0.0,0.2,0.4,0.6,0.8,1.0];
Walking.SetX = [-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4,0.5];
% Walking.SetY = [0.0,0.0,0.0];
% Walking.SetX = [0.0,0.0,0.0];
N = numel(Walking.SetY);
M = numel(Walking.SetX);

WalkingLibrary = cell(N,M);
opt = cell(N,M);
Walking.ControlParams_RightStance.Output.HAlpha = zeros(N,M,6,6);
Walking.ControlParams_RightStance.Output.HAlpha_q = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_dq = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_vcm = zeros(N,M,2,6);
Walking.ControlParams_RightStance.Output.HAlpha_u = zeros(N,M,6,6);
Walking.ControlParams_RightStance.Output.HAlpha_sigma = zeros(N,M,3,6);

Walking.ControlParams_LeftStance.Output.HAlpha = zeros(N,M,6,6);
Walking.ControlParams_LeftStance.Output.HAlpha_q = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_dq = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_vcm = zeros(N,M,2,6);
Walking.ControlParams_LeftStance.Output.HAlpha_u = zeros(N,M,6,6);
Walking.ControlParams_LeftStance.Output.HAlpha_sigma = zeros(N,M,3,6);

for i = 1:numel(Walking.SetY)
    for j = 1:numel(Walking.SetX)
        
        speed_y = Walking.SetY(i);
        speed_x = Walking.SetX(j);

        controlFile = sprintf('ControlParams_2step_%dx_%dy_00gH', speed_x*10,speed_y*10);
        WalkingLibrary{i,j} = load([MAT_PATH,controlFile]); 
        optFile = sprintf('2step_%dx_%dy_00_gH', speed_x*10,speed_y*10);
        opt{i,j} = load([MAT_PATH,optFile]); 
        
        % Increase stance knee angle
        if isSim
            stanceKneeAdjustment = 0;
            swingKneeAdjustment = 0; % Experiments need larger increase
        else 
            stanceKneeAdjustment = 0; % Experiments need larger increase
            swingKneeAdjustment = 0; % Experiments need larger increase
        end
        
        % Decrease stance knee angle
        WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([4,5,8,9]+3,:) = ...
            WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([4,5,8,9]+3,:)...
            + repmat([deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment);deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment)],1,6);
        
        WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([6,7,11,12]+3,:) = ...
            WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([6,7,11,12]+3,:)...
            + repmat([deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment);deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment)],1,6);
        
        % Increase swing knee angle at the middle of the step
        WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([6,7,11,12]+3,2:5) = ...
            WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([6,7,11,12]+3,2:5)...
            + repmat([-deg2rad(swingKneeAdjustment);deg2rad(swingKneeAdjustment);-deg2rad(swingKneeAdjustment);deg2rad(stanceKneeAdjustment)],1,4);
        
        WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([4,5,8,9]+3,2:5) = ...
            WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([4,5,8,9]+3,2:5)...
            + repmat([-deg2rad(swingKneeAdjustment);deg2rad(swingKneeAdjustment);-deg2rad(swingKneeAdjustment);deg2rad(stanceKneeAdjustment)],1,4);
        
        
        % Overwrite vcm bezier
        WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_vcm = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_dq(1:2,:);
        WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_vcm = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_dq(1:2,:);

        Walking.ControlParams_RightStance.Output.HAlpha(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha;
        Walking.ControlParams_RightStance.Output.HAlpha_q(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q(4:end,:);
        Walking.ControlParams_RightStance.Output.HAlpha_dq(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_dq(4:end,:);
        Walking.ControlParams_RightStance.Output.HAlpha_vcm(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_vcm;% - 1*repmat([speed_x; speed_y],1,6);
        Walking.ControlParams_RightStance.Output.HAlpha_u(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_u;

        % Compute sigma_desired right stance
        NumNodes = 29;
        s = zeros(1,NumNodes);
        sigma = zeros(3,NumNodes);
        for k = 1:NumNodes
            s(k) = k/NumNodes;
            q = opt{i,j}.outputs{1}.q(k,:)';
            dq = opt{i,j}.outputs{1}.dq(k,:)';
            [sig, sig_dot] = OriginalLeg_Springs_VariableLeg_COMoffset.ATRIAS3D_Sigma_Right([0;q(5:end)], dq(4:end), [leg_length;torso_com_offset]);
            sigma(:,k) =  sig;
        end
        Walking.ControlParams_RightStance.Output.HAlpha_sigma(i,j,:,:) = bezfit(s,sigma,5);
        
        Walking.ControlParams_LeftStance.Output.HAlpha(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha;
        Walking.ControlParams_LeftStance.Output.HAlpha_q(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q(4:end,:);
        Walking.ControlParams_LeftStance.Output.HAlpha_dq(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_dq(4:end,:);
        Walking.ControlParams_LeftStance.Output.HAlpha_vcm(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_vcm;% - 1*repmat([speed_x; speed_y],1,6);
        Walking.ControlParams_LeftStance.Output.HAlpha_u(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_u;
        
        % Compute sigma_desired left stance
        NumNodes = 29;
        s = zeros(1,NumNodes);
        sigma = zeros(3,NumNodes);
        for k = 1:NumNodes
            s(k) = k/NumNodes;
            q = opt{i,j}.outputs{2}.q(k,:)';
            dq = opt{i,j}.outputs{2}.dq(k,:)';
            [sig, sig_dot] = OriginalLeg_Springs_VariableLeg_COMoffset.ATRIAS3D_Sigma_Left([0;q(5:end)], dq(4:end), [leg_length;torso_com_offset]);
            sigma(:,k) =  sig;
        end
        Walking.ControlParams_RightStance.Output.HAlpha_sigma(i,j,:,:) = bezfit(s,sigma,5);
        
    end
end
% % Overwrite to trick interpolation (HACK)
% Walking.SetY = [-0.1,0.0,0.1];
% Walking.SetX = [-0.1,0.0,0.1];

% Side Stepping Gaits
MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary_Variable-COM-LegLength\mat\GaitLibrary_v1\';
sideStepLeft = load([MAT_PATH,'ControlParams_2step_0x_0y_00gH']);
SideSteppingLeft.ControlParams_RightStance = sideStepLeft.ControlParams1;
SideSteppingLeft.ControlParams_RightStance.Output.HAlpha_q(1:3,:) = [];
SideSteppingLeft.ControlParams_RightStance.Output.HAlpha_dq(1:3,:) = [];
SideSteppingLeft.ControlParams_LeftStance = sideStepLeft.ControlParams2;
SideSteppingLeft.ControlParams_LeftStance.Output.HAlpha_q(1:3,:) = [];
SideSteppingLeft.ControlParams_LeftStance.Output.HAlpha_dq(1:3,:) = [];

% Kicking
MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary_Variable-COM-LegLength\mat\GaitLibrary_v1\';
kickingLeft = load([MAT_PATH,'ControlParams_2step_0x_0y_00gH']);
KickingLeft.ControlParams_RightStance = kickingLeft.ControlParams1;
KickingLeft.ControlParams_RightStance.Output.HAlpha_q(1:3,:) = [];
KickingLeft.ControlParams_RightStance.Output.HAlpha_dq(1:3,:) = [];
KickingLeft.ControlParams_LeftStance = kickingLeft.ControlParams2;
KickingLeft.ControlParams_LeftStance.Output.HAlpha_q(1:3,:) = [];
KickingLeft.ControlParams_LeftStance.Output.HAlpha_dq(1:3,:) = [];

% Store
Collections.Walking = Walking;
Collections.SideSteppingLeft = SideSteppingLeft;
Collections.KickingLeft = KickingLeft;

GaitLibrary.Collections = Collections;
GaitLibrary.Model = double('OriginalLeg-yy/mm/dd');

ControlParams.RightStance = SideSteppingLeft.ControlParams_RightStance;
ControlParams.RightStance.Output.HAlpha_sigma = zeros(3,6);
ControlParams.LeftStance = SideSteppingLeft.ControlParams_LeftStance;
ControlParams.LeftStance.Output.HAlpha_sigma = zeros(3,6);
createBusObject(ControlParams, 'ControlParams_bus');

createBusObject(GaitLibrary, 'GaitLibrary_bus');