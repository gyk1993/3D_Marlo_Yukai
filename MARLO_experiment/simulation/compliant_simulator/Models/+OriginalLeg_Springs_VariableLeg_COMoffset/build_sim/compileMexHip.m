function compileMexHip()
	% Compile mex functions for symbolic calculations
	% Autogenerated by symbolicToMex on 2016-10-13 17:39
	% CWD during code generation: C:\Users\Ross\Documents\SVN\MARLO_Models\OriginalLeg_Springs_VariableLeg_COMoffset
	prevdir = cd;
	cd(fileparts(mfilename('fullpath')));
	compileAll();
	cd(prevdir);


function compileAll()
	% Compile each mex-function
	% In order to generate object files which could be linked in other code
	% (such as in an s-function), the compilation is done in two steps:
	% First, the primary code file is compiled without linking or creating
	% a mex-function. Then the main mex file is compiled and linked against
	% the object file.

	% Create function to change object file extension on Windows
	if ispc()
		obj = @(file) regexprep(file, '\.o$', '.obj');
	else
		obj = @(file) file;
	end

	disp('[BUILDING <a href="matlab:edit(''ATRIAS3D_Positions_Hip'')">ATRIAS3D_Positions_Hip</a>]')
	disp('mex(''-c'', ''-Icpp'', ''-outdir'', ''cpp'', ''cpp\ATRIAS3D_Positions_Hip.c'')')
	mex('-c', '-Icpp', '-outdir', 'cpp', 'cpp\ATRIAS3D_Positions_Hip.c')
	disp('mex(''-Icpp'', ''-outdir'', ''mex'', ''cpp\CATRIAS3D_Positions_Hip.c'', obj(''cpp\ATRIAS3D_Positions_Hip.obj''))')
	mex('-Icpp', '-outdir', 'mex', 'cpp\CATRIAS3D_Positions_Hip.c', obj('cpp\ATRIAS3D_Positions_Hip.obj'))

	disp('[BUILDING <a href="matlab:edit(''ATRIAS3D_VelocitiesAccel_Hip'')">ATRIAS3D_VelocitiesAccel_Hip</a>]')
	disp('mex(''-c'', ''-Icpp'', ''-outdir'', ''cpp'', ''cpp\ATRIAS3D_VelocitiesAccel_Hip.c'')')
	mex('-c', '-Icpp', '-outdir', 'cpp', 'cpp\ATRIAS3D_VelocitiesAccel_Hip.c')
	disp('mex(''-Icpp'', ''-outdir'', ''mex'', ''cpp\CATRIAS3D_VelocitiesAccel_Hip.c'', obj(''cpp\ATRIAS3D_VelocitiesAccel_Hip.obj''))')
	mex('-Icpp', '-outdir', 'mex', 'cpp\CATRIAS3D_VelocitiesAccel_Hip.c', obj('cpp\ATRIAS3D_VelocitiesAccel_Hip.obj'))

	disp('[BUILDING <a href="matlab:edit(''ATRIAS3D_FootPointPosJacob_Hip'')">ATRIAS3D_FootPointPosJacob_Hip</a>]')
	disp('mex(''-c'', ''-Icpp'', ''-outdir'', ''cpp'', ''cpp\ATRIAS3D_FootPointPosJacob_Hip.c'')')
	mex('-c', '-Icpp', '-outdir', 'cpp', 'cpp\ATRIAS3D_FootPointPosJacob_Hip.c')
	disp('mex(''-Icpp'', ''-outdir'', ''mex'', ''cpp\CATRIAS3D_FootPointPosJacob_Hip.c'', obj(''cpp\ATRIAS3D_FootPointPosJacob_Hip.obj''))')
	mex('-Icpp', '-outdir', 'mex', 'cpp\CATRIAS3D_FootPointPosJacob_Hip.c', obj('cpp\ATRIAS3D_FootPointPosJacob_Hip.obj'))
