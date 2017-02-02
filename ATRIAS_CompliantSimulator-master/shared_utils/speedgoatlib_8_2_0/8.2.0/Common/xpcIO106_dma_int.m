function board = xpcIO106_dma_int

    board = [];  % Preset to empty return.
  
%  Keep the order of these structure elements the same or
%  you will get an error and the entry in the list won't work. 

     board.name = 'IO106 DMA INT';
     board.VendorId = hex2dec('10b5'); 
     board.DeviceId = hex2dec('9056'); 
     board.SubVendorId = hex2dec('10b5');
     board.SubDeviceId = hex2dec('3101');
     board.PreHookFunction = 'xpcio106dmaprehook';
     board.PostHookFunction =  'NULL';  %xpcio106dmaposthook
     board.HookIncludeFile = 'xpcIO106dmahooks';
     board.StartFunction = 'xpcio106dmastart';
     board.StopFunction = 'xpcio106dmastop';

 return;

