#pragma once

#include "../Components/Base/ComponentBase.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase : public ComponentBase {
	public:
		//ComponentBase** components = NULL;
		std::vector<ComponentBase*> components;

		GameObjectBase* GetParent();
		void SetParent(GameObjectBase* parent);

		Vector2f GetPosition() const;
		void SetPosition(Vector2f position);
		Vector2f GetGlobalPosition();

		void AddComponent(ComponentBase* component);
		void RemoveComponent(int id);
		void RemoveComponent(ComponentBase* component);
		int GetComponentCount() const;

		virtual void Start();
		virtual void Update(const float dTime, const UpdateData* data);

		GameObjectBase() = default;
	private:
		GameObjectBase* _parent = NULL;
		int _componentCount = 0;

		Vector2f _localPosition = Vector2f(0, 0);
};