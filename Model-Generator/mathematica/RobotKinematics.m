(* ::Package:: *)

(* ::Title:: *)
(*RobotExprKinematics*)


(* ::Section:: *)
(*Center of Mass Position*)


masses=Block[{dof},Table[dof["mass"],{dof,dofs}]];
mass=Total[masses];
Subscript[pe, com]=Transpose[{ \!\(
\*UnderoverscriptBox[\(\[Sum]\), \(i = 1\), \(ndof\)]\(masses[\([i]\)]\ 
\(\*SubscriptBox[\(p\), 
SubscriptBox[\(sl\), \(i\)]]\)[\[Theta]]/mass\)\)}];
Subscript[Je, com]=D[Flatten[Subscript[pe, com]],{Flatten[Qe],1}];
Subscript[dJe, com]=D[Subscript[Je, com],t];



name="Com";
syms=StringJoin[name,#]&/@{"PosX","PosY","PosZ"}//ToExpression;
Table[
	Subscript[h, syms[[i]]]=Subscript[pe, com][[i]];
	Subscript[Jh, syms[[i]]]=Subscript[pe, com][[i]];
	Subscript[dJh, syms[[i]]]=\!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]
\*SubscriptBox[\(Jh\), \(syms[\([i]\)]\)]\);
	,
	{i,3}
];


(* ::Section:: *)
(*Generate expressions (h,Jh,Jhdot)*)


(* ::Subsection:: *)
(*For all links*)


Block[
	{name,lambda,offset,p,syms,nStart},
	If[StringMatchQ[model["type"],"planar"],
		nStart = 4;
		,
		nStart = 7;
	];
	Table[
		name=dofs[[i]]["name"][[1]];
		lambda=i;
		(*offset=ToExpression[pos["offset"]]/.kinConsts;//N*)
		offset={0,0,0}//N;
		(* Position in world frame*)
		p=RigidPosition[Subscript[g, Subscript[sj, lambda]][\[Theta]].RPToHomogeneous[I3,offset]];
		(* Jacobian of position *)
		J=Join[\!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[Qe], 1}\)]p\)];
		(* Rotation from body frame to world frame*)
		Subscript[\[ScriptCapitalR], name] =RigidOrientation[Subscript[g, Subscript[sj, lambda]][\[Theta]].RPToHomogeneous[I3,offset]];
		(* Angular Velocity in the body frame *)
		Subscript[\[Omega], name<>"_body"] = CrossProd[Transpose[Subscript[\[ScriptCapitalR], name]].\!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[\[ScriptCapitalR], \ name]\)\)];
		(* Angular Velocity in the world frame *)
		Subscript[\[Omega], name<>"_world"] = Subscript[\[ScriptCapitalR], name].Subscript[\[Omega], name<>"_body"];

		(* Store Variables*)
		syms=StringJoin[name,#]&/@{"PosX","PosY","PosZ"}//ToExpression;
		Table[
			Subscript[h, syms[[i]]]=p[[i]];
			Subscript[Jh, syms[[i]]]=J[[i]];
			Subscript[dJh, syms[[i]]]=\!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]
\*SubscriptBox[\(Jh\), \(syms[\([i]\)]\)]\);
			,
			{i,3}
		];

		Subscript[J\[Omega], name<>"_body"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[dQe], 1}\)]\(Subscript[\[Omega], \ name <> "\<_body\>"]\)\);
		Subscript[dJ\[Omega], name<>"_body"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[J\[Omega], \ name <> "\<_body\>"]\)\);
		Subscript[J\[Omega], name<>"_world"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[dQe], 1}\)]\(Subscript[\[Omega], \ name <> "\<_world\>"]\)\);
		Subscript[dJ\[Omega], name<>"_world"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[J\[Omega], \ name <> "\<_world\>"]\)\);
		,
		{i,nStart,ndof}
	];
];


(* ::Subsection:: *)
(*For all Points of Interest*)


poi=config["points of interest"];


Block[
	{name,lambda,offset,p,\[ScriptCapitalR],\[ScriptCapitalR]0,\[ScriptCapitalR]w,\[Omega],syms,roll,pitch,yaw,h6dof,Jh6dof,thetaX,thetaZ,thetaY},
	Table[
		name=pos["name"];
		lambda=(pos["lambda"]/.dofsIndex)[[1,1]];
		(*offset=ToExpression[pos["offset"]]/.kinConsts;//N*)
		offset=ToExpression[pos["offset"]]//N;
		(* World position *)
		p=RigidPosition[Subscript[g, Subscript[sj, lambda]][\[Theta]].RPToHomogeneous[I3,offset]];
		(* Jacobian of position *)
		J=Join[\!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[Qe], 1}\)]p\)];
		(* Rotation from body frame to world frame*)
		Subscript[\[ScriptCapitalR], name] =RigidOrientation[Subscript[g, Subscript[sj, lambda]][\[Theta]].RPToHomogeneous[I3,offset]];
		(* Angular Velocity in the body frame *)
		Subscript[\[Omega], name<>"_body"] = CrossProd[Transpose[Subscript[\[ScriptCapitalR], name]].\!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[\[ScriptCapitalR], \ name]\)\)];
		(* Angular Velocity in the world frame *)
		Subscript[\[Omega], name<>"_world"] = Subscript[\[ScriptCapitalR], name].Subscript[\[Omega], name<>"_body"];

		(* Store Variables*)
		syms=StringJoin[name,#]&/@{"PosX","PosY","PosZ"}//ToExpression;
		Table[
			Subscript[h, syms[[i]]]=p[[i]];
			Subscript[Jh, syms[[i]]]=J[[i]];
			Subscript[dJh, syms[[i]]]=\!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]
\*SubscriptBox[\(Jh\), \(syms[\([i]\)]\)]\);
			,
			{i,3}
		];

		Subscript[J\[Omega], name<>"_body"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[dQe], 1}\)]\(Subscript[\[Omega], \ name <> "\<_body\>"]\)\);
		Subscript[dJ\[Omega], name<>"_body"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[J\[Omega], \ name <> "\<_body\>"]\)\);
		Subscript[J\[Omega], name<>"_world"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \({Flatten[dQe], 1}\)]\(Subscript[\[Omega], \ name <> "\<_world\>"]\)\);
		Subscript[dJ\[Omega], name<>"_world"] = \!\(
\*SubscriptBox[\(\[PartialD]\), \(t\)]\(Subscript[J\[Omega], \ name <> "\<_world\>"]\)\);
		,
		{pos,poi}
	];
];


definedPositions=Join[
	Flatten[
		Table[
			StringJoin[name,#]&/@{"PosX","PosY","PosZ"},
			{name,Join[{"Com"},(#["name"])&/@config["points of interest"]]}
		]
	]
    ,
    Flatten[
		Table[
			StringJoin[name,#]&/@{"Roll","Pitch","Yaw"},
			{name,(#["name"])&/@config["points of interest"]}
		]
	]
];
