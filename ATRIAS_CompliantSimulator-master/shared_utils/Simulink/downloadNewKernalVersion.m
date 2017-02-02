function downloadNewKernalVersion(varargin)
%% Specify default input arguments and input parser

    defaultKernelFilePath       = tempname;
    defaultMultiCoreSupport     = 'on';
    defaultGraphicsModeSupport  = 'Enabled';
    defaultUsbSupport           = 'on';
    defaultTarget               = 'Speedgoat';
    %defaultCommunicationTimeOut = 20; % (sec)
      
    p = inputParser;
    addParameter(p,'kernelFilePath',defaultKernelFilePath,@ischar);
    addParameter(p,'multiCoreSupport',defaultMultiCoreSupport,@validMultiCoreSupportParameter);
    addParameter(p,'graphicsModeSupport',defaultGraphicsModeSupport,@validGraphicsModeSupportParameter);
    addParameter(p,'usbSupport',defaultUsbSupport,@validUsbModeSupportParameter);
    addParameter(p,'targetName',defaultTarget,@ischar);
    %addParameter(p,'communicationTimeOut',defaultCommunicationTimeOut,@numeric);
   
    % get input parameters and assign them to appropriate internal
    % variables
    parse(p,varargin{:});
    kernelFilePath       = p.Results.kernelFilePath;
    multiCoreSupport     = p.Results.multiCoreSupport;
    graphicsModeSupport  = p.Results.graphicsModeSupport;
    usbSupport           = p.Results.usbSupport;
    targetName           = p.Results.targetName;
    %communicationTimeOut = p.Results.communicationTimeOut;
    
% note: using an Ethernet Switch seems to cause occasional Tcp/Ip time outs.
%       Connecting host to target using USB to Ethernet adapter direct to
%       target seems to eliminate this problem.


% get the names of any existing target environments
target = SimulinkRealTime.getTargetSettings;

% the target we want to use is called "Mobile"
if strcmpi(target.Name, targetName)
    
    if ismember('kernelFilePath', p.UsingDefaults)
        mkdir(kernelFilePath)
    end
    
    % adjust the kernal attributes
    set(target,'TargetBoot', 'DOSLoader')
    set(target, 'DOSLoaderLocation', kernelFilePath)
    set(target, 'MultiCoreSupport', multiCoreSupport)
    set(target, 'TargetScope', graphicsModeSupport)
    set(target, 'USBSupport', usbSupport)
    %set(target, 'CommunicationTimeOut', communicationTimeOut)
    
    % create the boot image
    SimulinkRealTime.createBootImage(targetName)
    
    % rename generated boot image to xpckrnl.rtb
    kernelFiles = dir(fullfile(kernelFilePath, '*.rtb'));
    origKernelFileName = kernelFiles.name;
    
    if ~isempty(origKernelFileName)
        movefile(fullfile(kernelFilePath,origKernelFileName),...
                 fullfile(kernelFilePath,'xpckrnl.rtb'));
    end
    
    % create a SLRT target object to transfer the kernel files
    tg = slrt;
    
    currentDir = pwd;       % save current directory
    cd(kernelFilePath)      % change to directory containing kernel file
    
    % copyFileToTarget only copies files from current directory
    SimulinkRealTime.copyFileToTarget(tg,'xpckrnl.rtb');
    pause(0.5)              % give the file transfer time to complete
    
    % return to previous directory
    cd(currentDir);
    
    % reboot target to load in the new kernel
    reboot(tg);
else
    fprintf('\nExpected to find target %s, but instead found %s\n', ...
                                                   targetName, target.Name)
end

%% Clean up unnneded files
% Delete xpcboot.com and autoexec.bat, we only need xpckrnl.rtb
if exist(fullfile(kernelFilePath, 'xpcboot.com'), 'file')
    delete(fullfile(kernelFilePath, 'xpcboot.com'))
end

autoExecFiles = dir(fullfile(kernelFilePath, 'autoexec.*'));
if ~isempty(autoExecFiles)
    delete(fullfile(kernelFilePath, 'autoexec.*'))
end

if ismember('kernelFilePath', p.UsingDefaults)
    if exist(fullfile(kernelFilePath, 'xpckrnl.rtb'), 'file')
        delete(fullfile(kernelFilePath, 'xpckrnl.rtb'))
    end
    rmdir(kernelFilePath)
end

%% Wait until target machine has finished rebooting before returning
fprintf('\nSimulink Real Time Target Machine rebooting\n');

rebooted = false;
t = clock;          % get current time

while ~rebooted && etime(clock,t)<150
    pause(2)        % ping every 2 seconds
    fprintf(1,'.');
    try
        status = slrtpingtarget;
    catch err
        fprintf('encountered %s error\n\n', err)
    end
    
    if strcmpi(status, 'Success')
        rebooted = true;
    end
end

fprintf('\nSimulink Real Time Target Machine reboot complete\n');

end

function validMultiCoreSupportParameter(parameter)
% valid values for multiCoreSupport parameter are:
% 'on'
% 'off'
assert((strcmpi(parameter, 'on') || strcmpi(parameter, 'off')) && ...
       ischar(parameter),...
       'Value must be a string wtih values ''on'' or ''off''')
end

function validGraphicsModeSupportParameter(parameter)
% valid values for graphicsModeSupport parameter are:
% 'Enabled'
% 'Disabled'
assert((strcmpi(parameter, 'Enabled') || strcmpi(parameter, 'Disabled')) && ...
       ischar(parameter),...
       'Value must be a string wtih values ''Enabled'' or ''Disabled''')
end

function validUsbModeSupportParameter(parameter)
% valid values for usbModeSupport parameter are:
% 'on'
% 'off'
assert((strcmpi(parameter, 'on') || strcmpi(parameter, 'off')) && ...
       ischar(parameter),...
       'Value must be a string wtih values ''on'' or ''off''')
end
