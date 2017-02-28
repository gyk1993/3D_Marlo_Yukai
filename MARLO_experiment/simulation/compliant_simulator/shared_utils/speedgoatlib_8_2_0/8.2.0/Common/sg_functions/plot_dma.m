function plot_dma(nbPointsToPlot,frameSize,sampleRate,fileName )

    % Create file system object
    fsys = xpctarget.fs;
    % Open file on the target file system
    h = fsys.fopen(fileName);
    % Read the data from the target file into a MATLAB variable. Note that
    % this data will still be represented in xPC Target file
    % format (i.e. not bytes)
    data = fsys.fread(h);
    % Close file on file system
    fsys.fclose(h);
    % Call READXPCFILE to convert the data from xPC Target
    % file format to bytes for use in MATLAB
    waveArray = readxpcfile(data);

    %create a vector with all points of the waveform
    for i = 1 : nbPointsToPlot/frameSize
        for a = 1 : frameSize
            waveForm(i*frameSize-(frameSize-a)) = waveArray.data(i, a);

        end
    end
    
    %create time vector
    time = [0:sampleRate:sampleRate*(nbPointsToPlot-1)];
    %plot the poins
    stem(time, waveForm)%,'o',time, waveForm)
    xlabel('Time [s]')
    ylabel('Amplitude [V]')
    title('DMA waveform')
    grid
end