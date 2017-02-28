function board = xpcIO301_inta_int
% <name>_int Returns a structure that describes an interrupt service
% routine for xPC Target.
%
%   If you are writing a driver that requires an interrupt
%   from your board, then you need to create an instance of
%   this file for your board or boards.  The output can
%   be a vector of board(1), board(2) structures, etc.
%
%   Copy this file under a new name, <yourname>int.m,
%   where <yourname> is some unique string that is unlikely
%   to be used by some other custom library vendor, such
%   as your company name.
%
%   Remove the '%' comment delimiters below and fill in
%   the entries for your board.
%
%   The board.name entry is the string that will be
%   displayed in the interrupting source list in both
%   the asyncronous interrupt block and on the xPC Target
%   options page of the configuration parameters for a
%   model.
%
%   The VendorId and DeviceId values must be given for
%   your board if it is a PCI board.  If you need to specify
%   the Subsystem vendor ID and Subsystem device ID to
%   uniquely identify your board, then fill those in.  They
%   are ignored if set to -1.  Not all boards require these.
%   Most board suppliers will give these values in hexidecimal.
%   Use the hex2dec() function to convert to numeric as shown.
%
%   If you are creating an interrupt service routine for an ISA
%   board or a PC/104 board, then you won't have PCI vendor and
%   device IDs.  Set the VendorId to -1 and the DeviceId to 1.
%
%   HookIncludeFile is the name of the C file that contains
%   your interrupt controlling functions.
%
%   StartFunction is the name of the function that enables
%   interrupts on your board and performs any final preparation
%   before the model execution starts.  This is called after
%   all mdlStart routines have been called for all blocks in
%   the model.
%
%   StopFunction is the name of the function that disables
%   interrupts and performs any shutdown functions for interrupts.
%   This function is called just before all mdlTerminate
%   routines will be called in the model.
%
%   PreHookFunction is the interrupt service routine.  Perform
%   any required register read/write to acknowledge the interrupt
%   on the board and stop it from interrupting.  Interrupts
%   will be enabled after this routine returns and before the
%   model executes.
%
%   PostHookFunction is not useful and should just be set to 'NULL'.
%
% VERY IMPORTANT STEPS:
%
%   After creating a new <name>_int.m file, you must 'rehash toolbox'
%   before the file will be correctly executed.
% 
%   After making any change to the board.name entry, you must
%   exit Matlab and restart it.  The menus are only populated
%   the first time they are requested after starting Matlab.
%
%   ORDER MATTERS in this structure.  If the order is incorrect,
%   combining this structure with the built in interrupt list will
%   fail.
%
%   So, the steps to adding a new file or editing an existing file are:
%   1.  Create the new file, or edit an existing one
%   2.  Exit MATLAB and restart it
%   3.  Execute 'rehash toolbox' to put the new file on the hash list
%   4.  Open a model and check for your new entry on the interrupt list
  
% Copyright 2006 The MathWorks, Inc.
% $Revision: 1.1.6.2 $ $Date: 2006/12/20 08:11:58 $

  board = [];  % Preset to empty return.
  
%  Keep the order of these structure elements the same or
%  you will get an error and the entry in the list won't work.
 
 
 board.name = 'Speedgoat IO301 IntA';
 board.VendorId = hex2dec('16d5'); 
 board.DeviceId = hex2dec('4350'); 
 board.SubVendorId = hex2dec('16d5');
 board.SubDeviceId = hex2dec('4350');
 board.PreHookFunction = 'xpcIO301intaprehook';
 board.PostHookFunction =  'NULL';  %'xpcdx501intaposthook'
 board.HookIncludeFile = 'xpcIO301intahooks';
 board.StartFunction = 'xpcIO301intastart';
 board.StopFunction = 'xpcIO301intastop';

 return;

