#include <iostream>
#include <SFML/Graphics.hpp>

static sf::Vector2f GetDirVector(int dir) {
	if (dir == 0) {
		return sf::Vector2f(0, 1);
	}
	else if (dir == 1) {
		return sf::Vector2f(-1, 0);
	}
	else if (dir == 2) {
		return sf::Vector2f(0, -1);
	}
	else {
		return sf::Vector2f(1, 0);
	}
}


int main()	
{
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "I'm going to die making this!" );

	sf::CircleShape shape( 200.f );
	shape.setPointCount(100);
	shape.setFillColor( sf::Color::Green );

	shape.setPosition(sf::Vector2f(0, 0));

	int count = 0;
	int dir = 3;
	float dist = 0;

	float speed = 600;	

	sf::Clock clock;

	while ( window.isOpen() )
	{
		window.setSize(sf::Vector2u(800, 800));

		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}
		if (dist > 400) {
			dist = 0;
			dir++;
			if (dir > 3) {
				dir = 0;
			}
		}

		float dt = clock.restart().asSeconds();

		shape.setPosition(shape.getPosition() + GetDirVector(dir) * dt * speed);
		count = 0;
		dist += dt * speed;

		//std::cout << dt << std::endl;

		window.clear();
		window.draw( shape );
		window.display();
	}
}
