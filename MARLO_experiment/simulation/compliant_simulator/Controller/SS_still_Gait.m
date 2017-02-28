HAlpha = [zeros(1, 6);
    pi.*ones(1, 6);
    deg2rad(44).*ones(1, 6);
    zeros(1, 6);
    pi.*ones(1, 6);
    deg2rad(80).*ones(1, 6);];
H0 = [zeros(3, 6); [eye(3), zeros(3, 3)]; zeros(4, 6); [zeros(3, 3), eye(3)]; zeros(4, 6)]';
H0(2, 5) = 0.5;
H0(2, 6) = 0.5;
H0(3, 5) = -1;
H0(3, 6) = 1;
H0(6, 12) = -1;
H0(6, 13) = 1;
H0(5, 12) = 0.5;
H0(5, 13) = 0.5;

A = [1, 0, 0, 0, 0, 0;
    0, 0.5, 0.5, 0, 0, 0;
    0, -1, 1, 0, 0, 0;
    0, 0, 0, 1, 0, 0;
    0, 0, 0, 0, 0.5, 0.5;
    0, 0, 0, 0, -1, 1,];

outputs{1}.t = 1/3;
outputs{1}.HAlpha = HAlpha;
outputs{1}.H0 = H0;
outputs{1}.A = A;
outputs{2}.t = 1/3;
outputs{2}.HAlpha = HAlpha;
outputs{2}.H0 = H0;
outputs{2}.A = A;

save('C:\Users\oharib\Documents\GitHub\Omar-MARLO_WalkInPlace\gait-params\SS_still_Gait', 'outputs')
