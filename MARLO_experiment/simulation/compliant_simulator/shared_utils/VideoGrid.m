function [IMG] = VideoGrid(V, GridSize, SampleRate, T0, Crop, Decimation)
    
    if nargin<3 || isempty(SampleRate)
        SampleRate = V.FrameRate;
    end
    if nargin<4 || isempty(T0)
        T0 = 0;
    end
    if nargin<5 || isempty(Crop)
        Crop = [];
    end
    if nargin<6 || isempty(Decimation)
        Decimation = 1;
    end
    
    I = round(T0*V.FrameRate+1 + V.FrameRate/SampleRate*(0:prod(GridSize)));
    M = VideoToMovie(V, I, Crop, Decimation);
    vidSize = [size(M(1).cdata, 2) size(M(1).cdata, 1)];
    
    nRows = GridSize(1);
    nCols = GridSize(2);
    
    Gap = round(vidSize(1)/20);
    IMG = ones(nRows*vidSize(2)+(nRows-1)*Gap, nCols*vidSize(1)+(nCols-1)*Gap, 3, 'uint8');
    IMG = IMG*255; % set padding color to white
    for k=1:nRows
        for l=1:nCols
            IMG((k-1)*(vidSize(2)+Gap) + (1:vidSize(2)), (l-1)*(vidSize(1)+Gap) + (1:vidSize(1)), :) = M((k-1)*nCols+l).cdata;
        end
    end
end


% if nargin<2 || isempty(GridSize)
%     % Compare the figure and frame sizes to see how to best layout the
%     % grid. sizeRatio>1 means that we should try to put more columns than
%     % rows.
%
%     oldUnits = get(gcf,'Units');
%     set(gcf,'Units','pixels');
%     figPos = get(gcf,'Position');
%     figSize = figPos(3:4);
%     set(gcf,'Units',oldUnits);
%
%     N = length(M);
%     vidSize = [size(M(1).cdata, 2) size(M(1).cdata, 1)];
%     sizeRatio = figSize(1)*vidSize(2)/vidSize(1)/figSize(2);
%     nRows = floor(sqrt(N)*sizeRatio)+1;
%     nCols = ceil(N/nRows);
%     nRows = ceil(N/nCols);
% else
%     nRows = GridSize(1);
%     nCols = GridSize(2);
% end

% % Create grid of axes
% H = subplot1(nRows,nCols,'XTickL','None','YTickL','none','Gap',[0.00 0.00]);
%
% % Plot frames
% HT = H'; % simplifies indexing
% for k=1:N
%     axes(HT(k));
%     imshow(M(k).cdata);
%
%     %title(HT(k),sprintf('t=%0.2f',Tm(k)));
%     %titPos = get(get(HT(k),'Title'), 'Position');
%     %set(get(HT(k),'Title'), 'Position', titPos + [-0.05*vidSize(1) 0 0]);
% end
% set(HT(k+1:numel(HT)), 'Visible', 'off')
% IMG = [];
