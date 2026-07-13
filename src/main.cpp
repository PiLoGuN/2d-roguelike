#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Components/Movement/BasicMovement.h"
#include "Components/Drawer/SpriteDrawerBasic.h"
#include "Components/Encounters/Encounter.h"

using namespace sf;


int main()	
{
	std::cout << "INVASION" << std::endl;

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

	std::shared_ptr<GameObjectBase> encounter = std::make_shared<GameObjectBase>();

	sf::CircleShape circ = CircleShape(100, 100);
	//sf::CircleShape circ2 = new CircleShape(100, 100);

	encounter->AddComponent(std::make_shared<Encounter>(encounter));
	//encounter->AddComponent(std::make_shared<SpriteDrawerBasic>(encounter, circ, OffsetScalePair(Vector2f(0.5, 0.25), Vector2f(-100, -100)), Vector2f(1,1)));
	//encounter->AddComponent(SpriteDrawerBasic(encounter, circ2, OffsetScalePair(Vector2f(0.5, 0.75), Vector2f(-100, -100)), Vector2f(1, 1)));
	//encounter->AddComponent(std::make_shared<BasicMovement>(encounter, circ));

	//std::cout << encounter->components[0]->GetName() << std::endl;

	std::cout << "GUNFIRE!" << std::endl;

	encounter->Start();

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

		UpdateData data = UpdateData();
		data.window = &window;

		encounter->Update(dt, data);
		/*for (size_t i = 0; i < encounter.GetComponentCount(); i++)
		{
			//std::cout << encounter.components[i]->GetName() << std::endl;
			encounter.components[i]->Update(dt, data);
		}*/
		window.display();
	}
}

/*void ChangeNPrint(GameObjectBase& object) {

}*/