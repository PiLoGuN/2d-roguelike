#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Components/Movement/BasicMovement.h"

using namespace sf;

static Vector2f GetDirVector(int dir) {
	if (dir == 0) {
		return Vector2f(0, 1);
	}
	else if (dir == 1) {
		return Vector2f(-1, 0);
	}
	else if (dir == 2) {
		return Vector2f(0, -1);
	}
	else {
		return Vector2f(1, 0);
	}
}


int main()	
{
	RenderWindow window( VideoMode( { 800, 800 } ), "I'm going to die making this!" );

	CircleShape shape( 200.f );
	shape.setPointCount(100);
	shape.setFillColor( Color::Green );

	shape.setPosition(Vector2f(0, 0));

	int count = 0;
	int dir = 3;
	float dist = 0;

	float speed = 600;	

	Clock clock;

	GameObjectBase circle = GameObjectBase();
	circle.SetPosition(Vector2f(2, 1));
	circle.componentCount = 1;
	//circle.components = new ComponentBase* [1] { new DebugComp(&circle) };
	circle.components = new ComponentBase * [1] { new BasicMovement(&circle) };

	circle.Start();

	while ( window.isOpen() )
	{
		window.setSize(Vector2u(800, 800));

		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<Event::Closed>()) {
				window.close();

				for (size_t i = 0; i < circle.componentCount; i++)
				{
					delete circle.components[i];
				}
				delete circle.components;
				return 0;
			}
		}
		if (dist > 400) {
			dist = 0;
			dir++;
			if (dir > 3) {
				dir = 0;
			}
		}

		float dt = clock.restart().asSeconds();

		//shape.setPosition(shape.getPosition() + GetDirVector(dir) * dt * speed);
		count = 0;
		dist += dt * speed;

		circle.Update(dt);

		//std::cout << dt << std::endl;

		window.clear();
		window.draw( shape );
		window.display();
	}
}
