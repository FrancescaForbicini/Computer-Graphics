//For each matrix we perform the transformations in the reverse order to obtain the view matrix and not the camera matrix

// Rotate 45 degrees around an arbitrary axis passing through (1,0,-1). The x-axis can be aligned to the arbitrary axis after a rotation of 30 degrees around the z-axis, and then -60 degrees around the y-axis.
glm::mat4 MT1 = translate(glm::mat4(1), glm::vec3(1, 0, -1)) //for passing in the point (1,0,-1)
				* glm::rotate(glm::mat4(1), glm::radians(-60.0f), glm::vec3(0, 1, 0)) //rotation of -60 degrees around y-axis
				* glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 0, 1)) //rotation of 30 degrees around z-axis
				* glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0)) //rotation of 45 degrees around x-axis
				* glm::rotate(glm::mat4(1), glm::radians(-30.0f), glm::vec3(0, 0, 1)) //inverse of the second rotation
				* glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1, 0)) //inverse of the first rotation 
				* translate(glm::mat4(1), glm::vec3(-1, 0, 1));
			   
// Half the size of an object, using as fixed point (5,0,-2)
glm::mat4 MT2 = translate(glm::mat4(1), glm::vec3(5, 0, -2)) //for passing through (5,0,-2)
				* glm::scale(glm::mat4(1), glm::vec3(0.5, 0.5, 0.5)) //scaling of 1/2 the object
				* translate(glm::mat4(1),glm::vec3(-5,0,2));//inverse of the first translation
			   
// Mirror the starship along a plane passing through (1,1,1), and obtained rotating 15 degree around the x axis the xz plane
glm::mat4 MT3 = translate(glm::mat4(1), glm::vec3(1, 1, 1)) //for passing through (1,1,1)
				* glm::rotate(glm::mat4(1), glm::radians(15.0f), glm::vec3(1, 0, 0)) //rotation of 15 degrees around the x axis
				* glm::scale(glm::mat4(1), glm::vec3(1, -1, 1)) //Scaling to perform the mirroring 
				* glm::rotate(glm::mat4(1), glm::radians(-15.0f), glm::vec3(1, 0, 0))//inverse of rotation of 15 degrees
				* translate(glm::mat4(1), glm::vec3(-1, -1, -1));//inverse of translation for passing through (1,1,1)
			   
// Apply the inverse of the following sequence of transforms: Translation of (0, 0, 5) then rotation of 30 degree around the Y axis, and finally a uniform scaling of a factor of 3.
glm::mat4 MT4 = inverse(glm::scale(glm::mat4(1),glm::vec3(3,3,3))//Scaling of factor 3
				* glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 1, 0))//rotation of 30 degrees arounf y-axis
				* translate(glm::mat4(1), glm::vec3(0, 0, 5)));//translation for passing through (0,0,5)

