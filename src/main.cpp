#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Components/Movement/BasicMovement.h"
#include "Components/Drawer/SpriteDrawerBasic.h"

using namespace sf;


int main()	
{
	std::cout << "INVASION";

	sf::RenderWindow window( VideoMode( { 1200, 800 } ), "I'm on the leader, the one with the crown", sf::Style::Close | sf::Style::Titlebar );

	sf::Image icon;
	if (!icon.loadFromFile("assets/Images/Base/iconReal.png")) {
		std::cout << "Bad :(";
	}
	else {
		window.setIcon(icon);
		std::cout << "Good :)";
	}

	Clock clock;

	GameObjectBase encounter = GameObjectBase();

	sf::CircleShape circ = CircleShape(100, 100);

	BasicMovement* move = new BasicMovement(&encounter);
	move->shapeToMove = &circ;
	encounter.AddComponent(move);
	encounter.AddComponent(new SpriteDrawerBasic(&encounter, &circ, OffsetScalePair(Vector2f(0.1, 0.1), Vector2f(200, 200)), OffsetScalePair(Vector2f(0.1, 0.1), Vector2f(200, 200))));



	std::cout << "GUNFIRE!";

	encounter.Start();

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<Event::Closed>()) {
				window.close();

				return 0;
			}
		}
		float dt = clock.restart().asSeconds();

		UpdateData data = UpdateData();
		data.window = &window;

		for (size_t i = 0; i < encounter.GetComponentCount(); i++)
		{
			encounter.components[i]->Update(dt, &data);
		}

		window.clear();
		window.display();
	}
}
