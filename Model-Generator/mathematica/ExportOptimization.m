(* ::Package:: *)

(* ::Title:: *)
(*Export Optimization*)


(* ::Section:: *)
(*Configure Export Path*)


SetOptions[CseWriteCpp,
	ExportDirectory->$OptExportPath
];


(* ::Section:: *)
(*Export Natural Dynamics*)


Table[ExportWithGradient["naturalDynamics"<>ToString[i],naturalDynamics[[i]],{Qe,dQe,ddQe,\[ScriptCapitalU]}],{i,ndof}];//AbsoluteTiming


(* ::Section:: *)
(*Export Impact Dynamics*)


Table[ExportWithGradient["impactDynamics"<>ToString[i],impactDynamics[[i]],{Qe,dQe,dQn}],{i,ndof}];//AbsoluteTiming


(* ::Section:: *)
(*Export Holonomic Constraints*)


poi=config["points of interest"];


If[StringMatchQ[model["type"],"planar"],
	Block[
		{name, hdesired, holConstrPosition, holConstrVelocity, holConstrAcceleration, Fe, Fimp},
		Table[
			name=pos["name"];
			syms=StringJoin[name,#]&/@{"PosX","PosZ"}//ToExpression;
			
			Subscript[h, ToExpression[name]] = Table[Subscript[h, syms[[j]]],{j,2}];
			Subscript[Jh, ToExpression[name]] = Table[Subscript[Jh, syms[[j]]],{j,2}];
			Subscript[dJh, ToExpression[name]] = Table[Subscript[dJh, syms[[j]]],{j,2}];

			(* Position Level *)
			(* c - c_des = 0 *)			
			hdesired = Table[hd[i],{i,2}];
			holConstrPosition = Subscript[h, ToExpression[name]]-hdesired;
			ExportWithGradient["holConstrPosition_"<>name,holConstrPosition,{Qe,hdesired}];

			(* Velocity Level *)
			(* J(c)*dq = 0 *)			
			holConstrVelocity = Subscript[Jh, ToExpression[name]].dQe;
			ExportWithGradient["holConstrVelocity_"<>name,holConstrVelocity,{Qe,dQe}];

			(* Acceleration Level *)
			(* J(c)*ddq + dJ(c)*dq = 0 *)			
			holConstrAcceleration = Subscript[Jh, ToExpression[name]].ddQe + Subscript[dJh, ToExpression[name]].dQe;
			ExportWithGradient["holConstrAcceleration_"<>name,holConstrAcceleration,{Qe,dQe,ddQe}];

			(* Dynamics External Force due to constraint *)
			(* J'(c)*Fe *)
			Fe = Table[Fexternal[i],{i,2}];
			holConstrExternalForce = Transpose[Subscript[Jh, ToExpression[name]]].Fe;
			ExportWithGradient["holConstrExternalForce_"<>name,holConstrExternalForce,{Qe,Fe}];

			(* Impact Force due to constraint *)
			(* J'(c)*Fimp *)
			Fimp = Table[Fimpact[i],{i,2}];
			holConstrExternalForce = Transpose[Subscript[Jh, ToExpression[name]]].Fimp;
			ExportWithGradient["holConstrImpactForce_"<>name,holConstrExternalForce,{Qe,Fimp}];
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

			(* Position Level *)
			(* c - c_des = 0 *)			
			hdesired = Table[hd[i],{i,3}];
			holConstrPosition = Subscript[h, ToExpression[name]]-hdesired;
			ExportWithGradient["holConstrPosition_"<>name,holConstrPosition,{Qe,hdesired}];

			(* Velocity Level *)
			(* J(c)*dq = 0 *)			
			holConstrVelocity = Subscript[Jh, ToExpression[name]].dQe;
			ExportWithGradient["holConstrVelocity_"<>name,holConstrVelocity,{Qe,dQe}];

			(* Acceleration Level *)
			(* J(c)*ddq + dJ(c)*dq = 0 *)			
			holConstrAcceleration = Subscript[Jh, ToExpression[name]].ddQe + Subscript[dJh, ToExpression[name]].dQe;
			ExportWithGradient["holConstrAcceleration_"<>name,holConstrAcceleration,{Qe,dQe,ddQe}];

			(* Dynamics External Force due to constraint *)
			(* J'(c)*Fe *)
			Fe = Table[Fexternal[i],{i,3}];
			holConstrExternalForce = Transpose[Subscript[Jh, ToExpression[name]]].Fe;
			ExportWithGradient["holConstrExternalForce_"<>name,holConstrExternalForce,{Qe,Fe}];

			(* Impact Force due to constraint *)
			(* J'(c)*Fimp *)
			Fimp = Table[Fimpact[i],{i,3}];
			holConstrExternalForce = Transpose[Subscript[Jh, ToExpression[name]]].Fimp;
			ExportWithGradient["holConstrImpactForce_"<>name,holConstrExternalForce,{Qe,Fimp}];

			,
			{pos,poi}
		];
	];
];
