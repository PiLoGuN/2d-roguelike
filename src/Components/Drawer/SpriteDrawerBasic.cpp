#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData* data) {
	Vector2u wSize = data->window->getSize();
	Vector2f objectPos = GetOwner()->GetPosition();
	_shape->setPosition(Vector2f(wSize.x * position.scale.x + position.offset.x + objectPos.x, wSize.y * position.scale.y + position.offset.y + objectPos.y));
	_shape->setScale(Vector2f(size.x, size.y));

	data->window->draw(*_shape);
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_shape = shape;
}

SpriteDrawerBasic::SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape, OffsetScalePair pos, Vector2f sizeT) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_shape = shape;
	position = pos;
	size = sizeT;
}