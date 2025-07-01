// First iteration of a library for rendering 2D and 3D graphics

#pragma once
#include <string>
#include <glm/glm.hpp>

// my_class.hpp
#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP
#endif


class vec3D {
	private:
		glm::vec3 position;
		glm::vec3 colorRGB;

	public:
		vec3D();
		vec3D(glm::vec3 position, glm::vec3 color);

		const std::string getPosition();
		const std::string getColorRGB();

		void setPosition(const glm::vec3& newPos);
		void setColorRGB(const glm::vec3& newCol);
};