
#include <pixelManage.hpp>
#include <iostream>




//3D methods

vec3D::vec3D() {
	this->position = glm::vec3(0.0f, 0.0f, 0.0f);
	this->colorRGB = glm::vec3(0.0f, 0.0f, 0.0f);
}

vec3D::vec3D(glm::vec3 pos, glm::vec3 cRGB) : position(pos), colorRGB(cRGB) {
	this->position = pos;
	this->colorRGB = cRGB;
}

//Getters

const std::string vec3D::getPosition() {
	return	" X: " + std::to_string(position.x) + 
			" Y: " + std::to_string(position.y) +
			" Z: " + std::to_string(position.z);
}

const std::string vec3D::getColorRGB() {
	return	" R: " + std::to_string(colorRGB.r) +
			" G: " + std::to_string(colorRGB.g) + 
			" B: " + std::to_string(colorRGB.b);
}


//Setters

void vec3D::setPosition(const glm::vec3& pos) {
	this->position.x = pos.x;
	this->position.y = pos.y;
	return;
}

void vec3D::setColorRGB(const glm::vec3& pos) {
	this->colorRGB.r = pos.r;
	this->colorRGB.g = pos.g;
	this->colorRGB.b = pos.b;
	return;
}