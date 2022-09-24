//Parameters given by the assignment
float w = 2.0f; //half-width factor
float n = -4.0f; //near boundary
float f = 12.0f; //far boundary

// Create a matrix for Isometric projection with the given aspect ration a
glm::mat4 PO1(float a) {	
	float l = -w; //left boundary
	float r = w; //right boundary
	float b = -w / a; //bottom boundary
	float t = w/ a; //top boundary
	
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) //This added matrix product flips the y-axis to match the Vulkan conventions
					* glm::ortho(l, r, b, t, n, f) //must be applyed before performing the two rotations 
					* glm::rotate(glm::mat4(1), glm::radians(35.26f), glm::vec3(1, 0, 0)) //rotation of 35.26 degrees around x-axis
					* glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)) ;//rotation of 45 degrees around y-axis
	return out;
}

// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
glm::mat4 PO2(float a) {
	float l = -w; //left boundary
	float r = w; //right boundary
	float b = -w / a; //bottom boundary
	float t = w / a; //top boundary
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) //This added matrix product flips the y-axis to match the Vulkan conventions
					* glm::ortho(l, r, b, t, n, f) //must be applyed before performing the two rotations 
					* glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0))//rotation must be applied around x-axis
					* glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0));//rotation must be applied around y-axis
	return out;
}

// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
glm::mat4 PO3(float a) {
	float l = -w; //left boundary
	float r = w; //right boundary
	float b = -w / a; //bottom boundary
	float t = w / a; //top boundary
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) //This added matrix product flips the y-axis to match the Vulkan conventions
					* glm::ortho(l, r, b, t, n, f) //must be applyed before performing the two rotations
					* glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0)) //rotation must be applied around x-axis
					* glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1, 0)); //rotation must be applied around y-axis
	return out;
}

// Create a matrix for Cabinet projection (alpha = 45)
// with the given aspect ration a
glm::mat4 PO4(float a) {
	float l = -w; //left boundary
	float r = w; //right boundary
	float b = -w / a; //bottom boundary
	float t = w / a; //top boundary
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) //This added matrix product flips the y-axis to match the Vulkan conventions
					* glm::ortho(l, r, b, t, n, f) //must be applyed before performing the two rotations
					* glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, -0.35, -0.35, 1, 0, 0, 0, 0, 1);//using a shear along z-axis
	return out;
}

