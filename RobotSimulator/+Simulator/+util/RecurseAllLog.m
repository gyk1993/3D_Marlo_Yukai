function [newLogArray] = RecurseAllLog(log)
newLogArray = log(1);
for i=2:length(log)
    newLogArray = Simulator.util.RecurseLog(newLogArray, log(i));
end
end
