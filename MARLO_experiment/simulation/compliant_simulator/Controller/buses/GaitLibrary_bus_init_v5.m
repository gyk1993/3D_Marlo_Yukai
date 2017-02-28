
MAT_PATH = 'C:\Users\Ross\Documents\SVN\MARLO_Optimizations\GaitLibrary_Variable-COM-LegLength\mat\GaitLibrary_v5\';

% Build up 2D Walking Library
% WalkInPlace = load([MAT_PATH,'ControlParams_2step_0dx_0dy']);
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
Walking.ControlParams_RightStance.Output.HAlpha = zeros(N,M,6,6);
Walking.ControlParams_RightStance.Output.HAlpha_q_curr = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_dq_curr = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_q_tgt = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_dq_tgt = zeros(N,M,13,6);
Walking.ControlParams_RightStance.Output.HAlpha_vActual = zeros(N,M,2,6);
Walking.ControlParams_RightStance.Output.HAlpha_vFiltered = zeros(N,M,2,6);
Walking.ControlParams_RightStance.Output.HAlpha_u = zeros(N,M,6,6);
Walking.ControlParams_RightStance.Output = rmfield(Walking.ControlParams_RightStance.Output, 'HAlpha_q');
Walking.ControlParams_RightStance.Output = rmfield(Walking.ControlParams_RightStance.Output, 'HAlpha_dq');

Walking.ControlParams_LeftStance.Output.HAlpha = zeros(N,M,6,6);
Walking.ControlParams_LeftStance.Output.HAlpha_q_curr = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_dq_curr = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_q_tgt = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_dq_tgt = zeros(N,M,13,6);
Walking.ControlParams_LeftStance.Output.HAlpha_vActual = zeros(N,M,2,6);
Walking.ControlParams_LeftStance.Output.HAlpha_vFiltered = zeros(N,M,2,6);
Walking.ControlParams_LeftStance.Output.HAlpha_u = zeros(N,M,6,6);
Walking.ControlParams_LeftStance.Output = rmfield(Walking.ControlParams_LeftStance.Output, 'HAlpha_q');
Walking.ControlParams_LeftStance.Output = rmfield(Walking.ControlParams_LeftStance.Output, 'HAlpha_dq');

for i = 1:numel(Walking.SetY)
    for j = 1:numel(Walking.SetX)
        
        speed_y = Walking.SetY(i);
        speed_x = Walking.SetX(j);

        MAT_PATH = 'C:\Users\Ross\Documents\GIT\RobotOptimization\Examples\atrias\mat\';
        optimization = load([MAT_PATH,'walkingInPlace_v1']);   
