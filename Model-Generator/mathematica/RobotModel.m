(* ::Package:: *)

(* ::Title:: *)
(*Robot Model*)


(* ::Section:: *)
(*Model Configuration*)


(*ModelConfig=robot["model"]*)


(*ModelConfigFile=FileNameJoin[{$RobotConfigPath,"model",ModelConfig}]*)
(*ModelConfigFile=FileNameJoin[{"gen/generated_system.yaml"}]*)


model=Apply[Association,Association@SnakeYaml`YamlReadFile[ModelConfigFile],{2}];


dofs=model["dofs"]//RationalizeEx;
modelType=model["type"];
modelName=model["name"];
dofsIndex=PositionIndex[dofs[[All,1,1]]];


If[StringMatchQ[model["type"],"planar"],
	nb=3,
	nb=6
];
ndof=Length[dofs];


If[StringMatchQ[model["type"],"planar"],
	Qb=Vec[{Subscript[r, x][t],Subscript[r, z][t],Subscript[\[Phi], y][t]}],
	Qb=Vec[{Subscript[r, x][t],Subscript[r, y][t],Subscript[r, z][t],Subscript[\[Phi], x][t],Subscript[\[Phi], y][t],Subscript[\[Phi], z][t]}]
];
Q=Vec[Table[Subscript[\[Theta], ToExpression[(dofs[[i]]["name"])[[2]]]][t],{i,nb+1,ndof}]];
Qe=Join[Qb,Q];


dQ=D[Q,t];
dQb=D[Qb,t];
dQe=Join[dQb,dQ];


ddQe=D[dQe,t];


\[ScriptCapitalX]=Join[Qe,dQe];
d\[ScriptCapitalX]=D[\[ScriptCapitalX],t];


qe0subs=Table[Qe[[i,1]]-> 0,{i,ndof}];
qb0subs=Table[Qb[[i,1]]-> 0,{i,nb}];
dqe0subs=Table[dQe[[i,1]]-> 0,{i,ndof}];
dqb0subs=Table[dQb[[i,1]]-> 0,{i,nb}];


I3=IdentityMatrix[3];
Z3=ConstantArray[0,{3,3}];
I4=IdentityMatrix[4];


(* ::Section:: *)
(*Robot Kinmatics*)


(* ::Text:: *)
(*Using 1-based indexing, where 0 denotes the world / root link.*)


(* ::Text:: *)
(*Using nomenclature from Murray-Li-Sastry*)
(*Note that twists are defined with respect to the world in the base configuration, not relative to its parent.*)
(*The twist then creates a transform that rotates it about the origin of the joint.*)


(* ::Item:: *)
(*"g" - Homogeneous transform*)


(* ::Item:: *)
(*"\[Xi]" - Twist*)


(* ::Item:: *)
(*"p" - Position*)


(* ::Item:: *)
(*"R" - Rotation matrix*)


(* ::Text:: *)
(*Frames*)


(* ::Item:: *)
(*"s" - base frame (world, 0)*)


(* ::Item:: *)
(*"Subscript[l, i]" - link i*)


(* ::Item:: *)
(*"\"\!\(\n\*SubscriptBox[\(j\), \(i\)]\)"" - joint i*)


(* ::Subsection:: *)
(*Base Configuration*)


(* Base *)
\[Xi][0]={0,0,0,0,0,0};
(* Relative twist *)
\[Xi][0,0]=\[Xi][0];

(* SE(3) *)
E4=RPToHomogeneous[I3,{0,0,0}];
(* g_{sj_i}:  Joint transform from i to base *)
Subscript[g, Subscript[sj, 0]][0]=Subscript[g, Subscript[sj, 0]][\[Theta]]=E4;
(* g_{sl_i}: Link i CoM transform  to base *)
Subscript[g, Subscript[sl, 0]][0]=Subscript[g, Subscript[sl, 0]][\[Theta]]=E4;


(* ::Input:: *)
(**)


(* ::Subsection:: *)
(*Forward Kinematics*)


Block[
	{name,dof,lambda,mass, inertia, com, rL, EL,type,axis,xiv,xiw,qDof},
	Table[
		dof=dofs[[i]];
		name=dof["name"];
		lambda=dof["lambda"];
		(*{name,lambda}=GetFields[dof,{"name","lambda"}];*)
		(** Kinematics **)
		(* From SVA, we're given ^{i}X_{i-1} = X(^{i}E_{i-1}, ^{i-1}r)  -  spatial transform from i-1 to i *)
		(* With this, we can put together g_{i-1,i}(0) = T(^{i-1}E_{i}, ^{i-1}r)  -  homogeneous transfrom from i to i-1 *)
		(*{type, axis, EL, rL,com} = GetFields[dof, {"type", "axis", "E", "r","com"}];*)
		type=dof["type"];
		axis=dof["axis"];
		EL=dof["E"];
		rL=dof["r"];
		com=dof["com"];

		(* i to base *)
		(*Subscript[g, Subscript[sj, i]][0]=Subscript[g, Subscript[sj, lambda]][0].RPToHomogeneous[EL\[Transpose], rL];*)
		Subscript[g, Subscript[sj, i]][0]=Subscript[g, Subscript[sj, lambda]][0].RPToHomogeneous[EL, rL];
		
		(* Relative, DH-style twists, see MLS p. 94 *)
		(* Note that the twists are in body frame, so q = 0 *)
		If[type == "prismatic",
			(* xi : (q = 0, v = xiv ) *)
			xiv = axis[[4;;6]];
			\[Xi][lambda, i] = PrismaticTwist[{0, 0, 0}, xiv];
			,
			(* revolute *)
			(* xi : (q = 0, w = xiw, v (handled by function) *)
			xiw = axis[[1;;3]];
			\[Xi][lambda, i] = RevoluteTwist[{0, 0, 0}, xiw];
		];
		(* Transform relative twist (in joint frame i) to base frame S - using adjoint transform for twists (MLS, p .55, Eq. (2.58) *)
		(* Same as spatial transform (Featherstone, p .22, Eq. (2.26) -- note that twist is (v, w) and Plucker is (w, v) *)
		(* URDF Docs say that joint axis is in joint frame, so we will use the joint's frame in S to transform twist *)
		(* See http://www.ros.org/wiki/urdf/XML/joint *)
	
		\[Xi][i] = RigidAdjoint[Subscript[g, Subscript[sj, i]][0]] . \[Xi][lambda, i];	

		(* Put com for Link L in base frame S, get trasnform g_{s,l} from L to S *)
		(* Note that this is following Featherstone's spatialv2 implementation, where each dof has a body. Stacked dofs have zero mass. *)
		Subscript[g, Subscript[sl, i]][0] = Subscript[g, Subscript[sj, i]][0] . RPToHomogeneous[I3, com];
		,
		{i,ndof}
	];
];


(* ::Subsection:: *)
(*Chains*)


Block[
	{chainDef,chainIndicesDef,i},
	chainDef[0]={};
	chainIndicesDef[0]={};
	Table[
		dof=dofs[[i]];
		lambda=dof["lambda"];
		chainDef[i]=Append[chainDef[lambda],{\[Xi][i],Qe[[i,1]]}];
		chainIndicesDef[i]=Append[chainIndicesDef[lambda],i];
		,
		{i,ndof}
	];
	chains=Table[chainDef[i],{i,ndof}];
	chainIndices=Table[chainIndicesDef[i],{i,ndof}];
];


chainIndices//MatrixForm


(* ::Input:: *)
(**)


(* ::Subsection:: *)
(*Body Jacobian*)


Block[
	{Jz,curchain,curIndices,i},
	Table[
		(* Joint Position *)
		Subscript[g, Subscript[sj, i]][\[Theta]]=ForwardKinematics[Sequence@@chains[[i]],Subscript[g, Subscript[sj, i]][0]];
		Subscript[p, Subscript[sj, i]][\[Theta]]=RigidPosition[Subscript[g, Subscript[sj, i]][\[Theta]]];
		(* Center of Mass Position *)
		Subscript[g, Subscript[sl, i]][\[Theta]]=ForwardKinematics[Sequence@@chains[[i]],Subscript[g, Subscript[sl, i]][0]];
		Subscript[p, Subscript[sl, i]][\[Theta]]=RigidPosition[Subscript[g, Subscript[sl, i]][\[Theta]]];
		(* Body Jacobian *)
		Jz=ConstantArray[0,{6,ndof}];
		curchain=chains[[i]];
		curIndices=chainIndices[[i]];
		Jz[[;;,curIndices]]=BodyJacobian[Sequence@@chains[[i]],Subscript[g, Subscript[sl, i]][0]];
		Subscript[Je, Subscript[sl, i]]=Jz;
		Jz[[;;,curIndices]]=BodyJacobian[Sequence@@chains[[i]],Subscript[g, Subscript[sj, i]][0]];
		Subscript[Je, Subscript[sj, i]] =Jz;
		(*Subscript[Je0, Subscript[sj, i]]=D[Subscript[p, Subscript[sj, i]][\[Theta]],{Flatten[Qe],1}][[{1,3}]];
		Subscript[dJe0, Subscript[sj, i]]=D[Subscript[Je0, Subscript[sj, i]],t];*)
		,
		{i,ndof}
	];
];



