function slot = sg_zmi4104_writereg_v2_m(id)
    %% Check if others VME setup blocks are present
    setupMasktype = 'vmesetup_zmi4104';

    setupBlocks=find_system(bdroot, ...
                            'FollowLinks', 'on', ...
                            'LookUnderMasks', 'all', ...
                            'MaskType', setupMasktype, ...
                            'id', num2str(id) );

    if isempty(setupBlocks)
        error(['No ZMI4104 Setup block found in model for Bus Adapter identifier ', num2str(id)]);
    end
    
        
    %% Load data from Setup block
    data = get_param(setupBlocks{1}, 'UserData');

    slot = data.slot;
        
    %% Parameters check
    
    %% Make data available for others blocks
    
    
    %% Mask Display
    %maskDisplay = sg_mask('ZMI4104','initaxis',id);
    maskDisplay = ['disp(''Speedgoat\nZMI4104\nWrite register\nBus Adapter: ',num2str(id),'\nZMI4104''); '];
    
    maskDisplay = [maskDisplay, 'port_label(''input'',1,''Enable'');'];
    maskDisplay = [maskDisplay, 'port_label(''input'',2,''ZMI4104 ID'');'];
    maskDisplay = [maskDisplay, 'port_label(''input'',3,''Axis'');'];
    maskDisplay = [maskDisplay, 'port_label(''input'',4,''PCI Access'');'];
    maskDisplay = [maskDisplay, 'port_label(''input'',5,''Register'');'];
    maskDisplay = [maskDisplay, 'port_label(''input'',6,''Value'');'];
        
    
    set_param(gcb, 'MaskDisplay', maskDisplay);
    
    maskDescription = 'Speedgoat driver block<br>ZMI4104 - Write register<br><br>&copy; 2006 - 2013, Speedgoat GmbH, www.speedgoat.ch';
    set_param(gcb, 'MaskDescription', maskDescription);
end

