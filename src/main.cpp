#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Base/GameObjectHolder.h"
#include "Components/Movement/BasicMovement.h"
#include "Components/Drawer/SpriteDrawerBasic.h"
#include "Components/Encounters/Encounter.h"

using namespace sf;


int main()	
{
	sf::RenderWindow window( VideoMode( { 1200, 800 } ), "I'm on the leader, the one with the crown", sf::Style::Close | sf::Style::Titlebar);

	sf::Image icon;
	if (!icon.loadFromFile("assets/Images/Base/iconReal.png")) {
		std::cout << "Bad :(" << std::endl;
	}
	else {
		window.setIcon(icon);
		std::cout << "Good :)" << std::endl;
	}

	Clock clock;

	GameObjectHolder holder{};

	std::shared_ptr<GameObjectBase> encounter = std::make_shared<GameObjectBase>();

	std::shared_ptr<GameObjectBase> unit = std::make_shared<GameObjectBase>();
	std::shared_ptr<BaseUnit> unitB = std::make_shared<BaseUnit>();
	unitB->unitName = "Homuchmenok";
	unit->AddComponent(unitB);

	unit->SetParent(encounter);

	std::shared_ptr<sf::RectangleShape> rect = std::make_shared<sf::RectangleShape>(Vector2f(50, 50));
	rect->setOrigin(rect->getLocalBounds().getCenter());
	unit->AddComponent(std::make_shared<SpriteDrawerBasic>(unit, rect));

	std::vector<UnitHolder> holders = std::vector<UnitHolder>();
	holders.push_back(UnitHolder());
	holders.push_back(UnitHolder());

	holders[0].units.push_back(unit);

	encounter->AddComponent(std::make_shared<Encounter>(encounter, holders));


	std::cout << "GUNFIRE!" << std::endl;

	holder.AddObject(encounter);
	holder.AddObject(unit);

	UpdateData data = UpdateData();
	data.window = &window;

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
		}
		window.clear();
		float dt = clock.restart().asSeconds();

		data.time = time;
		time += dt;

		//encounter->Update(dt, data);
		holder.Update(dt, data);
		window.display();
	}
}