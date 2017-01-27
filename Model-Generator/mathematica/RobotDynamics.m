(* ::Package:: *)

(* ::Title:: *)
(*Robot Dynamics Expression*)


(*This package build symbolic expressions of robot dynamics*)
(*The following functions will be exported:
  @Inertia Matrix - De
  @Corilios Matrix - Ce
  @Gravity Vector - Ge
  @Spring Force Vector - Fs
  @Friction Force Vector - Fr
  @Potential Energy - Ve
  @Motor Matrix Thingy - Be
*)


(* ::Section:: *)
(*Generate Symbolic Expressions*)


(* ::Subsection:: *)
(*Mass & Inertia*)


MM=Block[
	{dof,mass,inertia},
	Table[
		mass=dof["mass"];
		inertia=dof["inertia"];
		BlockDiagonalMatrix[{I3*mass,inertia}]
		,
		{dof,dofs}
	]
];
masses=Block[{dof},Table[dof["mass"],{dof,dofs}]];
MMBoom=BlockDiagonalMatrix[{I3*boom["mass"],Z3}];


(* ::Subsection:: *)
(*Potential Energy*)


grav = 9.81;
Ve={Sum[grav*masses[[i]]*Subscript[p, Subscript[sl, i]][\[Theta]][[3]],{i,ndof}]};
\[ScriptCapitalG]e=Vec[D[Ve,{Flatten[Qe],1}]];


(* ::Subsection:: *)
(*Inertia Matrix*)


\[ScriptCapitalD]eBody=Sum[Subscript[Je, Subscript[sl, i]]\[Transpose].MM[[i]].Subscript[Je, Subscript[sl, i]],{i,ndof}];
\[ScriptCapitalD]eBoom=Subscript[Je, b]\[Transpose].MMBoom.Subscript[Je, b];

\[ScriptCapitalD]eMotor=ConstantArray[0,{ndof,ndof}];
Block[{actuator},
	Table[
		actuator=Association@dofs[[i]]["actuator"];
		\[ScriptCapitalD]eMotor[[i,i]]=actuator["inertia"];(*reflected inertia on joint side*)
		,
		{i,ndof}
	];
];
(* For 3D gait, remove Boom dynamics*)
(*\[ScriptCapitalD]e=\[ScriptCapitalD]eBody + \[ScriptCapitalD]eMotor;*)
\[ScriptCapitalD]e=\[ScriptCapitalD]eBody + \[ScriptCapitalD]eMotor;


(* ::Subsection:: *)
(*Coriolis Matrix*)


\[ScriptCapitalC]eBody=InertiaToCoriolis[\[ScriptCapitalD]eBody,Flatten[Qe],Flatten[dQe]];
(*\[ScriptCapitalC]eBoom=InertiaToCoriolis[\[ScriptCapitalD]eBoom,Flatten[Qe],Flatten[dQe]];*)

\[ScriptCapitalC]e=\[ScriptCapitalC]eBody;


Block[{qIndex, qaIndices, actuatedJoints, actuator},
	actuatedJoints = config["actuated joints"];
	qaIndices = Flatten[actuatedJoints/.dofsIndex];
];


(* ::Subsection:: *)
(*\[ScriptCapitalB]e Matrix*)


Block[{actuatedJoints, qaIndices, Be, i},
	actuatedJoints = config["actuated joints"];
	qaIndices = Flatten[actuatedJoints/.dofsIndex];
	nAct = Length[qaIndices];
	Be=ConstantArray[0,{ndof,nAct}];
	Table[
		qIndex = qaIndices[[i]]["joint"][[1]];
		actuator=Association@dofs[[qIndex]]["actuator"];
		gearRatio = actuator["ratio"];
		Be[[qIndex,i]] = gearRatio;
		,
		{i,nAct}
	];
	\[ScriptCapitalB]e=Be;
	Print[Be];
];
