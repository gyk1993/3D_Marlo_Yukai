function msg = EtherCATError(code)
    codes = {...
        0,     'EtherCAT working normally (no error)'; ...
        65537, 'Cyclic command: working counter error'; ...
        65538, 'Master initialization command: working counter error'; ...
        65539, 'Slave initialization command: working counter error'; ...
        65540, 'EOE mailbox receive: working counter error'; ...
        65541, 'COE mailbox receive: working counter error'; ...
        65542, 'FOE mailbox receive: working counter error'; ...
        65543, 'EOE mailbox send: working counter error'; ...
        65544, 'COE mailbox send: working counter error'; ...
        65545, 'FOE mailbox send: working counter error'; ...
        65546, 'Got no response on a sent Ethernet frame'; ...
        65547, 'Got no response on a sent EtherCAT initialization command from slave'; ...
        65548, 'Got no response on a sent EtherCAT master initialization command'; ...
        65549, 'Missing EtherCAT command in received Ethernet frame'; ...
        65550, 'Timeout when waiting for mailbox initialization command response'; ...
        65551, 'Not all slave devices are in operational state when receiving cyclic frames'; ...
        65552, 'Ethernet link (cable) not connected'; ...
        65553, 'Not in use'; ...
        65554, 'Redundancy: line break detected'; ...
        65555, 'At least one slave is in error state when receiving cyclic frames (BRD AL-STATUS)'; ...
        65556, 'Slave error status information'; ...
        65557, 'Fixed station address lost (or slave missing) - FPRD to AL_STATUS failed'; ...
        65558, 'SOE mailbox receive: working counter error'; ...
        65559, 'SOE mailbox send: working counter error'; ...
        65560, 'SOE mailbox write responded with an error'; ...
        65561, 'COE mailbox SDO abort'; ...
        65562, 'Client registration dropped, possibly call to ecatConfigureMaster by other thread (RAS)'; ...
        65563, 'Redundancy: line is repaired'; ...
        65564, 'FOE mailbox abort'; ...
        };
    
    if isstruct(code)
        code = code.EtherCATStatus(end,1);
    end
    
    idx = find([codes{:,1}] == code);
    if ~isempty(idx)
        msg = codes{idx,2};
    else
        msg = 'Unknown EtherCAT Error code.';
    end
end