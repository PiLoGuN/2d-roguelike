#include "Encounter.h"
#include "../Drawer/SpriteDrawerBasic.h"

std::vector<UnitHolder>& Encounter::GetHolders() {
	return *_holders;
}
UnitHolder& Encounter::GetHolders(const int id) {
	return (*_holders)[id];
}

const float HOLDER_WIDTH = 800;
const float HOLDER_HEIGHT = 200;

Encounter::Encounter(std::shared_ptr<GameObjectBase> owner, std::vector<UnitHolder>& holdersT) : GameObjectComponent(owner) {
	_holders = std::make_unique<std::vector<UnitHolder>>(holdersT);
	std::unique_ptr<RectangleShape> rectTop = std::make_unique<RectangleShape>(Vector2f(HOLDER_WIDTH, HOLDER_HEIGHT));
	std::unique_ptr<RectangleShape> rectBot = std::make_unique<RectangleShape>(Vector2f(HOLDER_WIDTH, HOLDER_HEIGHT));
	//std::shared_ptr<RectangleShape> rectDialog = std::make_shared<RectangleShape>(Vector2f(2000, 300));

	rectTop->setOrigin(rectTop->getLocalBounds().getCenter());
	rectBot->setOrigin(rectBot->getLocalBounds().getCenter());

	rectTop->setOutlineThickness(3);
	rectBot->setOutlineThickness(3);

	rectTop->setFillColor(sf::Color(180, 180, 180));
	rectBot->setFillColor(sf::Color(180, 180, 180));

	rectTop->setOutlineColor(sf::Color(130, 130, 130));
	rectBot->setOutlineColor(sf::Color(130, 130, 130));

	owner->AddComponent(std::move(std::make_unique<SpriteDrawerBasic>(owner, std::move(rectTop), 0, OffsetScalePair(Vector2f(0.5, 0.17)))));
	owner->AddComponent(std::move(std::make_unique<SpriteDrawerBasic>(owner, std::move(rectBot), 0, OffsetScalePair(Vector2f(0.5, 0.47)))));
}
Encounter::~Encounter() {
	
}

void Encounter::Start(const UpdateData& data) {
	for (size_t i = 0; i < _holders->size(); i++)
	{
		for (size_t y = 0; y < (*_holders)[i].units.size(); y++)
		{
			GameObjectBase& unit = *((*_holders)[i].units[y]);
			//unit.SetPosition(OffsetScalePair::ScaleToOffset(*data.window, Vector2f(0.5 + y * 0.1, 0.17)) );
			//unit.SetPosition(OffsetScalePair::ScaleToOffset(*data.window, (*_holders)[i].GetUnitPosition(y) * 0.85f) + Vector2f(25, 25));
			unit.SetPosition(OffsetScalePair::ScaleToOffset(*data.window, (*_holders)[i].GetUnitPosition(y)));
			std::cout << y << " " << (*_holders)[i].GetUnitPosition(y).x << " " << (*_holders)[i].GetUnitPosition(y).y << std::endl;
		}
	}
}

void Encounter::Update(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < _holders->size(); i++)
	{
		for (size_t y = 0; y < (*_holders)[i].units.size(); y++)
		{
			GameObjectBase& unit = *((*_holders)[i].units[y]);

			//unit.SetPosition(OffsetScalePair::ScaleToOffset(*data.window, Vector2f(0.5 + y * 0.1, 0.17)) + Vector2f(cos(data.time * 3), sin(data.time * 3)) * 30.0f);
		}
	}
	//std::cout << "Yuu" << std::endl;
	//std::cout << _holders->size() << std::endl;
	//std::cout << (*_holders)[0].units.size() << std::endl;
	//std::cout << (*_holders)[1].units.size() << std::endl;
}


