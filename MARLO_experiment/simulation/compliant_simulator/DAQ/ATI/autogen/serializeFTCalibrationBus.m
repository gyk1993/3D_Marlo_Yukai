function A = serializeFTCalibrationBus(S)
	%#codegen
	if coder.target('MATLAB')
		A = zeros(188, 1);
	else
		A = coder.nullcopy(zeros(188, 1));
	end
	A(1:8) = S.CalibSerialNumber;
	A(9:40) = S.CalibPartNumber;
	A(41:44) = S.CalibFamilyId;
	A(45:64) = S.CalibTime;
	A(65:100) = S.BasicMatrix(:);
	A(101) = S.ForceUnits;
	A(102) = S.TorqueUnits;
	A(103:108) = S.MaxRating;
	A(109) = S.CountsPerForce;
	A(110) = S.CountsPerTorque;
	A(111:116) = S.GageGain;
	A(117:122) = S.GageOffset;
	A(123:128) = S.Resolution;
	A(129:134) = S.Range;
	A(135:140) = S.ScaleFactor16;
	A(141:156) = S.UserField1;
	A(157:172) = S.UserField2;
	A(173:188) = S.SpareData;
end

