function [varargout] = DecodeSwitches(LimitSwitchesEncoded, t, F0)
    % From OSU code:
    % (See atrias/software/atrias_medulla_drivers/src/LegMedulla.cpp and
    % http://code.google.com/p/atrias/wiki/LimitSwitches; note error in Leg
    % A bits 4 and 5.)
    %
    % Hip
    % 0 	Inside limit (relaxed position)
    % 1 	Outside limit (fully extended)
    %
    % Leg A
    % 0 	Negative motor limit
    % 1 	Positive motor limit
    % 2 	Negative spring deflection limit
    % 3 	Positive spring deflection limit
    % 4 	Leg extension limit
    % 5 	Leg retraction limit
    %
    % Leg B
    % 0 	Negative motor limit
    % 1 	Positive motor limit
    % 2 	Negative spring deflection limit
    % 3 	Positive spring deflection limit
    % 4 	Motor retraction limit
    
    % LimitSwitchesEncoded is an integer which encodes the state of all of the limit switches
    % The bit encoding is as follows:
    %   Right Shin (A)
    %     LSB 0:	Negative motor limit
    %         1: 	Positive motor limit
    %         2: 	Negative spring deflection limit
    %         3: 	Positive spring deflection limit
    %         4: 	Leg retraction limit
    %         5: 	Leg extension limit
    %   Right Thigh (B)
    %   	  6: 	Negative motor limit
    %   	  7:	Positive motor limit
    %   	  8:	Negative spring deflection limit
    %   	  9:	Positive spring deflection limit
    %   	 10:	Motor retraction limit
    %   Right Hip
    %   	 11:	Inside limit (relaxed position)
    %   	 12:    Outside limit (fully extended)
    %   Left Shin (A)
    %        16:	Negative motor limit
    %        17: 	Positive motor limit
    %        18: 	Negative spring deflection limit
    %        19: 	Positive spring deflection limit
    %        20: 	Leg retraction limit
    %        21: 	Leg extension limit
    %   Left Thigh (B)
    %   	 22: 	Negative motor limit
    %   	 23:	Positive motor limit
    %   	 24:	Negative spring deflection limit
    %   	 25:	Positive spring deflection limit
    %   	 26:	Motor retraction limit
    %   Left Hip
    %   	 27:	Inside limit (relaxed position)
    %   	 28:	Outside limit (fully extended)
    %
    % LimitSwitchesDec is a matrix whose ith column is the ith bit of
    % LimitSwitchesEncoded (where, using MATLAB numbering, the LSB is bit
    % 1).

    if isstruct(LimitSwitchesEncoded)
        log = LimitSwitchesEncoded;
        LimitSwitchesEncoded = log.Switches;
        t = log.t;
    end
    if nargin<3
        F0 = 100;
    end
    
    LimitSwitchesDec = bsxfun(@bitget, LimitSwitchesEncoded, [0:12 16:28]+1);
    
    if nargout>0
        varargout{1} = LimitSwitchesDec;
    else
        figure(F0); %set(gcf, 'Position', [  10          45        1900         950]);
        %if nargin<2
        %    t = (0:length(LimitSwitchesEncoded)-1)/1000;
        %end
            
        h(1) = subplot(322); plotsw(t,LimitSwitchesDec(:,1:6)); title('Right Shin'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Negative motor', 'Positive motor', 'Negative spring deflection', 'Positive spring deflection', 'Leg retraction', 'Leg extension', 'Location', 'West');
        
        h(2) = subplot(324); plotsw(t,LimitSwitchesDec(:,7:11)); title('Right Thigh'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Negative motor', 'Positive motor', 'Negative spring deflection', 'Positive spring deflection', 'Motor retraction', 'Location', 'West');
        
        h(3) = subplot(326); plotsw(t,LimitSwitchesDec(:,12:13)); title('Right Hip'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Inside', 'Outside', 'Location', 'West');
        
        h(4) = subplot(321); plotsw(t,LimitSwitchesDec(:,14:19)); title('Left Shin'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Negative motor', 'Positive motor', 'Negative spring deflection', 'Positive spring deflection', 'Leg retraction', 'Leg extension', 'Location', 'West');
        
        h(5) = subplot(323); plotsw(t,LimitSwitchesDec(:,20:24)); title('Left Thigh'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Negative motor', 'Positive motor', 'Negative spring deflection', 'Positive spring deflection', 'Motor retraction', 'Location', 'West');
        
        h(6) = subplot(325); plotsw(t,LimitSwitchesDec(:,25:26)); title('Left Hip'); set(gca, 'YLim', [-0.2 1.2]);
        legend('Inside', 'Outside', 'Location', 'West');
        
        linkaxes(h,'x');
        %longdatacursor(h);
    end
end

function plotsw(t,sw)
    if length(t)>1
        L = 50;
        
        %{
        swf = zeros(size(sw));
        swf(1,:) = sw(1,:)/L;
        
        for k=2:size(sw,1)
            swf(k,:) = max(0, min(swf(k-1,:) + 2*sw(k,:)-1, 255));
        end
        swf = swf/L;
        %}
        plot(t,sw); hold on;
        %{
        plot(t,swf,'-.');
        swf(swf<1) = NaN;
        swf(swf>=1) = 1;
        plot(t,swf,'*');
        %}
    else
        plot([1; 1]*(1:length(sw)),[1; 1]*sw,'*');
    end
end

