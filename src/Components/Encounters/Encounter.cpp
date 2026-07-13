#include "Encounter.h"
#include "../Drawer/SpriteDrawerBasic.h"

std::vector<UnitHolder>& Encounter::GetHolders() {
	return _holders;
}
UnitHolder& Encounter::GetHolders(const int id) {
	return _holders[id];
}

Encounter::Encounter(std::shared_ptr<GameObjectBase> owner) : GameObjectComponent(owner) {
	std::shared_ptr<RectangleShape> rectTop = std::make_shared<RectangleShape>(Vector2f(800, 200));
	std::shared_ptr<RectangleShape> rectBot = std::make_shared<RectangleShape>(Vector2f(800, 200));
	//std::shared_ptr<RectangleShape> rectDialog = std::make_shared<RectangleShape>(Vector2f(2000, 300));

	rectTop->setOrigin(rectTop->getLocalBounds().getCenter());
	rectBot->setOrigin(rectBot->getLocalBounds().getCenter());

	rectTop->setOutlineThickness(3);
	rectBot->setOutlineThickness(3);

	rectTop->setFillColor(sf::Color(180, 180, 180));
	rectBot->setFillColor(sf::Color(180, 180, 180));

	rectTop->setOutlineColor(sf::Color(130, 130, 130));
	rectBot->setOutlineColor(sf::Color(130, 130, 130));

	owner->AddComponent(std::make_shared<SpriteDrawerBasic>(owner, rectTop, OffsetScalePair(Vector2f(0.5, 0.17))));
	owner->AddComponent(std::make_shared<SpriteDrawerBasic>(owner, rectBot, OffsetScalePair(Vector2f(0.5, 0.47))));
}
Encounter::~Encounter() {
	
}


