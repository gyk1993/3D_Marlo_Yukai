%% Script to initialize the Gait Library Bus

MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary\mat\GaitLibrary_v5\';

% Build up 2D Walking Library
WalkInPlace = load([MAT_PATH,'ControlParams_2step_0x_0y_00gH_v5']);
Walking.ControlParams_RightStance = WalkInPlace.ControlParams1;
Walking.ControlParams_LeftStance = WalkInPlace.ControlParams2;

Walking.SetY = [-1.0, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1.0];
Walking.SetX = [-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5];
dy_set = [-1.0, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1.0];
dx_set = [-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5];

WalkingLibrary = cell(numel(dy_set), numel(dx_set));
Walking.ControlParams_RightStance.Output.HAlpha = zeros(numel(dy_set),numel(dx_set),6,6);
Walking.ControlParams_RightStance.Output.HAlpha_q = zeros(numel(dy_set),numel(dx_set),13,6);
Walking.ControlParams_RightStance.Output.HAlpha_dq = zeros(numel(dy_set),numel(dx_set),13,6);
Walking.ControlParams_RightStance.Output.HAlpha_vcm= zeros(numel(dy_set),numel(dx_set),2,6);
Walking.ControlParams_LeftStance.Output.HAlpha = zeros(numel(dy_set),numel(dx_set),6,6);
Walking.ControlParams_LeftStance.Output.HAlpha_q = zeros(numel(dy_set),numel(dx_set),13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_dq = zeros(numel(dy_set),numel(dx_set),13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_vcm = zeros(numel(dy_set),numel(dx_set),2,6);

for i = 1:numel(dy_set)
    for j = 1:numel(dx_set)
        
        speed_y = dy_set(i);
        speed_x = dx_set(j);

        controlFile = sprintf('ControlParams_2step_%dx_%dy_00gH_v5', speed_x*10,speed_y*10);
        WalkingLibrary{i,j} = load([MAT_PATH,controlFile]);        
        
        % Increase stance knee angle
        if isSim
            stanceKneeAdjustment = 0;
            swingKneeAdjustment = 0; % Experiments need larger increase
        else 
            stanceKneeAdjustment = 0; % Experiments need larger increase
            swingKneeAdjustment = 0; % Experiments need larger increase
        end
        
        % Decrease stance knee angle
        WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([4,5,8,9],:) = ...
            WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([4,5,8,9],:)...
            + repmat([deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment);deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment)],1,6);
        
        WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([6,7,11,12],:) = ...
            WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([6,7,11,12],:)...
            + repmat([deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment);deg2rad(stanceKneeAdjustment);-deg2rad(stanceKneeAdjustment)],1,6);
        
        % Increase swing knee angle at the middle of the step
        WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([6,7,11,12],2:5) = ...
            WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([6,7,11,12],2:5)...
            + repmat([-deg2rad(swingKneeAdjustment);deg2rad(swingKneeAdjustment);-deg2rad(swingKneeAdjustment);deg2rad(stanceKneeAdjustment)],1,4);
        
        WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([4,5,8,9],2:5) = ...
            WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([4,5,8,9],2:5)...
            + repmat([-deg2rad(swingKneeAdjustment);deg2rad(swingKneeAdjustment);-deg2rad(swingKneeAdjustment);deg2rad(stanceKneeAdjustment)],1,4);
        
        % OVERWRITE TO MAKE HIPS MOVE AS A SINUSOID
        if isTest_hipTracking
            WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q([10,13],1:6) = deg2rad([0,0,-10,-10,0,0; 0,0,-10,-10,0,0]);
            WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q([10,13],1:6) = deg2rad([0,0,-10,-10,0,0; 0,0,-10,-10,0,0]);
        end
        
