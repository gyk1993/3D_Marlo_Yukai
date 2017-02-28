function Screen = getTargetScreen(tg)
    
    if nargin<1
        % If no target specified, use the default target
        tg = xpc;
    end
    
    % Update screen
    xpctargetspy();
    
    % Figure out which figure window displays the target screen
    if verLessThan('MATLAB','R2014a')
        tgfig = findall(0, 'Type', 'figure', 'Name', 'Real-Time xPC Target Spy');
    else
        tgfig = findall(0, 'Type', 'figure', 'Name', 'Simulink Real-Time Target Screen');
    end
    
    % Try to get text
    Screen.Text = getTargetText(tg, tgfig);
    
    % Get a screen shot
    Screen.Frame = getframe(tgfig);
end

function Text = getTargetText(tg, tgfig)
    % If the target is in text mode, grab the text
    % Initially it takes a while for the text display to update, so we will
    % try a few times until we get something other than a blank screen (all
    % whitespace).
    
    MaxTries = 10;
    
    if strcmpi(tg.Settings.TargetScope, 'Disabled')
        nTries = 0;
        IsWhiteSpace = true;
        while IsWhiteSpace && (nTries < MaxTries)
            pause(1); % (sec)
            hTiles = get(tgfig, 'Children');
            nTiles = length(hTiles);
            Text = cell(nTiles, 1);
            for k = 1:nTiles
                % Hack: We assume that the ordering of the Children is
                % from bottom to top.
                Text{k} = get(hTiles(nTiles + 1 - k), 'String');
            end
            nTries = nTries + 1;
            IsWhiteSpace = all(cellfun(@(s)all(isspace(s)), Text));
        end
    else
        Text = {};
    end
end
