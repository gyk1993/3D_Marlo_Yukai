function propagatePortNames(SrcBlock)
    
    Outports = find_system(gcb,'SearchDepth',1,'BlockType','Outport');
    OutportNames = regexp(Outports, '[^/]+$', 'match', 'once');
    PortConn = get_param(SrcBlock, 'PortConnectivity');
    j = 0;
    for k=1:length(PortConn)
        if ~isempty(PortConn(k).DstBlock)
            Outport = findOutport(PortConn(k).DstBlock);
            if ~isempty(Outport)
                j = j+1;
                set_param(Outport, 'Name', OutportNames{j});
            end
        end
    end
end

function Outport = findOutport(SrcBlock)
    Outport = [];
    if strcmpi(get_param(SrcBlock, 'BlockType'),  'Outport')
        Outport = SrcBlock;
    else
        PortConn = get_param(SrcBlock, 'PortConnectivity');
        for k=1:length(PortConn)
            if ~isempty(PortConn(k).DstBlock)
                Outport = findOutport(PortConn(k).DstBlock);
                break
            end
        end
    end
end
