function filename = anim(fanim, T, X, varargin)

    % parse inputs (hfig is an optional first argument)
    Options = parseOptions(varargin{:});

    % initialize
    ReplayOptions = Options;
    ReplayOptions.MakeVideo = false;
    figure(gcf); clf;
    scrsz = get(0, 'ScreenSize');
    set(gcf, 'Units', 'pixels', 'Position', [(scrsz(3:4)-Options.FrameSize)/2+scrsz(1:2)-1 Options.FrameSize]);
    subplot('Position',[0.05    0.15    0.90    0.75], 'Box', 'on');
    htitle  = title(sprintf('T = %0.1f',T(1)));
    uicontrol('Style', 'pushbutton', 'String', 'Replay', 'Tag', 'Replay',...
        'Units', 'normalized', 'Position', [0.45 0.02 0.1 0.06],...
        'Callback', @(obj,evt) play(fanim, T, X, htitle, ReplayOptions));

    play(fanim, T, X, htitle, Options);
    filename = Options.AVIFile;
end

function play(fanim, T, X, htitle, Options)

    cla;
    h = fanim([], X(1,:)');

    % Setup VideoWriter
    if Options.MakeVideo
        mov = VideoWriter(Options.AVIFile);
        mov.FrameRate = Options.FrameRate;
        open(mov);
    end

    try
        % simulate
        incomplete = 1;
        nframes = 0;
        tsim = tic;
        l = 1;
        while incomplete
            fanim(h, X(l,:)');
            if ishandle(htitle)
                % The drawing function could delete the title; if it does,
                % skip this step to avoid an error
                set(htitle, 'String', sprintf('T = %0.1f',T(l)));
            end
            drawnow;

            if Options.MakeVideo
                F = getframe(gcf);
                writeVideo(mov,F);
                
                % next frame index
                incomplete = l<length(T);
                l = l+1;
                
            else
                % Compute average walltime per frame
                t = toc(tsim) * Options.Speed;
                nframes = nframes + 1;
                spf = t/nframes;
                
                % Compute next frame based on the predicted time to draw 1 frame
                [~, lnext] = min(abs((T-T(1)) - (t+spf)));
                incomplete = lnext>l || l<length(T);
                l = lnext;
                
                % Delay (if needed)
                pause((T(l)-T(1)) - (t+spf));
            end
        end
    catch err
        err.getReport();
    end
    
    % Close VideoWriter
    if Options.MakeVideo
        close(mov);
    end
end


function Options = parseOptions(varargin)
    p = inputParser();
    p.FunctionName = mfilename;
    addParamValue(p, 'MakeVideo', false);
    addParamValue(p, 'FrameRate', 30);
    addParamValue(p, 'Speed', 1);
    addParamValue(p, 'FrameSize', [1280 720]);
    addParamValue(p, 'FilePrefix', 'Animation');
    p.parse(varargin{:});
    Options = p.Results;
    
    if Options.MakeVideo
        try
            [~,~,AVIDir] = getlogdir();
        catch
            AVIDir = pwd;
        end
        AVIDir = fullfile(AVIDir, 'animations');
        if ~exist(AVIDir, 'dir')
            status = mkdir(AVIDir);
            if (status~=1)
                AVIDir = pwd;
            end
        end

        speedstr = regexprep(num2str(Options.Speed), '\.', '_');
        AVIFile = sprintf('%s-%sx-%dfps-%s.avi', Options.FilePrefix, speedstr, Options.FrameRate, datestr(now,'ddmmmyy_HHMMSS'));
        AVIFile = fullfile(AVIDir,AVIFile);
        Options.AVIFile = AVIFile;
        
        if ispc
            fprintf('Creating <a href="matlab:winopen(''%s'');">%s</a>\n',AVIFile,AVIFile);
            fprintf('Open folder <a href="matlab:winopen(''%s'');">%s</a>\n',AVIDir,AVIDir);
        else
            fprintf('Creating <a href="matlab:system(''totem %s'');">%s</a>\n',AVIFile,AVIFile);
            fprintf('Open folder <a href="matlab:system(''env --unset=LD_LIBRARY_PATH nautilus %s'');">%s</a>\n',AVIDir,AVIDir);
        end
        
    else
        Options.AVIFile = '';
    end
end

