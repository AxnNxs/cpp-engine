// First iteration of a library for rendering 2D and 3D graphics

#pragma once
#include <string>
#include <glm/glm.hpp>

// my_class.hpp
#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP
#endif


class vec2D {
private:
	glm::vec2 position;
	glm::vec3 colorRGB;

public:
	vec2D();
	vec2D(glm::vec2 position, glm::vec3 color);
};



class vec3D {
private:
	glm::vec3 position;
	glm::vec3 colorRGB;

public:
	vec3D();
	vec3D(glm::vec3 position, glm::vec3 color);
};