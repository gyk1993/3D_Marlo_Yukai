function [gait] = GetGaitFromOptMat(file, varargin)
p = inputParser;
addRequired(p,'file');
addParameter(p,'Only2D',false,@islogical);
addParameter(p,'SwingLegControlTorso',false,@islogical);

parse(p, file, varargin{:});

file = p.Results.file;
Only2D = p.Results.Only2D;
SwingLegControlTorso = p.Results.SwingLegControlTorso;

%%
params = load(file);
outputs = params.outputs;

%% Defining output seletion
H0 = zeros(6, 17);
H0(1, 4) = 1;
H0(2, 7) = 0.5;
H0(2, 8) = 0.5;
H0(3, 7) = -1;
H0(3, 8) = 1;
H0(4, 11) = 1;
H0(5, 14) = 0.5;
H0(5, 15) = 0.5;
H0(6, 14) = -1;
H0(6, 15) = 1;

H0_RFB = H0;

H0_RSS = H0_RFB;
H0_RSS(2,:) = [-1, zeros(1, 16)];
H0_RSS(2, 5) = -0.5;
H0_RSS(2, 6) = -0.5;
H0_RSS(2, 7) = 0.5;
H0_RSS(2, 8) = 0.5;
if ~Only2D
    H0_RSS(1,:) = [0, -1, zeros(1, 15)];
end

H0_RDS = H0_RFB;
H0_RDS(2,:) = [-1, zeros(1, 16)];
H0_RDS(2, 5) = -0.5;
H0_RDS(2, 6) = -0.5;
H0_RDS(2, 7) = 0.5;
H0_RDS(2, 8) = 0.5;
if SwingLegControlTorso
    H0_RDS(5,:) = [-1, zeros(1, 16)];
    H0_RDS(5, 12) = -0.5;
    H0_RDS(5, 13) = -0.5;
    H0_RDS(5, 14) = 0.5;
    H0_RDS(5, 15) = 0.5;
end
if ~Only2D
    H0_RDS(1,:) = [0, -1, zeros(1, 15)];
    if SwingLegControlTorso
        H0_RDS(4,:) = [0, -1, zeros(1, 15)];
    end
end

H0_RSwS = H0_RFB;
if SwingLegControlTorso
    H0_RSwS(5,:) = [-1, zeros(1, 16)];
    H0_RSwS(5, 12) = -0.5;
    H0_RSwS(5, 13) = -0.5;
    H0_RSwS(5, 14) = 0.5;
    H0_RSwS(5, 15) = 0.5;
end
if ~Only2D
    if SwingLegControlTorso
        H0_RDS(4,:) = [0, -1, zeros(1, 15)];
    end
end

H0_LFB = H0;

H0_LSS = H0_LFB;
H0_LSS(5,:) = [-1, zeros(1, 16)];
H0_LSS(5, 12) = -0.5;
H0_LSS(5, 13) = -0.5;
H0_LSS(5, 14) = 0.5;
H0_LSS(5, 15) = 0.5;
if ~Only2D
    H0_LSS(4,:) = [0, -1, zeros(1, 15)];
end

H0_LDS = H0_LFB;
if SwingLegControlTorso
    H0_LDS(2,:) = [-1, zeros(1, 16)];
    H0_LDS(2, 5) = -0.5;
    H0_LDS(2, 6) = -0.5;
    H0_LDS(2, 7) = 0.5;
    H0_LDS(2, 8) = 0.5;
end
H0_LDS(5,:) = [-1, zeros(1, 16)];
H0_LDS(5, 12) = -0.5;
H0_LDS(5, 13) = -0.5;
H0_LDS(5, 14) = 0.5;
H0_LDS(5, 15) = 0.5;
if ~Only2D
    if SwingLegControlTorso
        H0_LDS(1,:) = [0, -1, zeros(1, 15)];
    end
    H0_LDS(4,:) = [0, -1, zeros(1, 15)];
end

H0_LSwS = H0_LFB;
if SwingLegControlTorso
    H0_LSwS(2,:) = [-1, zeros(1, 16)];
    H0_LSwS(2, 5) = -0.5;
    H0_LSwS(2, 6) = -0.5;
    H0_LSwS(2, 7) = 0.5;
    H0_LSwS(2, 8) = 0.5;
end
if ~Only2D
    if SwingLegControlTorso
        H0_LDS(1,:) = [0, -1, zeros(1, 15)];
    end
end

H0_cell = {H0_RFB, H0_RSS, H0_RDS, H0_RSwS, H0_LFB, H0_LSS, H0_LDS, H0_LSwS};

%% Constructing HAlpha

domainNum = [1, 1, 1, 1, 2, 2, 2, 2];

HAlpha_cell = {};
for i = 1:length(H0_cell)
    [q, ~] = CompliantSystem.ConvertNewSpringlessToSpringCoord(outputs{domainNum(i)}.q(:,4:end)', outputs{domainNum(i)}.dq(:,4:end)');
    yd = H0_cell{i}*q;
    
    HAlpha = [];
    for j=1:size(yd,1)
        HAlpha(j,:) = bezfit(linspace(0,1,length(outputs{domainNum(i)}.t)), yd(j,:), 5);
    end
    
    HAlpha_cell = [HAlpha_cell, HAlpha];
end

%% Decouplling Matrix
A = [1, 0, 0, 0, 0, 0;
    0, 0.5, 0.5, 0, 0, 0;
    0, -1, 1, 0, 0, 0;
    0, 0, 0, 1, 0, 0;
    0, 0, 0, 0, 0.5, 0.5;
    0, 0, 0, 0, -1, 1,];

%% Structuring and saving

gait = struct();
gait.outputs = {};

for i = 1:length(HAlpha_cell)
    gait.outputs{i}.t = 0.4;
    gait.outputs{i}.HAlpha = HAlpha_cell{i};
    gait.outputs{i}.H0 = H0_cell{i};
    gait.outputs{i}.A = A;
end

gait.domainNames = {'RFB','RSS','RDS','RSwS','LFB','LSS','LDS','LSwS'};

end