%         % Zero out vcm bezier
%         WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_vcm = zeros(2,6);
%         WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_vcm = zeros(2,6);

        Walking.ControlParams_RightStance.Output.HAlpha(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha;
        Walking.ControlParams_RightStance.Output.HAlpha_q(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_q;
        Walking.ControlParams_RightStance.Output.HAlpha_dq(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_dq;
        Walking.ControlParams_RightStance.Output.HAlpha_vcm(i,j,:,:) = WalkingLibrary{i,j}.ControlParams1.Output.HAlpha_vcm;% - 1*repmat([speed_x; speed_y],1,6);
        
        
        Walking.ControlParams_LeftStance.Output.HAlpha(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha;
        Walking.ControlParams_LeftStance.Output.HAlpha_q(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_q;
        Walking.ControlParams_LeftStance.Output.HAlpha_dq(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_dq;
        Walking.ControlParams_LeftStance.Output.HAlpha_vcm(i,j,:,:) = WalkingLibrary{i,j}.ControlParams2.Output.HAlpha_vcm;% - 1*repmat([speed_x; speed_y],1,6);
        

    end
end

% % Overwrite walking in place controller
% MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary\mat\';
% controlFile = sprintf('ControlParams_2step_%dx_%dy_00gH_v4', 0*10,0*10);
% NewWIP = load([MAT_PATH,controlFile]);
% % Increase stance knee angle
% ski = 2;
% NewWIP.ControlParams1.Output.HAlpha_q([4,5,8,9],:) = NewWIP.ControlParams1.Output.HAlpha_q([4,5,8,9],:)...
%                                     + repmat([deg2rad(ski);-deg2rad(ski);deg2rad(ski);-deg2rad(ski)],1,6);
% NewWIP.ControlParams2.Output.HAlpha_q([6,7,11,12],:) = NewWIP.ControlParams2.Output.HAlpha_q([6,7,11,12],:)...
%                                     + repmat([deg2rad(ski);-deg2rad(ski);deg2rad(ski);-deg2rad(ski)],1,6);
%                                 
% NewWIP.ControlParams1.Output.HAlpha_vcm = zeros(2,6);
% NewWIP.ControlParams2.Output.HAlpha_vcm = zeros(2,6);
% for i = 1:numel(dy_set)
%     for j = 1:numel(dx_set)
%         Walking.ControlParams_RightStance.Output.HAlpha(i,j,:,:) = NewWIP.ControlParams1.Output.HAlpha;
%         Walking.ControlParams_RightStance.Output.HAlpha_q(i,j,:,:) = NewWIP.ControlParams1.Output.HAlpha_q;
%         Walking.ControlParams_RightStance.Output.HAlpha_dq(i,j,:,:) = NewWIP.ControlParams1.Output.HAlpha_dq;
%         Walking.ControlParams_RightStance.Output.HAlpha_vcm(i,j,:,:) = NewWIP.ControlParams1.Output.HAlpha_vcm;
% 
%         Walking.ControlParams_LeftStance.Output.HAlpha(i,j,:,:) = NewWIP.ControlParams2.Output.HAlpha;
%         Walking.ControlParams_LeftStance.Output.HAlpha_q(i,j,:,:) = NewWIP.ControlParams2.Output.HAlpha_q;
%         Walking.ControlParams_LeftStance.Output.HAlpha_dq(i,j,:,:) = NewWIP.ControlParams2.Output.HAlpha_dq;
%         Walking.ControlParams_LeftStance.Output.HAlpha_vcm(i,j,:,:) = NewWIP.ControlParams2.Output.HAlpha_vcm;
%     end
% end

% Side Stepping Gaits
MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary\mat\';
sideStepLeft = load([MAT_PATH, 'ControlParams_2step_25sideStep_v2.mat']);
SideSteppingLeft.ControlParams_RightStance = sideStepLeft.ControlParams1;
SideSteppingLeft.ControlParams_LeftStance = sideStepLeft.ControlParams2;
% Modify sidestepping gait
% SideSteppingLeft.ControlParams_RightStance.Output.HAlpha(6,3:6) = ...
%     SideSteppingLeft.ControlParams_RightStance.Output.HAlpha(6,3:6) + repmat(deg2rad(0),1,4);% Modify foot clearance
SideSteppingLeft.ControlParams_RightStance.Output.HAlpha(4,3:6) = ...
    SideSteppingLeft.ControlParams_RightStance.Output.HAlpha(4,3:6) + linspace(deg2rad(5),deg2rad(5),4);% Modify foot clearance
SideSteppingLeft.ControlParams_LeftStance.Output.HAlpha(4,1:6) = ...
    SideSteppingLeft.ControlParams_LeftStance.Output.HAlpha(4,1:6) + linspace(deg2rad(5),0,6);% Modify foot clearance

% Kicking
MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary\mat\';
kickingLeft = load([MAT_PATH, 'ControlParams_2step_25kicking_v2.mat']);
KickingLeft.ControlParams_RightStance = kickingLeft.ControlParams1;
KickingLeft.ControlParams_RightStance.Output.HAlpha(4,3:5) = ...
    KickingLeft.ControlParams_RightStance.Output.HAlpha(4,3:5) + repmat(deg2rad(10),1,3);% Modify foot clearance
KickingLeft.ControlParams_LeftStance = kickingLeft.ControlParams2;

% Store
Collections.Walking = Walking;
Collections.SideSteppingLeft = SideSteppingLeft;
Collections.KickingLeft = KickingLeft;

GaitLibrary.Collections = Collections;
GaitLibrary.Model = double('OriginalLeg-yy/mm/dd');

ControlParams.RightStance = SideSteppingLeft.ControlParams_RightStance;
ControlParams.LeftStance = SideSteppingLeft.ControlParams_LeftStance;
createBusObject(ControlParams, 'ControlParams_bus');

createBusObject(GaitLibrary, 'GaitLibrary_bus');