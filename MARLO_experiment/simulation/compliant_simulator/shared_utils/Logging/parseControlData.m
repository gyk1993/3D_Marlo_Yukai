function S = parseControlData(S)
    % PARSECONTROLDATA  converts serialized ControlParams data and
    % vectorized ControlState data to a more useful format.
    
    if isfield(S, 'SerialOut') && ~isempty(S.SerialOut)
        [S.ts,A]=deserialize(S.t, S.SerialOut);
        try
            for k=1:length(S.ts)
                ControlParams(k,1) = deserializeControlParamsBus(A(:,:,k));
            end
            S.ControlParams = ControlParams;
        catch
            S.ControlParams = zeros(length(S.ts), 0);
            S.A = A;
        end
    end
    if isfield(S, 'ControlState') && ~isempty(S.ControlState)
        try
            ControlState = deserializeControlStateBus(S.ControlState(1,:)');
            ControlStateFields = fieldnames(ControlState);
            if length(ControlStateFields)~=size(S.ControlState,2)
                warning('PARSEMODELDATA: ControlState has non-scalar fields. Please update PARSEMODELDATA function.')
            else
                for k=1:length(ControlStateFields)
                    ControlState.(ControlStateFields{k}) = S.ControlState(:,k);
                end
                S.ControlState = ControlState;
            end
        catch
            warning('PARSEMODELDATA: Could not deserialize ControlState.')
        end
    end
end
