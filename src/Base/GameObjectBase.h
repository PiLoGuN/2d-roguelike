#pragma once

#include "../Components/Base/ComponentBase.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase : public ComponentBase {
	public:
		//ComponentBase** components = NULL;
		//std::vector<std::shared_ptr<ComponentBase>> components;
		std::vector<ComponentBase*> components;

		std::shared_ptr<GameObjectBase> GetParent();
		void SetParent(std::shared_ptr<GameObjectBase> parent);

		Vector2f GetPosition() const;
		void SetPosition(Vector2f position);
		Vector2f GetGlobalPosition();

		void AddComponent(ComponentBase& component);
		void RemoveComponent(int id);
		void RemoveComponent(ComponentBase& component);
		int GetComponentCount() const;

		virtual void Start();
		virtual void Update(const float dTime, const UpdateData& data);

		GameObjectBase();
		GameObjectBase(Vector2f pos);
	private:
		std::shared_ptr<GameObjectBase> _parent;
		//GameObjectBase _parent = NULL;
		int _componentCount = 0;

		Vector2f _localPosition = Vector2f(0, 0);
};