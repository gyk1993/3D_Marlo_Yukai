(* ::Package:: *)

(* ::Title:: *)
(*Convert URDF to YAML Model File*)


ClearAll;


(* ::Section:: *)
(*Initialization*)


SetDirectory[NotebookDirectory[]];
UtilsPath=FileNameJoin[{Directory[],"utils"}]
$Path=DeleteDuplicates[Append[$Path,UtilsPath]];
Needs["SnakeYaml`"];
Needs["ExtraUtil`"];
Needs["Units`"];
YamlInit[];


(*Coordinate transformation*)
Rx[q_]:={{1,0,0},{0,Cos[q],-Sin[q]},{0,Sin[q],Cos[q]}};
Ry[q_]:={{Cos[q],0,Sin[q]},{0,1,0},{-Sin[q],0,Cos[q]}};
Rz[q_]:={{Cos[q],-Sin[q],0},{Sin[q],Cos[q],0},{0,0,1}};


I3=IdentityMatrix[3];
Z3=ConstantArray[0,{3,3}];


(* ::Section:: *)
(*Load Configuration Settings*)


SettingsFile=FileNameJoin[{"settings.yaml"}];
settings=Apply[Association,Association@SnakeYaml`YamlReadFile[SettingsFile],{2}];
ConfigFile=FileNameJoin[{settings["config directory"]}];
config=Apply[Association,Association@SnakeYaml`YamlReadFile[ConfigFile],{2}];


(* ::Section:: *)
(*Load URDF*)


XMLFileName=FileNameJoin[{config["urdf"]}];
RobotModel=Import[XMLFileName,"XML"];
RobotLinks=Cases[RobotModel,XMLElement["link",_,_],Infinity];
RobotJoints=Cases[RobotModel,XMLElement["joint",{"name"->_,"type"->_},_],Infinity];


(* ::Section:: *)
(*Base Configuration*)


modelType=config["model type"]; (*spatial / planar*)
modelName=config["model name"];
If[StringMatchQ[modelType,"planar"],
	nBase=3;
	,
	nBase=6;
];
nRobot=First@Dimensions[RobotJoints];
nDof = nBase+nRobot;
baseLinkName = config["base link name"];


If[nBase == 3,
	BaseName={{"BasePosX"},{"BasePosZ"},{"BaseRotY"}};
	BaseAxis={{1,0,0},{0,0,1},{0,1,0}};
	BaseType={"prismatic","prismatic","revolute"};
	(*!!!!Please redefine the motion range for base coordinate in the optimization manually!!!!*)
	BaseJointLimits={{-1,1},{-1,1},{-Pi/2,Pi/2}}//N;
	BaseVelocityLimits=2;
	,
	BaseName={{"BasePosX"},{"BasePosY"},{"BasePosZ"},{"BaseRotX"},{"BaseRotY"},{"BaseRotZ"}};
	BaseAxis={{1,0,0},{0,1,0},{0,0,1},{1,0,0},{0,1,0},{0,0,1}};
	BaseType={"prismatic","prismatic","prismatic","revolute","revolute","revolute"};
	(*!!!!Please redefine the motion range for base coordinate in the optimization manually!!!!*)
	BaseJointLimits={{-1,1},{-1,1},{0,1.5},{-Pi/4,Pi/4},{-Pi/2,Pi/2},{-Pi/2,Pi/2}}//N;
	BaseVelocityLimits=2;
];


