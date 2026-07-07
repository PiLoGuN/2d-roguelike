#pragma once

#include "../Components/Base/ComponentBase.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase : public ComponentBase {
	public:
		GameObjectBase* GetParent() const;
		void SetParent(GameObjectBase* parent);
		Vector2f GetPosition() const;
		void SetPosition(Vector2f position);

		Vector2f GetGlobalPosition() const;

		ComponentBase** components = NULL;
		int componentCount = 0;

		virtual void Start();
		virtual void Update(float dTime);

		GameObjectBase() = default;
	private:
		GameObjectBase* _parent = NULL;

		Vector2f _localPosition = Vector2f(0, 0);

};