function makeInfo = rtwmakecfg()

%RTWMAKECFG adds include and source directories to code generation make files.
%   makeInfo=RTWMAKECFG returns a structured array containing build info.
%   Please refer to the rtwmakecfg API section in the Simulink Coder
%   Documentation for details on the format of this structure.
%-----------------------------------------------------------------------------
% This part links the model against all libraries in the AUTOLINK directory.
% It first assembles a list of all *.lib files in the AUTOLINK directory,
% removes the compiler indicator from each name, discards any duplicates
% thereby produced, and then adds the resulting list to the makeInfo record.
%
% Note that this strategy assumes that no collisions occur among names
% exported by the libraries. But this requirement is already forced on us by
% the fact that the model has a single namespace for all functions imported
% from external libs.
%
% Before adding a new lib to AUTOLINK, use the xpcLibCollide utility to check
% that no exported name in the new library collides with the names exported by
% libs in xpcblocks\AUTOLINK or xpcblocks\lib.

% Copyright 1995-2013 The MathWorks, Inc.

k = 0;

%----------------------------------------------------------------------------
% This part links libraries specifically requested by individual blocks in the
% model.  A block signals its need to link with a specific library by
% inserting an appropriate substring in its xpc_rtwmakecfg_data
% parameter. This parameter is created and updated by xpcLinkLib calls during
% InitFcn or mask initialization processing.

makeInfo.sourcePath = {};
makeInfo.includePath = {fullfile(pwd,'include')};
makeInfo.sources = {};

flds = get_param( bdroot, 'ObjectParameters' );
if isfield( flds, 'sg_rtwmakecfg_data' )
    data = get_param(bdroot, 'sg_rtwmakecfg_data');
else
    return;
end