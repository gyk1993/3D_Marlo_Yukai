function mdlsummary = getmdlsummary(mdl)
    mdlsummary = struct(...
        'Name', mdl, ...
        'FixedStep', [], ...
        'LastModifiedBy', [], ...
        'LastModifiedDate', [], ...
        'Dirty', [], ...
        'Outport', struct('Name',[],'Port',[],'PortDimensions',[]) ...
        );
    
    try
        mdlsummary.FixedStep        = get_param(mdl,'FixedStep');
        mdlsummary.LastModifiedBy   = get_param(mdl,'LastModifiedBy');
        mdlsummary.LastModifiedDate = get_param(mdl,'LastModifiedDate');
        mdlsummary.Dirty            = get_param(mdl,'Dirty');
        
        OutportNames = find_system(mdl,'SearchDepth',1,'BlockType','Outport');
        mdlsummary.Outport = struct('Name',OutportNames,'Port',0,'PortDimensions',0);
        bioBlkNames = {};
        %{
        try
            biofun =[mdl 'bio'];
            if exist(biofun,'file')==2
                bio = feval(biofun);
                bioBlkNames = {bio.blkName};
            end
        catch
        end
        %}
        for k=1:length(OutportNames)
            mdlsummary.Outport(k).Name = OutportNames{k};
            mdlsummary.Outport(k).Port = get_param(OutportNames{k},'Port');
            mdlsummary.Outport(k).PortDimensions = get_param(OutportNames{k},'PortDimensions');
            %{
            mdlsummary.Outport(k).InputSignalNames = get_param(OutportNames{k},'InputSignalNames');
            [inBio, idxBio] = ismember(mdlsummary.Outport(k).InputSignalNames{1}, bioBlkNames);
            if inBio
                mdlsummary.Outport(k).InputSignalNameDimensions = bio(idxBio).sigWidth;
            else
                mdlsummary.Outport(k).InputSignalNameDimensions = [];
            end
            %mdlsummary.Outport(k).CompiledPortDimensions = get_param(OutportNames{k},'CompiledPortDimensions');
            %mdlsummary.Outport(k).CompiledPortWidths = get_param(OutportNames{k},'CompiledPortWidths');
            %}
        end
    catch
    end
end

function signal = findOutportSignal(bio, bioBlkNames, port, partialPath)
    t1 = get_param(port, 'PortConnectivity');
    n2 = get_param(t1.SrcBlock, 'Name');
    partialPath = [partialPath '/' n2];
    [inBio, idxBio] = ismember(regexprep(partialPath,'^\w+/',''), bioBlkNames);
    if inBio
        signal = bio(idxBio);
    else
        %t2 = get_param(t1.SrcBlock, 'PortHandles');
        %t2 = t2.Outport(t1.SrcPort+1);
        o1 = find_system(partialPath,'SearchDepth',1,'BlockType','Outport');
        p1 = str2double(get_param(o1,'Port'));
        signal = findOutportSignal(bio, bioBlkNames, o1{p1==t1.SrcPort+1}, partialPath);
    end
end
