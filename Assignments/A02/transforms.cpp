	// Translate of +2 on the x axis, and -1 on the y axis
    //To perform the translation we put the movement coordinates in the last column.
	const float MT1[] =  {
			   1.0,		0.0,		0.0,		2.0,
			   0.0,		1.0,		0.0,	   -1.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	// Rotate of 45 degrees on the x axis
	//To perform the rotation we used the transfor matrix Rx,so in the second column we put the cos(45) and sin(45)
	//while in the third column we put -sin(45) and cos(45)
	const float MT2[] =  {
			   1.0,		0.0,		0.0,		0.0,
			   0.0,		0.7,	   -0.7,		0.0,
			   0.0,		0.7,		0.7,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	// Make the object 2 times smaller
	//To perform the scaling we put in the main diagonal the factor to reduce the object (in this case 1/2)
	const float MT3[] =  {
			   0.5,		0.0,		0.0,		0.0,
			   0.0,		0.5,		0.0,		0.0,
			   0.0,		0.0,		0.5,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	// Make the object 2 times longer on the z axis, and half on the other axis
	//To perform the scaling we put in the main diagonal in the first and second column the factor to reduce the object(1/2)
	//and in the third column the factor to increase the object(z)
	const float MT4[] =  {
			   0.5,		0.0,		0.0,		0.0,
			   0.0,		0.5,		0.0,		0.0,
			   0.0,		0.0,		2.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};

	// Mirror over the z axis
	//To perform the axial mirroring we put in the first and the second column the scaling factor -1 to 
	//apply the symmetry with respect to the z axis (so the third column)
	const float MT5[] =  {
			  -1.0,	    0.0,		0.0,		0.0,
			   0.0,	   -1.0,		0.0,		0.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
			   
	// Flatten over the z axis
	//To perform the flatten scaling we put in the third column the scaling factor 0 to 
	//apply the transformation with respect to the z axis (so the third column)
	const float MT6[] =  {
			   1.0,		0.0,		0.0,		0.0,
			   0.0,		1.0,		0.0,		0.0,
			   0.0,		0.0,		0.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};

	// Make a shear along the Y axis, with a factor of 1 along the x axis
	//To perform the shear we applyed the equations for the x axis, so we added to y 
	// the factor 1 * x;
	const float MT7[] =  {
			   1.0,		1.0,		0.0,		0.0,
			   0.0,		1.0,		0.0,		0.0,
			   0.0,		0.0,		1.0,		0.0,
			   0.0,		0.0,		0.0,		1.0};
