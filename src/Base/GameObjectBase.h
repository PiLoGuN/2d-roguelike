#pragma once

#include "../Components/Base/ComponentBase.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObjectBase : public ComponentBase {
	public:
		GameObjectBase();
		GameObjectBase(Vector2f pos);


		//This should not be stored, it's raw, real fucking raw
		//std::shared_ptr<GameObjectBase>& GetParent();
		GameObjectBase* GetParent();
		void SetParent(std::shared_ptr<GameObjectBase> parent);

		Vector2f GetPosition() const;
		void SetPosition(Vector2f position);
		Vector2f GetGlobalPosition();

		void AddComponent(std::shared_ptr<ComponentBase> component);
		void RemoveComponent(int id);
		void RemoveComponent(ComponentBase* component);
		std::shared_ptr<ComponentBase> GetComponent(int id);
		int GetComponentCount() const;

		virtual void Start(const UpdateData& data);
		virtual void Update(const float dTime, const UpdateData& data);
	private:
		std::shared_ptr<GameObjectBase> _parent = nullptr;
		std::vector<std::shared_ptr<ComponentBase>> _components;
		//GameObjectBase _parent = NULL;
		int _componentCount = 0;

		Vector2f _localPosition = Vector2f(0, 0);
};