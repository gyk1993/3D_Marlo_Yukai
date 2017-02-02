function board = xpcIO302_inta_int
  
  board = [];  % Preset to empty return.
  
 
  board.name = 'Speedgoat IO302 IntA';
  board.VendorId = hex2dec('16d5'); 
  board.DeviceId = hex2dec('4357'); 
  board.SubVendorId = hex2dec('16d5');
  board.SubDeviceId = hex2dec('4357');
  board.PreHookFunction = 'xpcIO302intaprehook';
  board.PostHookFunction = 'NULL';
  board.HookIncludeFile = 'xpcIO302intahooks';
  board.StartFunction = 'xpcIO302intastart';
  board.StopFunction = 'xpcIO302intastop';

 return;

