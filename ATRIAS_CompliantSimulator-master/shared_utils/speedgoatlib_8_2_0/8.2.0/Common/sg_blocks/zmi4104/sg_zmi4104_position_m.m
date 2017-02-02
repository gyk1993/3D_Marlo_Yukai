function slot = sg_zmi4104_position_m(id, zmi_id, axis, act_vel, act_time)
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
    maskDisplay = ['disp(''Speedgoat\nZMI4104\nPosition\nBus Adapter: ',num2str(id),'\nZMI4104: ',num2str(zmi_id),'\nAxis: ',num2str(axis),'''); '];
    
    nPort = 1;
    maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(nPort),',''Position'');'];
    nPort = nPort + 1;
        
    if act_vel == 1
        maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(nPort),',''Velocity'');'];
        nPort = nPort + 1;
%         maskDisplay = [maskDisplay, 'port_label(''output'',1,''Position'');'];
    end
    
    if act_time == 1
        maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(nPort),',''Time'');'];
        nPort = nPort + 1;
    end
    
%     maskDisplay = [maskDisplay, 'port_label(''output'',2,''Sample Position'');'];
%     maskDisplay = [maskDisplay, 'port_label(''output'',3,''Velocity'');'];
%     maskDisplay = [maskDisplay, 'port_label(''output'',4,''Time'');'];
    
    set_param(gcb, 'MaskDisplay', maskDisplay);
    
    maskDescription = 'Speedgoat driver block<br>ZMI4104 - Position<br><br>&copy; 2006 - 2012, Speedgoat GmbH, www.speedgoat.ch';
    set_param(gcb, 'MaskDescription', maskDescription);
end

