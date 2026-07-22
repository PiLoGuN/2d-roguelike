#include "Encounter.h"
//#include "../Drawer/SpriteDrawerBasic.h"
#include "../Drawer/Drawers/RectangleBasicDrawer.h"

std::vector<UnitHolder>& Encounter::GetHolders() {
	return *_holders;
}
UnitHolder& Encounter::GetHolders(const int id) {
	return (*_holders)[id];
}

const float HOLDER_WIDTH = 800;
const float HOLDER_HEIGHT = 200;

float lerp(float a, float b, float f)
{
	return a * (1.0f - f) + (b * f);
}

Encounter::Encounter(std::shared_ptr<GameObjectBase> owner, std::vector<UnitHolder>& holdersT, const UpdateData& data) : GameObjectComponent(owner) {
	_holders = std::make_unique<std::vector<UnitHolder>>(holdersT);
	std::unique_ptr<RectangleShape> rectTop = std::make_unique<RectangleShape>(Vector2f(HOLDER_WIDTH, HOLDER_HEIGHT));
	std::unique_ptr<RectangleShape> rectBot = std::make_unique<RectangleShape>(Vector2f(HOLDER_WIDTH, HOLDER_HEIGHT));
	//std::unique_ptr<RectangleShape> rectTop = std::make_unique<RectangleShape>();
	//std::unique_ptr<RectangleShape> rectBot = std::make_unique<RectangleShape>();
	//std::shared_ptr<RectangleShape> rectDialog = std::make_shared<RectangleShape>(Vector2f(2000, 300));

	rectTop->setOrigin(rectTop->getLocalBounds().getCenter());
	rectBot->setOrigin(rectBot->getLocalBounds().getCenter());

	rectTop->setOutlineThickness(3);
	rectBot->setOutlineThickness(3);

	rectTop->setFillColor(sf::Color(180, 180, 180));
	rectBot->setFillColor(sf::Color(180, 180, 180));

	rectTop->setOutlineColor(sf::Color(130, 130, 130));
	rectBot->setOutlineColor(sf::Color(130, 130, 130));

	(*_holders)[0].holderPosition = Vector2f(0.5, 0.17);
	(*_holders)[1].holderPosition = Vector2f(0.5, 0.47);

	Vector2f rectScale = OffsetScalePair::OffsetToScale(*data.window, Vector2f(HOLDER_WIDTH, HOLDER_HEIGHT));

	//Vector2 rectScale = Vector2f(0.75, 0.175);

	owner->AddComponent(std::move(std::make_unique<RectangleBasicDrawer>(owner, std::move(rectTop), data, 0, OffsetScalePair(Vector2f(0.5, 0.17)), OffsetScalePair(rectScale)) ));
	owner->AddComponent(std::move(std::make_unique<RectangleBasicDrawer>(owner, std::move(rectBot), data, 0, OffsetScalePair(Vector2f(0.5, 0.47)), OffsetScalePair(rectScale)) ));

	_window = data.window;
	
	_transformCallbackId = owner->transformUpdated.size();
	owner->transformUpdated.push_back([this]() {
		this->PositionHolderUnits();
	});
}
Encounter::~Encounter() {
	GetOwner()->transformUpdated.erase(GetOwner()->transformUpdated.begin() + _transformCallbackId);
}

void Encounter::PositionHolderUnits() {

	std::cout << "YES i'AM" << std::endl;


	for (size_t i = 0; i < _holders->size(); i++)
	{
		for (size_t y = 0; y < (*_holders)[i].units.size(); y++)
		{
			GameObjectBase& unit = *((*_holders)[i].units[y]);

			Vector2f position = (*_holders)[i].GetUnitPosition(y);
			position = Vector2f(Vector2f(lerp(-HOLDER_WIDTH / 2, HOLDER_WIDTH / 2, position.x), lerp(-HOLDER_HEIGHT / 2, HOLDER_HEIGHT / 2, position.y)));
			position.x += (*_holders)[i].holderPosition.x * _window->getSize().x;
			position.y += (*_holders)[i].holderPosition.y * _window->getSize().y;
			unit.SetPosition(position);
		}
	}
}

void Encounter::Start(const UpdateData& data) {
	PositionHolderUnits();
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
}


