#include "Encounter.h"
#include "../Drawer/SpriteDrawerBasic.h"

std::vector<UnitHolder>& Encounter::GetHolders() {
	return _holders;
}
UnitHolder& Encounter::GetHolders(const int id) {
	return _holders[id];
}

Encounter::Encounter(GameObjectBase& owner) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	//_holders = std::vector<UnitHolder>(2);

	sf::RectangleShape rectTop = sf::RectangleShape(Vector2f(800, 300));
	sf::RectangleShape rectBot = sf::RectangleShape(Vector2f(800, 300));

	SpriteDrawerBasic topDrawer(owner, rectTop, OffsetScalePair());
	SpriteDrawerBasic botDrawer(owner, rectTop);

	owner.AddComponent(topDrawer);
	owner.AddComponent(botDrawer);
}
Encounter::~Encounter() {
	
}
