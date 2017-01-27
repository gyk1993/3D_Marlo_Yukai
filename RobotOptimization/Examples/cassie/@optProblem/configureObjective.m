function [obj] = configureObjective(obj, varargin)
    % addCost - register cost function
    %
    % Copyright 2014-2015 Texas A&M University AMBER Lab
    % Author: Ayonga Hereid <ayonga@tamu.edu>
       
    obj.nzmaxCost = 0;
    costInfos = cell(obj.nDomain,1);
    
    
    %% All Domain Costs
    for i=1:obj.nDomain
        
        % Additive torque cost
        obj.domains{i} = addCost(obj.domains{i},'torqueCost',...
            {{'u'}}, 1:obj.domains{i}.nNode);
        
        % Additive hip cost
        weight = 1000;
        obj.domains{i} = addCost(obj.domains{i},'hipCost',...
            {{'q'}}, 1:obj.domains{i}.nNode,weight);
        
        % Additive yaw cost
        weight = 1000;
        obj.domains{i} = addCost(obj.domains{i},'yawCost',...
            {{'q'}}, 1:obj.domains{i}.nNode,weight);
               
        
%         % Constrain x0 externally
%         if i == 1
%             external = load('mat\opt_01_dx_00_dy');
%             x_external = [external.outputs{1}.q(1,:), external.outputs{1}.dq(1,:)];
%             weight = 10000*ones(1,44); weight([1:6]) = 0;
%             obj.domains{i} = addCost(obj.domains{i},'xCostExternal',...
%                 {{'q','dq'}}, 1, [weight, x_external]);
%         end
    
        % configure domain structure
        obj.domains{i} = configObjectiveStructure(obj.domains{i},...
            obj.nzmaxCost);
        
        obj.nzmaxCost = obj.nzmaxCost + obj.domains{i}.nzmaxCost;
        costInfos{i} = obj.domains{i}.costArray;
    end
    
    
    obj.costArray = vertcat(costInfos{:});
    nCosts = numel(obj.costArray);
    % construct the row and column indices for the sparse jacobian
    % matrix
    obj.costRows = ones(obj.nzmaxCost,1);
    obj.costCols = ones(obj.nzmaxCost,1);
    for i=1:nCosts
        
        j_index = obj.costArray(i).j_index;
        obj.costCols(j_index) = obj.costArray(i).deps;

    end
end
