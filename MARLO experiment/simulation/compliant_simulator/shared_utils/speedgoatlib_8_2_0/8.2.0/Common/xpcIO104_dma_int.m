function board = xpcIO104_dma_int

    board = [];  % Preset to empty return.
  
%  Keep the order of these structure elements the same or
%  you will get an error and the entry in the list won't work. 

     board.name = 'IO104 DMA INT';
     board.VendorId = hex2dec('10b5'); 
     board.DeviceId = hex2dec('9056'); 
     board.SubVendorId = hex2dec('10b5');
     board.SubDeviceId = hex2dec('3172');
     board.PreHookFunction = 'xpcio104dmaprehook';
     board.PostHookFunction =  'NULL'; %'xpcio104dmaposthook';
     board.HookIncludeFile = 'xpcIO104dmahooks';
     board.StartFunction = 'xpcio104dmastart';
     board.StopFunction = 'xpcio104dmastop';

 return;

