/*
 * Camera.h
 *
 *  Created on: 13 ott 2016
 *      Author: clasb
 */

#ifndef CAMERA_H_
#define CAMERA_H_


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "shaders/Shader.h"
#include "Input.h"

enum Camera_Movement {
	    FORWARD,
	    LEFT,
		BACKWARD,
	    RIGHT
	};

class Camera{
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	GLfloat Zoom;

	Camera(glm::vec3 position, glm::vec3 up, glm::vec3 front);
	Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch);

	void update(GLuint deltaT, Input* input);
	glm::mat4 getViewMatrix();
	void processKeyboard(Camera_Movement direction, GLfloat deltaTime);
	void rotate(GLfloat deg);
	void bindViewMatrix(std::vector<Shader*> shaders);

private:
	// Default camera values
	static constexpr GLfloat YAW        = -90.0f;
	static constexpr GLfloat PITCH      =  0.0f;
	static constexpr GLfloat SPEED      =  1.0f;
	static constexpr GLfloat SENSITIVTY =  0.25f;
	static constexpr GLfloat ZOOM       =  45.0f;

	void updateCameraVector();

};



#endif /* CAMERA_H_ */