BaseJoints=Table[
	Module[{name,type,axis,limit,velocity,parent,child},
		name=First@BaseName[[i]];
		type=BaseType[[i]];
		axis=BaseAxis[[i]];
		limit=BaseJointLimits[[i]];
		velocity=BaseVelocityLimits;
		If[i==1,parent="Origin",parent=BaseName[[i-1,1]]];
		If[i==nBase,child=baseLinkName,child=BaseName[[i,1]]];
		XMLElement["joint",{"name"->name,"type"->type},
			{XMLElement["origin",{"rpy"->"0 0 0","xyz"->"0.0 0.0 0.0"},{}],
			 XMLElement["parent",{"link"->parent},{}],
			 XMLElement["child",{"link"->child},{}],
			 XMLElement["axis",{"xyz"->ToString[axis[[1]]]<>" "<>ToString[axis[[2]]]<>" "<>ToString[axis[[3]]]},{}],
			 XMLElement["limit",{"effort"->"0.0","lower"->ToString[limit[[1]]],"upper"->ToString[limit[[2]]],"velocity"->ToString[velocity]},{}]}]
	]
	,
	{i,1,nBase}
];


BaseLinks=Table[
	Module[{name},
		name=BaseName[[i,1]];
		XMLElement["link",{"name"->name},
			{XMLElement["inertial",{},
				{XMLElement["origin",{"rpy"->"0 0 0","xyz"->"0.0 0.0 0.0"},{}],
				 XMLElement["mass",{"value"->"0.0"},{}],
				 XMLElement["inertia",{"ixx"->"0.0","ixy"->"0.0","ixz"->"0.0","iyy"->"0.0","iyz"->"0.0","izz"->"0.0"},{}]}]}]
	]
	,
	{i,1,nBase-1}
];


(* ::Section:: *)
(*Extended Configurations*)


