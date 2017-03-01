function Input_bus() 
% INPUT_BUS initializes a set of bus objects in the MATLAB base workspace 

% Bus object: Input_bus 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 't';
elems(1).Dimensions = [1 1];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'q';
elems(2).Dimensions = [17 1];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'dq';
elems(3).Dimensions = [17 1];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).SamplingMode = 'Sample based';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

elems(4) = Simulink.BusElement;
elems(4).Name = 'ControlParams';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'Bus: ControlParams_bus';
elems(4).SampleTime = -1;
elems(4).Complexity = 'real';
elems(4).SamplingMode = 'Sample based';
elems(4).Min = [];
elems(4).Max = [];
elems(4).DocUnits = '';
elems(4).Description = '';

elems(5) = Simulink.BusElement;
elems(5).Name = 'ControlState';
elems(5).Dimensions = 1;
elems(5).DimensionsMode = 'Fixed';
elems(5).DataType = 'Bus: ControlState_bus';
elems(5).SampleTime = -1;
elems(5).Complexity = 'real';
elems(5).SamplingMode = 'Sample based';
elems(5).Min = [];
elems(5).Max = [];
elems(5).DocUnits = '';
elems(5).Description = '';

Input_bus = Simulink.Bus;
Input_bus.HeaderFile = '';
Input_bus.Description = '';
Input_bus.DataScope = 'Auto';
Input_bus.Alignment = -1;
Input_bus.Elements = elems;
clear elems;
assignin('base','Input_bus', Input_bus);

