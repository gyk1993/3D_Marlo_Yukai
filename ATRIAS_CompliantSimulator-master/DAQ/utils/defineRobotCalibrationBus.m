function defineRobotCalibrationBus()
    %% Define Bus Objects
    v = ver('MATLAB');
    vnum = str2double(v.Version);
    
    if (vnum<=7.12)
        formatCell = @(C) {C(:,[1:4 6])};
    else
        formatCell = @(C) {C};
    end
    
    %% Calibration Parameters Structure
    % Calibration =
    %    AbsCalTick: [10x1 double]
    %    BoomCalTick: [3x1 double]
    %    AbsCalConst: [10x1 double]
    %    AbsCalAngle: [10x1 double]
    %    AbsMaxTick: [10x1 double]
    %    IncCalConst: [6x1 double]
    %    IncMaxTick: [6x1 double]
    %    BoomCalConst: [3x1 double]
    %    BoomCalAngle: [3x1 double]
    %    BoomMaxTick: [3x1 double]
    %    MaxTick: [9x1 double]
    %    Motors: [9x1 double]
    %    KVHOrientation: [3x3 double]
    %    MicrostrainOrientation: [3x3 double]
    
    % {ElementName, Dimensions, DataType, SampleTime, Complexity, SamplingMode, DimensionsMode, Min, Max, DocUnits, Description};
    RobotCalibrationElementsCell = ...
        {{'AbsCalTick', 10,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'BoomCalTick',  3,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'AbsCalConst', 10,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'AbsCalAngle', 10,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'AbsMaxTick',  10,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'IncCalConst',  6,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'IncMaxTick',   6,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'BoomCalConst', 3,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'BoomCalAngle', 3,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'BoomMaxTick',  3,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'MaxTick',      9,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'Motors',       9,  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'KVHOrientation', [3 3],  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        {'MicrostrainOrientation', [3 3],  'double', inf, 'real', 'Sample', 'Fixed', [], [], '', ''} ...
        };
    RobotCalibrationCell = {'RobotCalibrationBus', '', 'Defines robot calibration structure', 'Auto', '-1', RobotCalibrationElementsCell};
    Simulink.Bus.cellToObject(formatCell(RobotCalibrationCell));
    assignin('base', 'RobotCalibration', initializeSimulinkBus('RobotCalibrationBus'));
end