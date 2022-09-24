// Create a world matrix using position, Euler angles, and size
// Euler angles are passed in YPR parameter:
// YPR.x : Yaw
// YPR.y : Pitch
// YPR.z : Roll
glm::mat4 MakeWorldMatrixEuler(glm::vec3 pos, glm::vec3 YPR, glm::vec3 size) {
	glm::mat4 out = glm::translate(glm::mat4(1.0), pos) *   //position of the object
					glm::eulerAngleYXZ(glm::radians(YPR.x), //define the orientation of the object in the space
									   glm::radians(YPR.y), 
									   glm::radians(YPR.z)) * 
					glm::scale(glm::mat4(1.0),size);  //scaling object
	/*
		Another Solution without using the function eulerAngleYXZ
			glm::mat4 out = glm::translate(glm::mat4(1.0), pos) * 
						    glm::rotate(glm::mat4(1.0), glm::radians(YPR.x), glm::vec3(0, 1, 0)) * //rotation respect yaw
							glm::rotate(glm::mat4(1.0), glm::radians(YPR.y), glm::vec3(1, 0, 0)) *  //rotation respect pitch
							glm::rotate(glm::mat4(1.0), glm::radians(YPR.z), glm::vec3(0, 0, 1)) *  //rotation respect roll
							glm::scale(glm::mat4(1.0),size);
	*/
	return out;
}

// Create a world matrix using position, quaternion angles, and size
glm::mat4 MakeWorldMatrixQuat(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
	glm::mat4 out = glm::translate(glm::mat4(1.0f),pos) * //position of the object
					glm::mat4(rQ) * //to extract angles from the quaternion building a 4x4 matrix
					glm::scale(glm::mat4(1.0f),size);  //scaling object
	return out;
}

	