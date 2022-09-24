// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	//previous value of the last call procedure
	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = 0.0f;
	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
	//DeltaT measured the time since the last call to the procedure
	float deltaT = time - lastTime;
	lastTime = time;

	static glm::vec3 pos = glm::vec3(-3,0,2);	

	static float yaw = 0.0f; 
	float roll = 0.0f;  

	//The subjet faces up and down while floating in the air
	if (glfwGetKey(window, GLFW_KEY_UP)) {
		pos.y = pos.y + deltaT;
		roll = 90.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN)) {
		pos.y = pos.y - deltaT;
		roll = -90.0f;
	}

	//To move the object to the left
	if (glfwGetKey(window, GLFW_KEY_A)) {
		pos.x = pos.x - deltaT;
		yaw = -180.0f;
	}

	//To move the object forward
	if (glfwGetKey(window, GLFW_KEY_W)) {
		pos.z = pos.z - deltaT;
		yaw = +90.0f;
	}

	//To move the object to the right
	if (glfwGetKey(window, GLFW_KEY_D)) {
		pos.x = pos.x + deltaT;
		yaw = 0.0f;
	}

	//To move the object backward
	if (glfwGetKey(window, GLFW_KEY_S)) {
		pos.z = pos.z + deltaT;
		yaw = -90.0f;
	}
	glm::mat4 out;
	
	//With quaternions
	glm::quat rotx = glm::rotate(glm::mat4(1.0), glm::radians(0.0f), glm::vec3(1, 0, 0)); //moving the x
	glm::quat roty = glm::rotate(glm::mat4(1.0), glm::radians(yaw), glm::vec3(0, 1, 0)); //moving the y
	glm::quat rotz = glm::rotate(glm::mat4(1.0), glm::radians(roll), glm::vec3(0, 0, 1)); //moving the z

	out = glm::translate(glm::mat4(1), pos) * glm::mat4(roty) * glm::mat4(rotx) * glm::mat4(rotz);

	/*Another Solution: Without quaternions
		glm::mat4 roty = glm::rotate(glm::mat4(1.0), glm::radians(yaw), glm::vec3(0, 1, 0));
		glm::mat4 rotx = glm::rotate(glm::mat4(1.0), glm::radians(0.0f), glm::vec3(1, 0, 0));
		glm::mat4 rotz = glm::rotate(glm::mat4(1.0), glm::radians(roll), glm::vec3(0, 0, 1));

		out = glm::translate(glm::mat4(1), pos) ;
		out = out * roty * rotx * rotz;
	*/
		
	return out;
}

