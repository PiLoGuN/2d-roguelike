#include "RectangleBasicDrawer.h"

void RectangleBasicDrawer::Resized() {
	Vector2u wSize = _window->getSize();

	RectangleShape* shapeTemp = dynamic_cast<RectangleShape*>(_shape.get());
	shapeTemp->setSize(Vector2f((wSize.x * size.scale.x) + size.offset.x, (wSize.y * size.scale.y) + size.offset.y));

	shapeTemp->setOrigin(shapeTemp->getLocalBounds().getCenter());

	Vector2f objectPos = GetOwner()->GetGlobalPosition();
	_shape->setPosition(Vector2f((wSize.x * position.scale.x) + position.offset.x + objectPos.x, (wSize.y * position.scale.y) + position.offset.y + objectPos.y));

	std::cout << (wSize.x * size.scale.x) + size.offset.x << std::endl;
}

RectangleBasicDrawer::RectangleBasicDrawer(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos, OffsetScalePair size) : SpriteDrawerBasic(owner, std::move(shape), data, priority, pos, size) {
	//SpriteDrawerBasic::SpriteDrawerBasic(owner, shape, priority, pos, size);

	Vector2u wSize = _window->getSize();

	RectangleBasicDrawer::Resized();

	//dynamic_cast<RectangleShape>(_shape).;
	//Vector2u wSize = data.window->getSize();
	//RectangleShape* shapeTemp = dynamic_cast<RectangleShape*>(_shape.get());
	//RectangleShape shapeTemp = _shape;
	//shapeTemp->setSize(Vector2f((wSize.x * size.scale.x) + size.offset.x, (wSize.y * size.scale.y) + size.offset.y));
}