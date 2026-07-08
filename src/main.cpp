#include <iostream>
#include <SFML/Graphics.hpp>
#include "Base/GameObjectBase.cpp"
#include "Components/Movement/BasicMovement.h"
#include "Components/Debug/DebugComp.cpp"

using namespace sf;


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
	circle.AddComponent(new BasicMovement(&circle));

	((BasicMovement*)circle.components[0])->shapeToMove = &shape;

	circle.Start();

	while ( window.isOpen() )
	{
		window.setSize(Vector2u(800, 800));

		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<Event::Closed>()) {
				window.close();

				//delete[] circle.components;
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
