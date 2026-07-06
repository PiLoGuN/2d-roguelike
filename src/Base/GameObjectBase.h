#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase {
	public:
		Vector2f position;

		void Start();
		void Update(float dTime);

		GameObjectBase();
	private:
		
};