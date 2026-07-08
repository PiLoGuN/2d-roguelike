#pragma once

//#include "../../Base/GameObjectBase.h"

class ComponentBase {
	public:
		//GameObjectBase* GetOwner();

		virtual void Start() {};
		virtual void Update(const float dTime) {};

		//ComponentBase(GameObjectBase* owner);
	//private:
	//	GameObjectBase* _gObject;
};