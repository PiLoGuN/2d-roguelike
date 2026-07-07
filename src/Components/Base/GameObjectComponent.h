#pragma once

#include "../../Base/GameObjectBase.h"
#include "ComponentBase.h"

class GameObjectComponent: public ComponentBase {
	public:
		GameObjectBase* GetOwner();

		GameObjectComponent(GameObjectBase* owner);
	private:
		GameObjectBase* _owner;
};