#include "SpriteDrawerBasic.h"

#include <iostream>

void SpriteDrawerBasic::Update(const float dTime, const UpdateData& data) {
	//Vector2u wSize = data.window->getSize();
	//Vector2f objectPos = GetOwner()->GetGlobalPosition();
	//_shape->setPosition(Vector2f((wSize.x * position.scale.x) + position.offset.x + objectPos.x, (wSize.y * position.scale.y) + position.offset.y + objectPos.y));
	//_shape->setScale(Vector2f(scale.x, scale.y));

	//if (GetOwner()->Get)
}

void SpriteDrawerBasic::RenderUpdate(const float dTime, const UpdateData& data) {
	data.window->draw(*_shape.get());
}


SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = OffsetScalePair(Vector2f(0, 0), Vector2f(0, 0));

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);

	_window = data.window;
	
	_transformCallbackId = owner->transformUpdated.size();
	owner->transformUpdated.push_back([this]() {
		this->Resized();
	});
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = pos;
	//scale = Vector2f(1, 1);

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);

	_window = data.window;

	_transformCallbackId = owner->transformUpdated.size();
	owner->transformUpdated.push_back([this]() {
		this->Resized();
	});
}

SpriteDrawerBasic::SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos, OffsetScalePair sizeT) : GameObjectComponent(owner) {
	_shape = std::move(shape);
	position = pos;
	size = sizeT;

	renderOrder = priority;
	RenderOrderer::GetRenderer().AddRenderer(this);

	_window = data.window;

	_transformCallbackId = owner->transformUpdated.size();
	owner->transformUpdated.push_back([this]() {
		this->Resized();
	});
}

SpriteDrawerBasic::~SpriteDrawerBasic() {
	GetOwner()->transformUpdated.erase(GetOwner()->transformUpdated.begin() + _transformCallbackId);

	RenderOrderer::GetRenderer().RemoveRenderer(this);
}