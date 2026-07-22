#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Base/GameObjectHolder.h"
#include "Components/Movement/BasicMovement.h"
//#include "Components/Drawer/SpriteDrawerBasic.h"
#include "Components/Drawer/Drawers/RectangleBasicDrawer.h"
#include "Components/Encounters/Encounter.h"
#include "Components/Drawer/RenderOrderer.h"

using namespace sf;

std::shared_ptr<GameObjectBase> createTestUnit(GameObjectHolder& holder, std::shared_ptr<GameObjectBase>& enc, const UpdateData& data) {
	std::shared_ptr<GameObjectBase> unit = std::make_shared<GameObjectBase>();
	std::unique_ptr<BaseUnit> unitB = std::make_unique<BaseUnit>();
	unitB->unitName = "Homuchmenok";

	unit->AddComponent(std::move(unitB));

	std::unique_ptr<sf::RectangleShape> rect = std::make_unique<sf::RectangleShape>(Vector2f(50, 50));
	rect->setOrigin(rect->getLocalBounds().getCenter());
	rect->setFillColor(sf::Color(163, 0, 0));

	unit->AddComponent(std::move(std::make_unique<RectangleBasicDrawer>(unit, std::move(rect), data, 1, OffsetScalePair(), OffsetScalePair(Vector2f(0, 0), Vector2f(50, 50)))));

	holder.AddObject(unit);

	unit->SetParent(enc);

	return unit;
}


int main()	
{
	//sf::RenderWindow window( VideoMode( { 1200, 800 } ), "I'm on the leader, the one with the crown", sf::Style::Close | sf::Style::Titlebar);
	float screenWidth = 1920.f;
	float screenHeight = 1080.f;
	//sf::RenderWindow window(VideoMode({ 1920, 1080 }), "I'm on the leader, the one with the crown", sf::Style::Fullscreen);
	sf::RenderWindow window(VideoMode({ 1920, 1080 }), "I'm on the leader, the one with the crown", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

	window.setFramerateLimit(200);

	sf::Image icon;
	if (!icon.loadFromFile("assets/Images/Base/iconReal.png")) {
		std::cout << "Bad :(" << std::endl;
	}
	else {
		window.setIcon(icon);
		std::cout << "Good :)" << std::endl;
	}

	Clock clock;

	UpdateData data = UpdateData();
	data.window = &window;

	GameObjectHolder holder{};

	std::shared_ptr<GameObjectBase> encounter = std::make_shared<GameObjectBase>();

	std::vector<UnitHolder> holders = std::vector<UnitHolder>();
	holders.push_back(UnitHolder());
	holders.push_back(UnitHolder());

	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));
	holders[0].units.push_back(createTestUnit(holder, encounter, data));

	encounter->AddComponent(std::move(std::make_unique<Encounter>(encounter, holders, data)));

	std::cout << "GUNFIRE!" << std::endl;

	holder.AddObject(encounter);

	//encounter->Start();
	holder.Start(data);

	float time = 0;

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<Event::Closed>()) {
				window.close();

				return 0;
			}
			if (event->is<sf::Event::Resized>()) {
				//RenderOrderer::GetRenderer().Resized();
				std::cout << "RESIZED" << std::endl;

				if (const auto* resized = event->getIf<sf::Event::Resized>())
				{
					// update the view to the new size of the window
					//sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
					//window.setView(sf::View(visibleArea));

					sf::Vector2u size = window.getSize();
					float  heightRatio = screenHeight / screenWidth;
					float  widthRatio = screenWidth / screenHeight;

					if (size.y * widthRatio <= size.x)
					{
						size.x = size.y * widthRatio;
					}
					else if (size.x * heightRatio <= size.y)
					{
						size.y = size.x * heightRatio;
					}

					window.setSize(size);
				}

				//RenderOrderer::GetRenderer().Resized();
			}

		}
		window.clear();
		float dt = clock.restart().asSeconds();

		data.time = time;
		time += dt;

		//encounter->Update(dt, data);
		holder.Update(dt, data);
		//holder.RenderUpdate(dt, data);
		RenderOrderer::GetRenderer().Render(dt, data);
		window.display();
	}
}