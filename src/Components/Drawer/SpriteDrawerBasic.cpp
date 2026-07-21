#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData& data) {
	Vector2u wSize = data.window->getSize();
	Vector2f objectPos = GetOwner()->GetGlobalPosition();
	_shape->setPosition(Vector2f((wSize.x * position.scale.x) + position.offset.x + objectPos.x, (wSize.y * position.scale.y) + position.offset.y + objectPos.y));
	_shape->setScale(Vector2f(size.x, size.y));
}

void SpriteDrawerBasic::RenderUpdate(const float dTime, const UpdateData& data) {
	data.window->draw(*_shape.get());
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = OffsetScalePair(Vector2f(0, 0), Vector2f(0, 0));
	size = Vector2f(1, 1);

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority, OffsetScalePair pos) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = pos;
	size = Vector2f(1, 1);

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority, OffsetScalePair pos, Vector2f sizeT) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = pos;
	size = sizeT;

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);
}

SpriteDrawerBasic::~SpriteDrawerBasic() {
	RenderOrderer::GetRenderer().RemoveRenderer(this);
}