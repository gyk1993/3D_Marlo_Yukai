(* ::Package:: *)

(* ::Title:: *)
(*Export Simulation*)


statesubsCpp=Dispatch@Join[
	((\[ScriptCapitalX][[#+1,1]]-> HoldForm@x[[#]]&)/@(Range[2*ndof]-1))]

statesubsMatlab=Dispatch@Join[
	((\[ScriptCapitalX][[#,1]]-> x[#]&)/@(Range[2*ndof]))]


SetOptions[CseWriteCpp,
	ExportDirectory->$SimExportPath,
	ArgumentLists->{x},
	ArgumentDimensions-> {{2*ndof,1}},
	SubstitutionRules-> statesubsCpp,
	ExportFull->False
];

SetOptions[CseWriteMatlab,
	ExportDirectory->$SimExportPath<>"/m",
	Arguments->{x},
	SubstitutionRules-> statesubsMatlab
];


(* ::Section:: *)
(*Export Kinematics*)


(* Center of Mass Position *)
If[StringMatchQ[model["type"],"planar"],
	CseWriteCpp["pe_com_vec",Join[{Subscript[pe, com][[1]]},{Subscript[pe, com][[3]]}]]
	CseWriteCpp["Je_com_mat",Join[{Subscript[Je, com][[1]]},{Subscript[Je, com][[3]]}]]
	CseWriteCpp["dJe_com_mat",Join[{Subscript[dJe, com][[1]]},{Subscript[dJe, com][[3]]}]]
	,
	CseWriteCpp["pe_com_vec",Subscript[pe, com]]
	CseWriteCpp["Je_com_mat",Subscript[Je, com]]
	CseWriteCpp["dJe_com_mat",Subscript[dJe, com]]
];


If[StringMatchQ[model["type"],"planar"],
	CseWriteMatlab["pe_com_vec",{Join[{Subscript[pe, com][[1]]},{Subscript[pe, com][[3]]}]}]
	CseWriteMatlab["Je_com_mat",{Join[{Subscript[Je, com][[1]]},{Subscript[Je, com][[3]]}]}]
	CseWriteMatlab["dJe_com_mat",{Join[{Subscript[dJe, com][[1]]},{Subscript[dJe, com][[3]]}]}]
	,
	CseWriteMatlab["pe_com_vec",{Subscript[pe, com]}]
	CseWriteMatlab["Je_com_mat",{Subscript[Je, com]}]
	CseWriteMatlab["dJe_com_mat",{Subscript[dJe, com]}]
];


If[StringMatchQ[model["type"],"planar"],
	Block[
		{name,lambda,offset,p,\[ScriptCapitalR],\[ScriptCapitalR]0,\[ScriptCapitalR]w,\[Omega],syms,roll,pitch,yaw,h6dof,Jh6dof},
		Table[
			name=dofs[[i]]["name"][[1]];
			syms=StringJoin[name,#]&/@{"PosX","PosZ"}//ToExpression;
			
			Subscript[h, ToExpression[name]] = Table[Subscript[h, syms[[j]]],{j,2}];
			Subscript[Jh, ToExpression[name]] = Table[Subscript[Jh, syms[[j]]],{j,2}];
			Subscript[dJh, ToExpression[name]] = Table[Subscript[dJh, syms[[j]]],{j,2}];

			CseWriteMatlab["p_"<>name, Subscript[h, ToExpression[name]]];
			CseWriteMatlab["J_"<>name, Subscript[Jh, ToExpression[name]]];
			CseWriteMatlab["dJ_"<>name, Subscript[dJh, ToExpression[name]]];
			CseWriteMatlab["R_"<>name, Subscript[\[ScriptCapitalR], name]];
			CseWriteMatlab["w_body_"<>name, Subscript[\[Omega], name<>"_body"]];
			CseWriteMatlab["Jw_body_"<>name, Subscript[J\[Omega], name<>"_body"]];
			CseWriteMatlab["dJw_body_"<>name, Subscript[dJ\[Omega], name<>"_body"]];
			CseWriteMatlab["w_world_"<>name, Subscript[\[Omega], name<>"_world"]];
			CseWriteMatlab["Jw_world_"<>name, Subscript[J\[Omega], name<>"_world"]];
			CseWriteMatlab["dJw_world_"<>name, Subscript[dJ\[Omega], name<>"_world"]];

			CseWriteCpp["p_"<>name, {Subscript[h, ToExpression[name]]}];
			CseWriteCpp["J_"<>name, {Subscript[Jh, ToExpression[name]]}];
			CseWriteCpp["dJ_"<>name, {Subscript[dJh, ToExpression[name]]}];
			CseWriteCpp["R_"<>name, {Subscript[\[ScriptCapitalR], name]}];
			CseWriteCpp["w_body_"<>name, {Subscript[\[Omega], name<>"_body"]}];
			CseWriteCpp["Jw_body_"<>name, {Subscript[J\[Omega], name<>"_body"]}];
			CseWriteCpp["dJw_body_"<>name, {Subscript[dJ\[Omega], name<>"_body"]}];
			CseWriteCpp["w_world_"<>name, {Subscript[\[Omega], name<>"_world"]}];
			CseWriteCpp["Jw_world_"<>name, {Subscript[J\[Omega], name<>"_world"]}];
			CseWriteCpp["dJw_world_"<>name, {Subscript[dJ\[Omega], name<>"_world"]}];
			,
			{i,4,ndof}
		];
	];,
	Block[
		{name,lambda,offset,p,\[ScriptCapitalR],\[ScriptCapitalR]0,\[ScriptCapitalR]w,\[Omega],syms,roll,pitch,yaw,h6dof,Jh6dof},
		Table[
			name=dofs[[i]]["name"][[1]];
			syms=StringJoin[name,#]&/@{"PosX","PosY","PosZ"}//ToExpression;
			
			Subscript[h, ToExpression[name]] = Table[Flatten[Subscript[h, syms[[j]]]],{j,3}];
			Subscript[Jh, ToExpression[name]] = Table[Flatten[Subscript[Jh, syms[[j]]]],{j,3}];
			Subscript[dJh, ToExpression[name]] = Table[Flatten[Subscript[dJh, syms[[j]]]],{j,3}];
			
			CseWriteMatlab["p_"<>name, Subscript[h, ToExpression[name]]];
			CseWriteMatlab["Jp_"<>name, Subscript[Jh, ToExpression[name]]];
			CseWriteMatlab["dJp_"<>name, Subscript[dJh, ToExpression[name]]];
			CseWriteMatlab["R_"<>name, Subscript[\[ScriptCapitalR], name]];
			CseWriteMatlab["w_body_"<>name, Subscript[\[Omega], name<>"_body"]];
			CseWriteMatlab["Jw_body_"<>name, Subscript[J\[Omega], name<>"_body"]];
			CseWriteMatlab["dJw_body_"<>name, Subscript[dJ\[Omega], name<>"_body"]];
			CseWriteMatlab["w_world_"<>name, Subscript[\[Omega], name<>"_world"]];
			CseWriteMatlab["Jw_world_"<>name, Subscript[J\[Omega], name<>"_world"]];
			CseWriteMatlab["dJw_world_"<>name, Subscript[dJ\[Omega], name<>"_world"]];

			CseWriteCpp["p_"<>name, {Subscript[h, ToExpression[name]]}];
			CseWriteCpp["J_"<>name, {Subscript[Jh, ToExpression[name]]}];
			CseWriteCpp["dJ_"<>name, {Subscript[dJh, ToExpression[name]]}];
			CseWriteCpp["R_"<>name, {Subscript[\[ScriptCapitalR], name]}];
			CseWriteCpp["w_body_"<>name, {Subscript[\[Omega], name<>"_body"]}];
			CseWriteCpp["Jw_body_"<>name, {Subscript[J\[Omega], name<>"_body"]}];
			CseWriteCpp["dJw_body_"<>name, {Subscript[dJ\[Omega], name<>"_body"]}];
			CseWriteCpp["w_world_"<>name, {Subscript[\[Omega], name<>"_world"]}];
			CseWriteCpp["Jw_world_"<>name, {Subscript[J\[Omega], name<>"_world"]}];
			CseWriteCpp["dJw_world_"<>name, {Subscript[dJ\[Omega], name<>"_world"]}];
			,
			{i,7,ndof}
		];
	];
];


poi=config["points of interest"];

If[StringMatchQ[model["type"],"planar"],
	Block[
		{name,lambda,offset,p,\[ScriptCapitalR],\[ScriptCapitalR]0,\[ScriptCapitalR]w,\[Omega],syms,roll,pitch,yaw,h6dof,Jh6dof},
		Table[
			name=pos["name"];
			syms=StringJoin[name,#]&/@{"PosX","PosZ"}//ToExpression;
			
			Subscript[h, ToExpression[name]] = Table[Subscript[h, syms[[j]]],{j,2}];
			Subscript[Jh, ToExpression[name]] = Table[Subscript[Jh, syms[[j]]],{j,2}];
			Subscript[dJh, ToExpression[name]] = Table[Subscript[dJh, syms[[j]]],{j,2}];

			CseWriteMatlab["p_"<>name, Subscript[h, ToExpression[name]]];
			CseWriteMatlab["J_"<>name, Subscript[Jh, ToExpression[name]]];
			CseWriteMatlab["dJ_"<>name, Subscript[dJh, ToExpression[name]]];
			CseWriteMatlab["R_"<>name, Subscript[\[ScriptCapitalR], name]];
			CseWriteMatlab["w_body_"<>name, Subscript[\[Omega], name<>"_body"]];
			CseWriteMatlab["Jw_body_"<>name, Subscript[J\[Omega], name<>"_body"]];
			CseWriteMatlab["dJw_body_"<>name, Subscript[dJ\[Omega], name<>"_body"]];
			CseWriteMatlab["w_world_"<>name, Subscript[\[Omega], name<>"_world"]];
			CseWriteMatlab["Jw_world_"<>name, Subscript[J\[Omega], name<>"_world"]];
			CseWriteMatlab["dJw_world_"<>name, Subscript[dJ\[Omega], name<>"_world"]];

			CseWriteCpp["p_"<>name, {Subscript[h, ToExpression[name]]}];
			CseWriteCpp["J_"<>name, {Subscript[Jh, ToExpression[name]]}];
			CseWriteCpp["dJ_"<>name, {Subscript[dJh, ToExpression[name]]}];
			CseWriteCpp["R_"<>name, {Subscript[\[ScriptCapitalR], name]}];
			CseWriteCpp["w_body_"<>name, {Subscript[\[Omega], name<>"_body"]}];
			CseWriteCpp["Jw_body_"<>name, {Subscript[J\[Omega], name<>"_body"]}];
			CseWriteCpp["dJw_body_"<>name, {Subscript[dJ\[Omega], name<>"_body"]}];
			CseWriteCpp["w_world_"<>name, {Subscript[\[Omega], name<>"_world"]}];
			CseWriteCpp["Jw_world_"<>name, {Subscript[J\[Omega], name<>"_world"]}];
			CseWriteCpp["dJw_world_"<>name, {Subscript[dJ\[Omega], name<>"_world"]}];
			,
			{pos,poi}
		];
	];,
	Block[
		{name,lambda,offset,p,\[ScriptCapitalR],\[ScriptCapitalR]0,\[ScriptCapitalR]w,\[Omega],syms,roll,pitch,yaw,h6dof,Jh6dof},
		Table[
			name=pos["name"];
			syms=StringJoin[name,#]&/@{"PosX","PosY","PosZ"}//ToExpression;
			
			Subscript[h, ToExpression[name]] = Table[Flatten[Subscript[h, syms[[j]]]],{j,3}];
			Subscript[Jh, ToExpression[name]] = Table[Flatten[Subscript[Jh, syms[[j]]]],{j,3}];
			Subscript[dJh, ToExpression[name]] = Table[Flatten[Subscript[dJh, syms[[j]]]],{j,3}];
			
			CseWriteMatlab["p_"<>name, Subscript[h, ToExpression[name]]];
			CseWriteMatlab["Jp_"<>name, Subscript[Jh, ToExpression[name]]];
			CseWriteMatlab["dJp_"<>name, Subscript[dJh, ToExpression[name]]];
			CseWriteMatlab["R_"<>name, Subscript[\[ScriptCapitalR], name]];
			CseWriteMatlab["w_body_"<>name, Subscript[\[Omega], name<>"_body"]];
			CseWriteMatlab["Jw_body_"<>name, Subscript[J\[Omega], name<>"_body"]];
			CseWriteMatlab["dJw_body_"<>name, Subscript[dJ\[Omega], name<>"_body"]];
			CseWriteMatlab["w_world_"<>name, Subscript[\[Omega], name<>"_world"]];
			CseWriteMatlab["Jw_world_"<>name, Subscript[J\[Omega], name<>"_world"]];
			CseWriteMatlab["dJw_world_"<>name, Subscript[dJ\[Omega], name<>"_world"]];

			CseWriteCpp["p_"<>name, {Subscript[h, ToExpression[name]]}];
			CseWriteCpp["J_"<>name, {Subscript[Jh, ToExpression[name]]}];
			CseWriteCpp["dJ_"<>name, {Subscript[dJh, ToExpression[name]]}];
			CseWriteCpp["R_"<>name, {Subscript[\[ScriptCapitalR], name]}];
			CseWriteCpp["w_body_"<>name, {Subscript[\[Omega], name<>"_body"]}];
			CseWriteCpp["Jw_body_"<>name, {Subscript[J\[Omega], name<>"_body"]}];
			CseWriteCpp["dJw_body_"<>name, {Subscript[dJ\[Omega], name<>"_body"]}];
			CseWriteCpp["w_world_"<>name, {Subscript[\[Omega], name<>"_world"]}];
			CseWriteCpp["Jw_world_"<>name, {Subscript[J\[Omega], name<>"_world"]}];
			CseWriteCpp["dJw_world_"<>name, {Subscript[dJ\[Omega], name<>"_world"]}];
			,
			{pos,poi}
		];
	];
];


(* ::Section:: *)
(*Export Dynamics*)


exprs={
	{"De_mat",{\[ScriptCapitalD]e}},
	{"Ve_sca",{Ve}},
	{"Ce_mat",{\[ScriptCapitalC]e}},
	{"Ge_vec",{\[ScriptCapitalG]e}},
	{"Be_mat",{\[ScriptCapitalB]e}}
};


Block[{name,sym,expr},
	Table[
		{name,sym}=expr;
		CseWriteCpp[name,sym];
		,
		{expr,exprs}
	];
];//AbsoluteTiming



