function S = initializeSimulinkBus(BusName)
    Bus = evalin('base', BusName);
    S = struct();
    
    builtinClasses = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64'};
    
    for k=1:length(Bus.Elements)
        if ismember(Bus.Elements(k).DataType, builtinClasses)
            if isscalar(Bus.Elements(k).Dimensions)
                dims = [Bus.Elements(k).Dimensions 1];
            else
                dims = Bus.Elements(k).Dimensions;
            end
            S.(Bus.Elements(k).Name) = zeros(dims, Bus.Elements(k).DataType);
            if ~isempty(Bus.Elements(k).Min)
                S.(Bus.Elements(k).Name) = max( S.(Bus.Elements(k).Name), Bus.Elements(k).Min );
            end
            if ~isempty(Bus.Elements(k).Max)
                S.(Bus.Elements(k).Name) = min( S.(Bus.Elements(k).Name), Bus.Elements(k).Max );
            end
        else
            S.(Bus.Elements(k).Name) = [];
        end
    end
end
