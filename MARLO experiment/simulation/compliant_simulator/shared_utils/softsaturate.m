function [s, ds] = softsaturate(s, ds, delta, p)
    % This saturation allows some overshoot or undershoot in order to make
    % a smooth transition to the saturation region.
    %
    % The soft-saturated value sbar of s is given by
    %           {  1                ,    if s > 1+delta
    %           {  1+f((s-1)/delta) ,    if 1 < s <= 1+delta
    %   sbar =  {  s                ,    if 0 <= s <= 1
    %           {  -f(-s/delta)     ,    if -delta <= s < 0
    %           {  0                ,    if s < -delta
    %
    % The transition function f is a degree-three polynomial satisfying
    %   f(t) = a3*t^3 + a2*t^2 + a1*t + a0
    %   f(0) = 0               <=>   a0 = 0
    %   df/dt(0) = 1/delta     <=>   a1 = delta
    %   f(1) = 0               <=>   a0+a1+a2+a3 = 1
    %   df/dt(1) = 0           <=>   3*a3 + 2*a2 + a1 = 0
    %
    % The derivative of sbar is
    %           {  0                           ,    if s > 1+delta
    %           {  df/dt((s-1)/delta)*ds/delta ,    if 1 < s <= 1+delta
    %  dsbar =  {  ds                          ,    if 0 <= s <= 1
    %           {  df/dt(-s/delta)*ds/delta    ,    if -delta <= s < 0
    %           {  0                           ,    if s < -delta
     
    % TEST CODE
    %{
        delta = 0.2;
        t     = -1:0.001:2;
        ds    = 1.5+0*t;
        s     = 1.5*t;
        [sbar, dsbar] = softsaturate(s, ds, delta);
        figure;
        subplot(211); plot(t,s,t,sbar,t,max(0,min(s,1)),':r')
        legend('s','soft-saturated s','hard-saturated s');
        axis([-1 2 -1 2]);
        subplot(212); plot(t,ds,t,dsbar,t(1:end-1),diff(s)./diff(t),':r',t(1:end-1),diff(sbar)./diff(t),':m');
        legend('ds','soft-saturated ds','discrete estimate of ds','discrete estimate of dsbar');
        axis([-1 2 -1 2]);
    %}
    
    if nargin<4
        % Precompute this and pass it in for speed
        p=[0 delta 0 0]/[0 0 0 1; 0 0 1 0; 1 1 1 1; 3 2 1 0].'; %t=(s-1)/delta;
    end
    
    % Fully saturated above 1+delta
    ds(s > 1+delta) = 0;
    s(s > 1+delta)  = 1;
        
    % Make a continuously differentiable transition to s=1 at 1+delta
    ds(s>1) = polyval( [3 2 1].*p(1:3), (s(s>1)-1)/delta ).*ds(s>1)/delta;
    s(s>1)  = 1+polyval(p, (s(s>1)-1)/delta);
        
    % Fully saturate below -delta
    ds(s < -delta) = 0;
    s(s < -delta)  = 0;
        
    % Make a continuously differentiable transition to s=0 at -delta
    ds(s<0) = polyval( [3 2 1].*p(1:3), -s(s<0)/delta ).*ds(s<0)/delta;
    s(s<0)  = -polyval(p, -s(s<0)/delta);
end