Str2Num[s_String]:=Read[StringToStream[s],Number];
Str2Num[sl_?ListQ]:=Map[Read[StringToStream[#],Number]&,Flatten@sl];


jointTransform[XMLElement["joint", tag_, children_]] :=  
  Association@Join[Map[Association[#]&,tag],Map[jointTransform[#]&,children]];

jointTransform[XMLElement["origin", tag_, {}]] :=  
  <|"origin"-> Map[Str2Num[#]&,Map[StringSplit[#]&,Association[tag]]]|>;
jointTransform[XMLElement["parent", tag_, {}]] :=  
  <|"parent"-> "link"/.tag|>;
jointTransform[XMLElement["child", tag_, {}]] :=  
  <|"child"-> "link"/.tag|>;
jointTransform[XMLElement["axis", tag_, {}]] :=  
  <|"axis"-> "xyz"/.Map[Str2Num[#]&,Map[StringSplit[#]&,Association[tag]]]|>;
jointTransform[XMLElement["limit", tag_, {}]] :=  
  <|"limit"-> Map[Str2Num[#]&,Association[tag]]|>;


linkTransform[XMLElement["link",tag_,children_]]:=
	Association@Join[Map[Association[#]&,tag],Map[linkTransform[#]&,children]];

linkTransform[XMLElement["visual",_,_]]:={};
linkTransform[XMLElement["collision",_,_]]:={};
linkTransform[XMLElement["inertial",_,children_]]:=
	Map[linkTransform[#]&,children];
linkTransform[XMLElement["origin", tag_, {}]] :=  
  <|"origin"-> Map[Str2Num[#]&,Map[StringSplit[#]&,Association[tag]]]|>;
linkTransform[XMLElement["mass", tag_, {}]] :=  
  <|"mass"-> "value"/.tag|>;
linkTransform[XMLElement["inertia", tag_, {}]] :=  
  <|"inertia"-> 
	{{"ixx","ixy","ixz"},
	 {"ixy","iyy","iyz"},
	 {"ixz","iyz","izz"}}
	/.Map[Str2Num[#]&,Association[tag]]|>;
	


ExJoints=Map[jointTransform[#]&,Join[BaseJoints,RobotJoints]];
ExLinks=Map[linkTransform[#]&,Join[BaseLinks,RobotLinks]];


ExLinkName=Map[#["name"]&,ExLinks];
ExJointName=Map[#["name"]&,ExJoints];
ExChildLinkName=Join[{"Origin"},Map[#["child"]&,ExJoints]];


(*ExJointNameFull=
	StringReplace[StringReplace
		[ExJointName,{"B"->"Base",StartOfString~~"R"-> "Right",
		 StartOfString~~"L"-> "Left","R"~~EndOfString-> "Roll",
		 "P"~~EndOfString-> "Pitch","Y"-> "Yaw","R"->"Rot",
		 "P"-> "Pos" ,"S"-> "Shoulder","E"->"Elbow","W"-> "Wrist",
		 "F"->"Finger","H"-> "Hip","K"->"Knee","A"->"Ankle",
		 "TS"->"Torso","NK"->"Neck"}],
	{"BasePosYaw"->"BasePosY","BaseRotYaw"->"BaseRotY"}];*)


FullNameReplaceRule={"_"-> ""};


SimpleNameReplaceRule={};


ExJointNameFull=StringReplace[ExJointName,FullNameReplaceRule];
ExJointNameSimple=StringReplace[ExJointNameFull,SimpleNameReplaceRule];



ExJointNameFull //MatrixForm


ExJointNameSimple


KinTree=Map[{#["name"],#["type"],#["axis"],#["parent"],#["child"]}&,ExJoints];
Grid[Join[{{"Joint Name","Joint Type","Joint Axis", "Parent Link", "Child Link"}},KinTree],Dividers->{{False,True},{False,True}}]


(*
GetJointName[joint_]:="name"/.joint[[2]];
GetJointType[joint_]:="type"/.joint[[2]];
GetAxisVector[axis_]:=ToExpression[StringSplit["xyz"/.axis[[2]]]];

GetChildLink[joint_,ExLinks_]:=
	Module[{link,ExLinkNames},
		link="link"/.joint[[3,3]];
		ExLinkNames=Map["name"/.#[[2]]&,ExLinks];
		ExLinks[[First[Position[StringMatchQ[ExLinkName,"Body_TSY"],True]]]]
	];
*)
GetJointAxis[joint_]:=
	Module[{type,axis},
		type=joint["type"];
		axis=joint["axis"];
		If[StringMatchQ[type,"prismatic"],
			Join[{0,0,0},axis],
			Join[axis,{0,0,0}]
		]
	];
GetLinkInertia[link_]:=
	Module[{\[Phi],\[Theta],\[Psi],inertia,R},
		{\[Phi],\[Theta],\[Psi]}=link["origin"]["rpy"];
		inertia=link["inertia"];
		R=Rz[\[Psi]].Ry[\[Theta]].Rx[\[Phi]];
		R\[Transpose].inertia.R
	];


(* ::Section:: *)
(*Motor Inertias and Gear Ratios*)


actuators = config["actuated joints"];
actuatorList = {};
Block[
	{joint, inertia, gearRatio},
	Table[
		joint=actuator["joint"];
		inertia=actuator["intertia"];
		actuatorList = Join[actuatorList,{actuator}];
		,
		{actuator,actuators}
	];
];
actuatorList

GetMotorInertia[jointName_]:=
	Module[{location, actuator, inertia},
		location = Position[actuatorList,jointName];
		If[location == {},
			inertia = 0;
		,
			actuator = actuatorList[[location[[1,1]]]];
			inertia = actuator["inertia"];
		];
		inertia
	];

GetMotorGearRatio[jointName_]:=
	Module[{location, actuator, gearRatio},
		location = Position[actuatorList,jointName];
		If[location == {},
			gearRatio = 1;
		,
			actuator = actuatorList[[location[[1,1]]]];
			gearRatio = actuator["gearRatio"];
		];
		gearRatio
	];


(* ::Section:: *)
(*Create Kinematic Tree Table*)


Block[{joint,link,origin,\[Phi],\[Theta],\[Psi],limit},
	ExDofs=Table[
		joint=ExJoints[[i]];
		link=First@ExLinks[[First[Position[StringMatchQ[ExLinkName,joint["child"]],True]]]];
		origin=joint["origin"];
		limit =joint["limit"];
		{\[Phi],\[Theta],\[Psi]}=origin["rpy"];	
		{
			"name"-> {ExJointNameFull[[i]],ExJointNameSimple[[i]]},
			"axis"-> GetJointAxis[joint],
			"type"-> joint["type"],
			"mass"-> CRoundEx[Str2Num[link["mass"]]]//N,
			"com"-> CRoundEx[link["origin"]["xyz"]]//N,
			"inertia"-> CRoundEx[GetLinkInertia[link]]//N,
			"E"-> CRoundEx[Rz[\[Psi]].Ry[\[Theta]].Rx[\[Phi]]]//N, (* NOT THE SAME CONVENTION AS USED LATER *)
			"r"-> CRoundEx[origin["xyz"]]//N,
			"lambda"-> First@First@Position[StringMatchQ[ExChildLinkName,joint["parent"]],True]-1,
			"limit"-> {{
				"min"-> CRoundEx[limit["lower"]]//N,
				"max"-> CRoundEx[limit["upper"]]//N
				}},
			"actuator"-> {{
				"inertia"-> GetMotorInertia[ExJointNameFull[[i]]],
				"type"-> If[limit["effort"]==0.0,"base","rotor"],
				"maxTorque"-> CRoundEx[limit["effort"]]//N,
				"maxVelocity"-> CRoundEx[limit["velocity"]]//N,
				"ratio"-> GetMotorGearRatio[ExJointNameFull[[i]]]
			}}		
		},
		{i,1,nDof}
	];
];


Block[{joint,link,origin,\[Phi],\[Theta],\[Psi],limit},
	ExDofsSimple=Table[
		joint=ExJoints[[i]];
		link=First@ExLinks[[First[Position[StringMatchQ[ExLinkName,joint["child"]],True]]]];
		origin=joint["origin"];
		limit =joint["limit"];
		{\[Phi],\[Theta],\[Psi]}=origin["rpy"];	
		{
			"name"-> {ExJointNameFull[[i]]},
			"axis"-> GetJointAxis[joint],
			"type"-> joint["type"],
            "parent"-> joint["parent"],
            "child"->joint["child"]	
		},
		{i,1,nDof}
	];
];





(* ::Section:: *)
(*Others*)


(*posStruct=Block[{dof,joint},
Join[Table[
	joint=ExJoints[[i]];
	{
	"name"-> ExJointNameFull[[i]],
	"lambda"-> First@First@Position[StringMatchQ[ExChildLinkName,joint["child"]],True]-1,
	"offset"-> {0,0,0}
	}
	,
	{i,6,17}
],
{{"name"->"RightHeel","lambda"->16,"offset"->{-0.00325113480269273, 0.000456917198900064, -0.0307839394944265}},
{"name"->"RightSole","lambda"->16,"offset"->{0.0764645991126832, -0.0107463985844791, -0.0552839394944273}}},
Table[
	joint=ExJoints[[i]];
	{
	"name"-> ExJointNameFull[[i]],
	"lambda"-> First@First@Position[StringMatchQ[ExChildLinkName,joint["child"]],True]-1,
	"offset"-> {0,0,0}
	}
	,
	{i,18,24}
],
{{"name"->"LeftHeel","lambda"-> 23,"offset"->{-0.00325113480269262, -0.000456917198900397, -0.0307839394944245}},
{"name"->"LeftSole","lambda"->23,"offset"->{0.0764645991126817, 0.0107463985844797, -0.0552839394944271}}}]]*)


posStruct//MatrixForm


(* ::Section:: *)
(*Export*)


yamlStruct={
	"type"-> modelType,
	"nDoF"-> nDof,
	"nBase"-> nBase,
	"name"-> modelName,
	"base"-> basePosition,
	"dofs"-> ExDofs,
	"positions"-> posStruct
};



EnsureDirectoryExists[FileNameJoin[{config["ExportPath"]}]]
SetDirectory[NotebookDirectory[]];
SetDirectory[FileNameJoin[{config["ExportPath"]}]];
YamlWriteFile[yamlStruct,FileNameJoin[{"generated_system.yaml"}]];









