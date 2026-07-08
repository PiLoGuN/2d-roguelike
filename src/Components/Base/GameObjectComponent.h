#pragma once

#include "../../Base/GameObjectBase.h"
#include "ComponentBase.h"

class GameObjectComponent: public ComponentBase {
	public:
		GameObjectBase* GetOwner();

		void Start() override {};
		void Update(const float dTime) override {};

		GameObjectComponent() { throw 2; }
		GameObjectComponent(GameObjectBase* owner);
	private:
		GameObjectBase* _owner;
};