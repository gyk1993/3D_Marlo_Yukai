function sg_zmi4104_vmesetup_m(id, modules, slot)
    %% Check if others VME setup blocks are present
    masktype = get_param( gcb, 'MaskType' );

    setupBlocks=find_system(bdroot, ...
                            'FollowLinks', 'on', ...
                            'LookUnderMasks', 'all', ...
                            'MaskType', masktype, ...
                            'id', id );

    if length(setupBlocks)>1
        error('Only one instance of the VME Setup block per Bus Adapter identifier allowed in a model');
    end
    
    %% Parameters check
    
    %% Make data available for others blocks
    data.id = id;
    data.slot = slot;
    
    %set_param(gcb, 'UserDataPersistent', 'on');
    set_param(gcb, 'UserData', data );
    
    %% Mask Display
    %maskDisplay = sg_mask('ZMI4104','vmesetup',id);
    maskDisplay = ['disp(''Speedgoat\nZMI4104\nVME Setup\nBus Adapter: ',num2str(id),'''); '];
    
    for i = 1 : modules
        maskDisplay = [maskDisplay, 'port_label(''output'',', num2str(i),',''ZMI4104 (', num2str(i),')'');'];
    end
        
        
    
    set_param(gcb, 'MaskDisplay', maskDisplay);
    
    maskDescription = 'Speedgoat driver block<br>ZMI4104 - VME Setup<br><br>&copy; 2006 - 2012, Speedgoat GmbH, www.speedgoat.ch';
    set_param(gcb, 'MaskDescription', maskDescription);
end

