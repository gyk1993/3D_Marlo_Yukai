# Model-Generator
This repository is used to generate the equations of motion and necessary code for simulation and optimization of bipeds and their controllers. Included is Mathematica code to generate the dynamics and kinematics representations of a robot, and Matlab code to generate code for holonomic constraints and optmization constraints used by IPOPT.

## Required Resources:
* Use Mathematica 10+
* Use MATLAB 2015b+
* Have Eigen installed (can be downloaded from [here](http://eigen.tuxfamily.org/))
* Install JSONlab toolbox into Matlab (can be obtained [here](http://www.mathworks.com/matlabcentral/fileexchange/33381-jsonlab--a-toolbox-to-encode-decode-json-files))

## Recommended:
* Setup Matlab to use [MinGW](http://www.mathworks.com/help/matlab/matlab_external/install-mingw-support-package.html) if using Windows. We have noticed that mexing was faster using MinGW than Visual Studio for large models in some cases.
