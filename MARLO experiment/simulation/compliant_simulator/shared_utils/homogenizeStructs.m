function S = homogenizeStructs(varargin)
    % Takes multiple structures and concatenates them into a struct array
    % Adds fields with empty values and reorders fields where needed to
    % make the structures compatible for concatenation.
    % The ordering of the fields in the output structure S is taken from
    % the first input argument in which that field occurs.
    
    S = varargin{1};
    for k=2:nargin
        Stmp = varargin{k};
        fields = fieldnames(Stmp);
        for l=1:length(fields)
            S(k).(fields{l}) = Stmp.(fields{l});
        end
    end
end
