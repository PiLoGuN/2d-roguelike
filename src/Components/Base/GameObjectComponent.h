#pragma once

#include "../../Base/GameObjectBase.h"
#include "ComponentBase.h"

class GameObjectComponent: public ComponentBase {
	public:
		std::shared_ptr<GameObjectBase> GetOwner();

		void Start() override {};
		void Update(const float dTime, const UpdateData& data) override {};

		virtual std::string GetName() override { return "BASE OBJECT"; };

		//GameObjectComponent() { throw 2; }
		GameObjectComponent();
		GameObjectComponent(GameObjectBase& owner);
	private:
		std::shared_ptr<GameObjectBase> _owner;
};