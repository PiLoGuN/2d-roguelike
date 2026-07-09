#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData* data) {
	//std::cout << "The one with the crown";
	Vector2u wSize = data->window->getSize();
	_shape->setPosition(Vector2f(wSize.x * position.scale.x + position.offset.x, wSize.y * position.scale.y + position.offset.y));
	_shape->setScale(Vector2f(wSize.x * size.scale.x + size.offset.x, wSize.y * size.scale.y + size.offset.y));
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_shape = shape;
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape, OffsetScalePair pos, OffsetScalePair sizeT) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_shape = shape;
	position = pos;
	size = sizeT;
}