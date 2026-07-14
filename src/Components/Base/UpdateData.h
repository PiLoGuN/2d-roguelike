#pragma once

#include <SFML/Graphics.hpp>

struct UpdateData {
	sf::RenderWindow* window;
	float time;

	UpdateData() = default;
};