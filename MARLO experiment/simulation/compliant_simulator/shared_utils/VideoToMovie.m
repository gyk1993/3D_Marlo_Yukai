function M = VideoToMovie(V,I,Crop,Decimation)
    % VideoToMovie reads in frame data, optionally cropping and decimating
    
    nFrames = V.NumberOfFrames;
    vidHeight = V.Height;
    vidWidth = V.Width;
    
    if nargin<2 || isempty(I)
        I = 1:nFrames;
    end
    if nargin<3 || isempty(Crop)
        Crop = [1 vidWidth 1 vidHeight];
    elseif isscalar(Crop)
        pct = max(0.01, min(Crop, 1)); % saturate cropping percentage
        w = round(vidWidth*pct);
        h = round(vidHeight*pct);
        LowerLeft = max(1,[ceil((vidWidth-w)/2) ceil((vidHeight-h)/2)]);
        Crop = [LowerLeft(1) LowerLeft(1)+w-1 LowerLeft(2) LowerLeft(2)+h-1];
    end
    if nargin<4 || isempty(Decimation)
        Decimation = 1;
    end
    nFrames   = length(I);
    vidWidth  = floor((Crop(2)-Crop(1)+1)/Decimation);
    vidHeight = floor((Crop(4)-Crop(3)+1)/Decimation);
    
    % Preallocate movie structure.
    M(1:nFrames) = ...
        struct('cdata', zeros(vidHeight, vidWidth, 3, 'uint8'),...
        'colormap', []);
    
    % Read one frame at a time.
    idxW = Crop(1):Decimation:Crop(2);
    idxH = Crop(3):Decimation:Crop(4);
    
    for k = 1 : nFrames
        F  = read(V, I(k));
        M(k).cdata = F(idxH, idxW, :);
    end
    
    % Play
    if nargout==0
        PlayMovie(M, V. FrameRate);
    end
end
