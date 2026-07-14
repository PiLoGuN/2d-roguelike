#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

struct OffsetScalePair {
	Vector2f scale;
	Vector2f offset;

	OffsetScalePair() = default;

	OffsetScalePair(Vector2f scaleT) {
		scale = scaleT;
		offset = Vector2f(0, 0);
	}

	OffsetScalePair(Vector2f scaleT, Vector2f offsetT) {
		scale = scaleT;
		offset = offsetT;
	}

	static Vector2f ScaleToOffset(sf::RenderWindow& window, Vector2f scale);
	static Vector2f OffsetToScale(sf::RenderWindow& window, Vector2f offset);
};