#include "OffsetScalePair.h"

Vector2f OffsetScalePair::ScaleToOffset(sf::RenderWindow& window, Vector2f scale) {
	Vector2u stats = window.getSize();
	return Vector2f(stats.x * scale.x, stats.y * scale.y);
}

Vector2f OffsetScalePair::OffsetToScale(sf::RenderWindow& window, Vector2f offset) {
	Vector2u stats = window.getSize();
	return Vector2f(offset.x / stats.x, offset.y / stats.y);
}