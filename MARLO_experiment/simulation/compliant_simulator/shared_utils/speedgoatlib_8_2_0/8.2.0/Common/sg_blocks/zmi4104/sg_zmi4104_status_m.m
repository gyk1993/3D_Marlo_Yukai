function slot = sg_zmi4104_status_m(id, zmi_id, axis)
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
    maskDisplay = ['disp(''Speedgoat\nZMI4104\nStatus\nBus Adapter: ',num2str(id),'\nZMI4104: ',num2str(zmi_id),'\nAxis: ',num2str(axis),'''); '];
        
    maskDisplay = [maskDisplay, 'port_label(''output'',1,''Errors'');'];
    
    set_param(gcb, 'MaskDisplay', maskDisplay);
    
    maskDescription = 'Speedgoat driver block<br>ZMI4104 - Status<br><br>&copy; 2006 - 2012, Speedgoat GmbH, www.speedgoat.ch';
    set_param(gcb, 'MaskDescription', maskDescription);
end

