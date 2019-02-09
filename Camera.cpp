/*
 * Camera.cpp
 *
 *  Created on: 13 ott 2016
 *      Author: clasb
 */

#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, glm::vec3 front){
	this->position = position;
	this->worldUp = up;
	this->up = up;
	this->front = front;
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->yaw = YAW;
	this->pitch = PITCH;
	this->mouseSensitivity = SENSITIVTY;
	this->Zoom = ZOOM;
	this->movementSpeed = SPEED;
}

Camera::Camera(glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f),glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY), Zoom(ZOOM){
	this->position = position;
	this->worldUp = up;
	this->yaw = yaw;
	this->pitch = pitch;
	this->updateCameraVector();
}

void Camera::update(GLuint deltaT, Input* input){
	for(int i=0; i<Input::KEY_MAX; i++){
		if(input->getKeyPress()[i] == 1)
			switch(i){
			case 0:
				processKeyboard(FORWARD, deltaT);
				break;
			case 1:
				processKeyboard(LEFT, deltaT);
				break;
			case 2:
				processKeyboard(BACKWARD, deltaT);
				break;
			case 3:
				processKeyboard(RIGHT, deltaT);
				break;
			}
	}
	//updateCameraVector();
}

void Camera::processKeyboard(Camera_Movement direction, GLfloat deltaTime){
	GLfloat velocity = this->movementSpeed * deltaTime;
	if (direction == FORWARD)
		this->position -= this->up * velocity;
	if (direction == BACKWARD)
		this->position += this->up * velocity;
	if (direction == LEFT)
		this->position -= this->right * velocity;
	if (direction == RIGHT)
		this->position += this->right * velocity;
}

glm::mat4 Camera::getViewMatrix(){
	return glm::lookAt(this->position, this->position + this->front, this->up);
}

void Camera::updateCameraVector(){
	glm::vec3 front;
	front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	front.y = sin(glm::radians(this->pitch));
	front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front = glm::normalize(front);
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up 	= glm::normalize(glm::cross(this->right, this->front));
}

void Camera::rotate(GLfloat deg){
	pitch += deg;
	updateCameraVector();
}

void Camera::bindViewMatrix(std::vector<Shader*> shaders){
	GLint viewLocation;
	glm::mat4 view = glm::lookAt(this->position, this->position + this->front, this->up);;
	for(GLuint i=0; i<shaders.size(); i++){
		viewLocation = glGetUniformLocation(shaders[i]->getProgramID(), "view");
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
	}
}


