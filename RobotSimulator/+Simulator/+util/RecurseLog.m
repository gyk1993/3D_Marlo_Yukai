function [newLogArray] = RecurseLog(logArray, log)
	if isstruct(log)
		fields = fieldnames(log);
		newLogArray = struct();
		for i = 1:numel(fields)
			newLogArray.(fields{i}) = Simulator.util.RecurseLog(logArray.(fields{i}), log.(fields{i}));
		end
    else
        try
            newLogArray = [logArray, log];
        catch % Bug, happpend when holonomic constraint dimension changes during domain
            newLogArray = logArray;
        end
	end
end
