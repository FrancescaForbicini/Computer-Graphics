 // Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)
glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {
	glm::mat4 out = glm::rotate(glm::mat4(1.0), -Angs.z, glm::vec3(0, 0, 1)) * //rotation with respect to z-axis 
					glm::rotate(glm::mat4(1.0), -Angs.y, glm::vec3(0, 1, 0)) * //rotation with respect to y-axis 
					glm::rotate(glm::mat4(1.0), -Angs.x, glm::vec3(1, 0, 0)) * //rotation with respect to x- axis
					glm::translate(glm::mat4(1.0), glm::vec3(-Pos.x, -Pos.y, -Pos.z)); //translation must be perfomed after the three rotations
	return out;
}

 // Create a look at matrix
 // Pos    -> Position of the camera (c)
 // aim    -> Position of the target (a)
 // Roll   -> roll (rho)
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
	glm::vec3 posXaim = glm::vec3(Pos.x - aim.x, Pos.y - aim.y, Pos.z - aim.z); //distance between the start from where the camera is looking
																				//and end in its center
	glm::vec3 vz = glm::normalize(posXaim); //normalization of the posXaim
	glm::vec3 uXvz = glm::cross(glm::vec3(0, 1, 0) , vz); //the new x-axis must be perpendicular to the y and z axis
	glm::vec3 vx = glm::normalize(uXvz); //normalization of the cross product before
	glm::vec3 vy = glm::cross(vz, vx); //the new y-axis must be perpendicular to the x and z axis
	glm::mat4 out = glm::mat4(glm::vec4(vx.x, vx.y, vx.z, 0), 
							  glm::vec4(vy.x, vy.y, vy.z, 0), 
							  glm::vec4(vz.x, vz.y, vz.z, 0), 
							  glm::vec4(Pos.x, Pos.y, Pos.z, 1)); //we're building the 4x4 matrix
	out = glm::inverse(out); //inverse of the matrix build before to create the view matrix
	out = glm::rotate(glm::mat4(1), -Roll, glm::vec3(0, 0, 1)) //projection matrix
		  * out; //view matrix
	/*
	Another Solution: using lookAt directly
	glm::mat4 out = glm::lookAt(Pos, aim, glm::vec3(0, 1, 0));
	glm::mat4 out = glm::lookAt(Pos, aim, glm::vec3(0, 1, 0));
	out = out * glm::rotate(glm::mat4(1), -Roll, glm::vec3(0, 0, 1));
	*/
	return out;
}



