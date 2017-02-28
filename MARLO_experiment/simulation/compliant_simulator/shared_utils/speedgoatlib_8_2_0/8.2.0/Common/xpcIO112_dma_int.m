function board = xpcIO112_dma_int

    board = [];  % Preset to empty return.
  
%  Keep the order of these structure elements the same or
%  you will get an error and the entry in the list won't work. 

     board.name = 'IO112 DMA INT';
     board.VendorId = hex2dec('10b5'); 
     board.DeviceId = hex2dec('9056'); 
     board.SubVendorId = hex2dec('10b5');
     board.SubDeviceId = hex2dec('3431');
	  board.PreHookFunction = 'xpcio112dmaprehook';
     board.PostHookFunction =  'NULL';  
     board.HookIncludeFile = 'xpcIO112dmahooks';
     board.StartFunction = 'xpcio112dmastart';
     board.StopFunction = 'xpcio112dmastop';

 return;

