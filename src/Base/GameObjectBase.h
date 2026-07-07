#pragma once

#include "../Components/Base/ComponentBase.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase: public ComponentBase {
	public:
		GameObjectBase* parent;
		ComponentBase** components;
		int componentCount;
		Vector2f position;

		virtual void Start() override;
		virtual void Update(float dTime) override;

		GameObjectBase() = default;
	private:
		
};