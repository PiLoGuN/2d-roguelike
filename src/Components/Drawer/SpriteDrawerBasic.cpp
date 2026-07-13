#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData& data) {
	Vector2u wSize = data.window->getSize();
	Vector2f objectPos = GetOwner()->GetPosition();
	_shape->setPosition(Vector2f((wSize.x * position.scale.x) + position.offset.x + objectPos.x, (wSize.y * position.scale.y) + position.offset.y + objectPos.y));
	_shape->setScale(Vector2f(size.x, size.y));

	/*sf::Color cTemp = _shape->getFillColor();
	_shape->setFillColor(sf::Color(cTemp.r + 500 * dTime, cTemp.g + 500 * dTime, cTemp.b + 500 * dTime));
	if (_shape->getFillColor().r >= 254) {
		_shape->setFillColor(sf::Color(0, 0, 0));
	}
	std::cout << _shape->getFillColor().r<<std::endl;*/
	
	data.window->draw(*_shape.get());
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape) : GameObjectComponent(owner), _shape(shape) {
	position = OffsetScalePair(Vector2f(0, 0), Vector2f(0, 0));
	size = Vector2f(1, 1);
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape, OffsetScalePair pos) : GameObjectComponent(owner), _shape(shape) {
	position = pos;
	size = Vector2f(1, 1);
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape, OffsetScalePair pos, Vector2f sizeT) : GameObjectComponent(owner), _shape(shape) {
	position = pos;
	size = sizeT;
}