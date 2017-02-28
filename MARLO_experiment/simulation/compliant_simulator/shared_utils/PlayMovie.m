function PlayMovie(M,FrameRate)
    
    if isa(M,'VideoReader')
        FrameRate = M.FrameRate;
        M = VideoToMovie(M);
    elseif nargin<2
        FrameRate = 15;
    end
    while (FrameRate>=30 && length(M)>10)
        M = M(1:2:end);
        FrameRate = FrameRate/2;
    end
        
    % Size a figure based on the video's width and height.
    vidWidth = size(M(1).cdata,2);
    vidHeight = size(M(1).cdata,1);
    
    hf = figure;
    set(hf, 'MenuBar','none','Units','pixels','Position', [150 150 vidWidth vidHeight])
    
    % Play back the movie once at the video's frame rate.
    movie(hf, M, 1, FrameRate)
end
