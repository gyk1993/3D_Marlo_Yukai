function gait = GetManualGait(varargin)
p = inputParser;
addParameter(p,'Only2D',false,@islogical);
addParameter(p,'SwingLegControlTorso',false,@islogical);

parse(p,varargin{:});

Only2D = p.Results.Only2D;
SwingLegControlTorso = p.Results.SwingLegControlTorso;

%% Constructing HAlpha
HAlpha = [zeros(1, 6);
    pi.*ones(1, 6);
    linspace(deg2rad(55), deg2rad(60), 6);
    zeros(1, 6);
    pi.*ones(1, 6);
    deg2rad([60, 65, 105, 105, 60, 55])];

HAlphaRFB = HAlpha;

HAlphaRSS = HAlphaRFB;
HAlphaRSS(2, :) = zeros(1, 6);

HAlphaRDS = HAlphaRFB;
HAlphaRDS(2, :) = zeros(1, 6);
if SwingLegControlTorso
    HAlphaRDS(5, :) = zeros(1, 6);
end

HAlphaRSwS = HAlphaRFB;
if SwingLegControlTorso
    HAlphaRSwS(5, :) = zeros(1, 6);
end

HAlphaLFB = HAlpha([4, 5, 6, 1, 2, 3], :);

HAlphaLSS = HAlphaLFB;
HAlphaLSS(5, :) = zeros(1, 6);

HAlphaLDS = HAlphaLFB;
HAlphaLDS(5, :) = zeros(1, 6);
if SwingLegControlTorso
    HAlphaLDS(2, :) = zeros(1, 6);
end

HAlphaLSwS = HAlphaLFB;
if SwingLegControlTorso
    HAlphaLSwS(2, :) = zeros(1, 6);
end

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

%% Decouplling Matrix
A = [1, 0, 0, 0, 0, 0;
    0, 0.5, 0.5, 0, 0, 0;
    0, -1, 1, 0, 0, 0;
    0, 0, 0, 1, 0, 0;
    0, 0, 0, 0, 0.5, 0.5;
    0, 0, 0, 0, -1, 1,];

HAlpha_cell = {HAlphaRFB, HAlphaRSS, HAlphaRDS, HAlphaRSwS, HAlphaLFB, HAlphaLSS, HAlphaLDS, HAlphaLSwS};
H0_cell = {H0_RFB, H0_RSS, H0_RDS, H0_RSwS, H0_LFB, H0_LSS, H0_LDS, H0_LSwS};

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