%         controlFile = sprintf('ControlParams_2step_%ddx_%ddy', speed_x*10,speed_y*10);
%         controlFile = sprintf('ControlParams_2step_%dx_%dy_00gH', speed_x*10,speed_y*10);

        HAlpha_q_RightStance_new = bezfit(linspace(0,1,29), optimization.outputs{1}.q', 5);
        HAlpha_q_RightStance = zeros(13,6);
        HAlpha_q_RightStance(1:3,:) = HAlpha_q_RightStance_new([5,4,6],:);
        HAlpha_q_RightStance(4:13,:) = HAlpha_q_RightStance_new([8,9,13,14,8,9,7,13,14,12],:);
        HAlpha_q_RightStance(13,:) = -HAlpha_q_RightStance(13,:);
       
        HAlpha_dq_RightStance_new = bezfit(linspace(0,1,29), optimization.outputs{1}.dq', 5);
        HAlpha_dq_RightStance = zeros(13,6);
        HAlpha_dq_RightStance(1:3,:) = HAlpha_dq_RightStance_new([5,4,6],:);
        HAlpha_dq_RightStance(4:13,:) = HAlpha_dq_RightStance_new([8,9,13,14,8,9,7,13,14,12],:);
        HAlpha_dq_RightStance(13,:) = -HAlpha_dq_RightStance(13,:);        
        
        HAlpha_q_LeftStance_new = bezfit(linspace(0,1,29), optimization.outputs{2}.q', 5);
        HAlpha_q_LeftStance = zeros(13,6);
        HAlpha_q_LeftStance(1:3,:) = HAlpha_q_LeftStance_new([5,4,6],:);
        HAlpha_q_LeftStance(4:13,:) = HAlpha_q_LeftStance_new([8,9,13,14,8,9,7,13,14,12],:);
        HAlpha_q_LeftStance(13,:) = -HAlpha_q_LeftStance(13,:);
        
        HAlpha_dq_LeftStance_new = bezfit(linspace(0,1,29), optimization.outputs{2}.dq', 5);
        HAlpha_dq_LeftStance = zeros(13,6);
        HAlpha_dq_LeftStance(1:3,:) = HAlpha_dq_LeftStance_new([5,4,6],:);
        HAlpha_dq_LeftStance(4:13,:) = HAlpha_dq_LeftStance_new([8,9,13,14,8,9,7,13,14,12],:);
        HAlpha_dq_LeftStance(13,:) = -HAlpha_dq_LeftStance(13,:);
        
        WalkingLibrary{i,j}.ControlParams_RightStance = WalkInPlace.ControlParams1;        
        WalkingLibrary{i,j}.ControlParams_LeftStance = WalkInPlace.ControlParams2;       

        Walking.ControlParams_RightStance.Output.HAlpha(i,j,:,:) = zeros(6,6);
        Walking.ControlParams_RightStance.Output.HAlpha_q_curr(i,j,:,:) = HAlpha_q_RightStance;
        Walking.ControlParams_RightStance.Output.HAlpha_dq_curr(i,j,:,:) = HAlpha_dq_RightStance;
        Walking.ControlParams_RightStance.Output.HAlpha_q_tgt(i,j,:,:) = HAlpha_q_RightStance;
        Walking.ControlParams_RightStance.Output.HAlpha_dq_tgt(i,j,:,:) = HAlpha_dq_RightStance;
        Walking.ControlParams_RightStance.Output.HAlpha_vActual(i,j,:,:) = zeros(2,6);
        Walking.ControlParams_RightStance.Output.HAlpha_vFiltered(i,j,:,:) = zeros(2,6);
        Walking.ControlParams_RightStance.Output.HAlpha_u(i,j,:,:) = zeros(6,6);

        Walking.ControlParams_LeftStance.Output.HAlpha(i,j,:,:) = zeros(6,6);
        Walking.ControlParams_LeftStance.Output.HAlpha_q_curr(i,j,:,:) = HAlpha_q_LeftStance;
        Walking.ControlParams_LeftStance.Output.HAlpha_dq_curr(i,j,:,:) = HAlpha_dq_LeftStance;
        Walking.ControlParams_LeftStance.Output.HAlpha_q_tgt(i,j,:,:) = HAlpha_q_LeftStance;
        Walking.ControlParams_LeftStance.Output.HAlpha_dq_tgt(i,j,:,:) = HAlpha_dq_LeftStance;
        Walking.ControlParams_LeftStance.Output.HAlpha_vActual(i,j,:,:) = zeros(2,6);
        Walking.ControlParams_LeftStance.Output.HAlpha_vFiltered(i,j,:,:) = zeros(2,6);
        Walking.ControlParams_LeftStance.Output.HAlpha_u(i,j,:,:) = zeros(6,6);
    end
end
% % Overwrite to trick interpolation (HACK)
% Walking.SetY = [-0.1,0.0,0.1];
% Walking.SetX = [-0.1,0.0,0.1];


% Store
Collections.Walking = Walking;

GaitLibrary.Collections = Collections;
GaitLibrary.Model = double('OriginalLeg-yy/mm/dd');

tmp1 = WalkInPlace.ControlParams1;
tmp1.Output.HAlpha_vActual = zeros(2,6);
tmp1.Output.HAlpha_vFiltered = zeros(2,6);
tmp1.Output = rmfield(tmp1.Output, 'HAlpha_u');
tmp1.Output.HAlpha_u = zeros(6,6);
tmp1.Output.HAlpha_q_curr = tmp1.Output.HAlpha_q(4:end,:);
tmp1.Output.HAlpha_q_curr = tmp1.Output.HAlpha_q(4:end,:);
tmp1.Output.HAlpha_dq_curr = tmp1.Output.HAlpha_dq(4:end,:);
tmp1.Output.HAlpha_q_tgt = tmp1.Output.HAlpha_q(4:end,:);
tmp1.Output.HAlpha_dq_tgt = tmp1.Output.HAlpha_dq(4:end,:);
tmp1.Output = rmfield(tmp1.Output, 'HAlpha_q');
tmp1.Output = rmfield(tmp1.Output, 'HAlpha_dq');
tmp1.Output = rmfield(tmp1.Output, 'HAlpha_vcm');

tmp2 = WalkInPlace.ControlParams2;
tmp2.Output.HAlpha_vActual = zeros(2,6);
tmp2.Output.HAlpha_vFiltered = zeros(2,6);
tmp2.Output = rmfield(tmp2.Output, 'HAlpha_u');
tmp2.Output.HAlpha_u = zeros(6,6);
tmp2.Output.HAlpha_q_curr = tmp2.Output.HAlpha_q(4:end,:);
tmp2.Output.HAlpha_dq_curr = tmp2.Output.HAlpha_dq(4:end,:);
tmp2.Output.HAlpha_q_tgt = tmp2.Output.HAlpha_q(4:end,:);
tmp2.Output.HAlpha_dq_tgt = tmp2.Output.HAlpha_dq(4:end,:);
tmp2.Output = rmfield(tmp2.Output, 'HAlpha_q');
tmp2.Output = rmfield(tmp2.Output, 'HAlpha_dq');
tmp2.Output = rmfield(tmp2.Output, 'HAlpha_vcm');

ControlParams.RightStance = tmp1;
ControlParams.LeftStance = tmp2;
createBusObject(ControlParams, 'ControlParams_bus');

createBusObject(GaitLibrary, 'GaitLibrary_bus');