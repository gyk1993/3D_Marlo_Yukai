function [] = compile(CODE_PATH, INCLUDE_PATH, EIGEN_PATH)
%> To Compile C/C++ files to .mex for Windows and XOS
%> Copyright: Georgia Tech, AMBER LAB
%> Authors: Wen-Loong Ma <wenloong.ma@gmail.com>
%
% Heavily Modified: 12/13/2016 - Ross Hartley

%%
paths = {INCLUDE_PATH, EIGEN_PATH};

cd(CODE_PATH);
all = dir('*.cc');
n = length(all);

% parpool(4)
tic
for i = 1 : n
    MexStuff(all(i).name, datetime(all(i).date), paths, i);
end
toc

delete('*.pdb');
delete('*.lib');

cd ..
cd ..

beep;

end

function MexStuff(file, codeDate, paths, i)
    % file = 'J_naturalDynamics.cc';
    [~, fileName, ~] = fileparts(file);
    
    if exist([fileName,'.mexw64'], 'file')
        mexFile = dir([fileName,'.mexw64']);
        mexDate = datetime(mexFile.date);
        
        if mexDate > codeDate
            disp(['i = ', num2str(i), ', Already Compiled: ', fileName]);
            return;
        end
    elseif exist([fileName,'.mexa64'], 'file')
        mexFile = dir([fileName,'.mexa64']);
        mexDate = datetime(mexFile.date);
        
        if mexDate > codeDate
            disp(['i = ', num2str(i), ', Already Compiled: ', fileName]);
            return;
        end
    end
    
    disp(['i = ', num2str(i), ', Compiling: ', fileName]);

    comp(file, paths);
    
    disp(['i = ', num2str(i), ', Done Compiling: ', fileName]);
    
    if ~exist('./src','dir')
        mkdir('src')
    end
    if ~exist('./mex','dir')
        mkdir('mex')
    end
    movefile([fileName,'.cc'], './src/');
    movefile([fileName,'.hh'], './src/');
    movefile([fileName,'.mexw64'], './mex/');
end


%% Compile
function [] = comp(file, paths)
tic
mex(...
    ['-I', paths{1}], ...
    ['-I', paths{2}], ...
    file ...
    );

toc
end

