(* ::Package:: *)

(* ::Title:: *)
(*Main File for Simulation Expression*)


(* ::Section:: *)
(*Initialization*)


SetDirectory[NotebookDirectory[]]


(* Generating the YAML file from the URDF *)
<<ConvertUrdf2Yaml`;//AbsoluteTiming


ClearAll;


SetDirectory[NotebookDirectory[]]
UtilsPath=FileNameJoin[{NotebookDirectory[],"utils"}]
$Path=DeleteDuplicates[Append[$Path,UtilsPath]];


Needs["Units`"];
Needs["RobotLinks`"];
Needs["ExtraUtil`"];
Needs["ToCpp`"];
Needs["ToMatlab`"];
Needs["SnakeYaml`"];


On[Assert];


YamlInit[];


(* ::Section:: *)
(*Load Behavior Configuration*)


SettingsFile=FileNameJoin[{"settings.yaml"}];
settings=Apply[Association,Association@SnakeYaml`YamlReadFile[SettingsFile],{2}];
ConfigFile=FileNameJoin[{settings["config directory"]}];
config=Apply[Association,Association@SnakeYaml`YamlReadFile[ConfigFile],{2}];

ModelConfigFile=FileNameJoin[{config["ExportPath"],"generated_system.yaml"}];


(* exported files for simulation path *)
$SimExportPath=FileNameJoin[{config["ExportPath"],"sim"}];
$OptExportPath=FileNameJoin[{config["ExportPath"],"opt"}];

EnsureDirectoryExists[$SimExportPath];
EnsureDirectoryExists[$OptExportPath];
EnsureDirectoryExists[FileNameJoin[{$SimExportPath,"m"}]];


(* ::Section:: *)
(*Simulation*)


(* ::Subsubsection:: *)
(*Generate Model*)


(*Execute this package before any other sub packages.*)
(*This package loads robot model configuration and compute forward kinematics*)
<<RobotModel`;//AbsoluteTiming


(*This package build expressions for kinematics elements, *)
(*e.g. positions, constraints, jacobians *)
<<RobotKinematics`;//AbsoluteTiming


(*This package build symbolic expressions of robot dynamics*)
<<RobotDynamics`;//AbsoluteTiming


(* ::Subsection:: *)
(*Export Model*)


<<ExportSimulation`;//AbsoluteTiming


(* ::Section:: *)
(*Optimization*)


(* ::Subsection:: *)
(*Generate Dynamics*)


\[ScriptCapitalU]=Vec[Table[\[ScriptU][i],{i,nAct}]];
naturalDynamics=Table[\[ScriptCapitalD]e[[i,;;]].ddQe+\[ScriptCapitalC]e[[i,;;]].dQe+\[ScriptCapitalG]e[[i,1]]-\[ScriptCapitalB]e[[i,;;]].\[ScriptCapitalU],{i,ndof}];//AbsoluteTiming


Qn=Qe/.Subscript[x_,y_]:>Subscript[x,{y,n}];
dQn=D[Qn,t];
ddQn=D[dQn,t];

impactDynamics=Table[\[ScriptCapitalD]e[[i,;;]].(dQn - dQe),{i,ndof}];//AbsoluteTiming


(* ::Subsection:: *)
(*Export Dynamics*)


<<ExportOptimization`;//AbsoluteTiming


Print[Qe];
