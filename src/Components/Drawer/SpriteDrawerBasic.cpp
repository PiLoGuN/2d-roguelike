#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData& data) {
	Vector2u wSize = data.window->getSize();
	Vector2f objectPos = GetOwner()->GetPosition();
	_shape.setPosition(Vector2f((wSize.x * position.scale.x) + position.offset.x + objectPos.x, (wSize.y * position.scale.y) + position.offset.y + objectPos.y));
	_shape.setScale(Vector2f(size.x, size.y));

	std::cout << "This ENDS HERE" << std::endl;
	std::cout << GetOwner() << std::endl;
	std::cout << (wSize.x * position.scale.x) << " " << (wSize.y * position.scale.y) << std::endl;
	std::cout << (wSize.x * position.scale.x) + position.offset.x << " " << (wSize.y * position.scale.y) + position.offset.y << std::endl;
	std::cout << objectPos.x << " " << objectPos.y << std::endl;
	std::cout << _shape.getPosition().x << " " << _shape.getPosition().y << std::endl;
	std::cout << _shape.getScale().x << " " << _shape.getScale().y << std::endl;

	data.window->draw(_shape);
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase& owner, sf::Shape& shape) : GameObjectComponent(owner), _shape(shape) {
	position = OffsetScalePair(Vector2f(0, 0), Vector2f(0, 0));
	size = Vector2f(1, 1);
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase& owner, sf::Shape& shape, OffsetScalePair pos) : GameObjectComponent(owner), _shape(shape) {
	position = pos;
	size = Vector2f(1, 1);
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase& owner, sf::Shape& shape, OffsetScalePair pos, Vector2f sizeT) : GameObjectComponent(owner), _shape(shape) {
	position = pos;
	size = sizeT;
}