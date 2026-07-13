#pragma once

#include "../../Base/GameObjectBase.h"
#include "ComponentBase.h"

class GameObjectComponent: public ComponentBase {
	public:
		//Raw, why raw?
		//The parent object should NEVER get out of scope before the component does, and this function's result shouldn't really be stored
		//p.s. to myself, please don't store it
		//Anyway, if the owner doesn't exist, neither does this component
		GameObjectBase* GetOwner();
		//For some time i will really really need a smart pointer, might be redundant, but we'll see
		std::shared_ptr<GameObjectBase> GetOwnerSmart();

		void Start() override {};
		void Update(const float dTime, const UpdateData& data) override {};

		virtual std::string GetName() override { return "BASE OBJECT"; };

		//GameObjectComponent() { throw 2; }
		GameObjectComponent();
		GameObjectComponent(std::shared_ptr<GameObjectBase> owner);
	private:
		std::shared_ptr<GameObjectBase> _owner;
};