
#include <pixelManage.hpp>
#include <iostream>

vec2D::vec2D() {
	
}


vec2D::vec2D(glm::vec2 pos, glm::vec3 cRGB) : position(position), colorRGB(cRGB) {
	this->position = pos;
	this->colorRGB = cRGB;
}

