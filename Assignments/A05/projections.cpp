//Parameter given by the assignmet
float n = 0.1f; //near boundary
float f = 9.9f; //far boundary


// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 90o
glm::mat4 PO1(float a) {
	glm::mat4 out = glm::perspective(glm::radians(90.0f), a, n, f);
	out[1][1] *= -1; //Since the Vulkan and OpenGL matrices for Fov/Aspect ratio projection 
					 //differ only for the sign of the element in the second row / second column
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 120o
glm::mat4 PO2(float a) {
	glm::mat4 out = glm::perspective(glm::radians(120.0f), a, n, f);
	out[1][1] *= -1; //Since the Vulkan and OpenGL matrices for Fov/Aspect ratio projection 
					 //differ only for the sign of the element in the second row / second column
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 30o
glm::mat4 PO3(float a) {
	glm::mat4 out = glm::perspective(glm::radians(30.0f), a, n, f);
	out[1][1] *= -1; //Since the Vulkan and OpenGL matrices for Fov/Aspect ratio projection 
					 //differ only for the sign of the element in the second row / second column
	return out;
}

// Create a matrix for Perspecrtive projection, with the given aspect ratio a.
// Here the perspective should only show the left side of the view
// with a FovY = 90o. Here r=0, and l, t and b should be computed
// to match both the aspect ratio and the FovY
glm::mat4 PO4(float a) {
	float l = -2.0f * a * n * tan(90.0f/2); //left boundary
	float r = 0.0f; //right boundary
	float t = n * tan(90.0f/2); //top boundary
	float b = -n * tan(90.0f/2); //bottom boundary
	glm::mat4 out = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1))	 //This added matrix product flips the y-axis to match the Vulkan conventions.
				  * glm::frustum(l,r, b, t, n, f); //to compute the perspective projection matrix specifying the boundaries
	return out;
}


