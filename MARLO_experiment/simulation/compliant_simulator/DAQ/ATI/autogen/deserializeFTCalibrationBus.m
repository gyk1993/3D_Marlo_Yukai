function S = deserializeFTCalibrationBus(A)
	%#codegen
	S = struct();
	S.CalibSerialNumber = A(1:8);
	S.CalibPartNumber = A(9:40);
	S.CalibFamilyId = A(41:44);
	S.CalibTime = A(45:64);
	S.BasicMatrix = reshape(A(65:100), [6 6]);
	S.ForceUnits = A(101:101);
	S.TorqueUnits = A(102:102);
	S.MaxRating = A(103:108);
	S.CountsPerForce = A(109:109);
	S.CountsPerTorque = A(110:110);
	S.GageGain = A(111:116);
	S.GageOffset = A(117:122);
	S.Resolution = A(123:128);
	S.Range = A(129:134);
	S.ScaleFactor16 = A(135:140);
	S.UserField1 = A(141:156);
	S.UserField2 = A(157:172);
	S.SpareData = A(173:188);
end

