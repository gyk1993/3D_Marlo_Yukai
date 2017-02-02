classdef VRJoystickWrapper < handle
	properties (GetAccess = protected, SetAccess = private)
		joy
        axes_prev
		buttons_prev
		pov_prev
	end
	
	methods
		function obj = VRJoystickWrapper(joystickID)
			obj.joy = vrjoystick(joystickID);
			[axes, buttons, pov] = read(obj.joy);
			
			obj.axes_prev = zeros(size(axes));
            obj.buttons_prev = zeros(size(buttons));
			obj.pov_prev = -ones(size(pov));
		end
	end
	
	methods (Sealed)
		function [axes, buttons, pov, buttonsRiseEdge, povRiseEdge] = Tick(obj)
			[axes, buttons, pov] = read(obj.joy);
			
			buttonsRiseEdge = zeros(size(buttons));
            
            for idx = 1:numel(axes)
				axesRiseEdge(idx) = (axes(idx) ~= 0 && obj.axes_prev(idx) == 0);
			end
            
			for idx = 1:numel(buttons)
				buttonsRiseEdge(idx) = (buttons(idx) ~= 0 && obj.buttons_prev(idx) == 0);
            end
			
			povRiseEdge = zeros(size(pov));
			for idx = 1:numel(pov)
				povRiseEdge(idx) = (pov(idx) ~= -1 && obj.pov_prev(idx) == -1);
            end
			
            obj.axes_prev = axes;
			obj.buttons_prev = buttons;
			obj.pov_prev = pov;
		end
		
		function close(obj)
			close(obj.joy);
		end
	end
end
