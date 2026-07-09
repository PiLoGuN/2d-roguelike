#pragma once

//#include "../../Base/GameObjectBase.h"

#include "UpdateData.h"

class ComponentBase {
	public:
		//GameObjectBase* GetOwner();

		virtual void Start() {};
		virtual void Update(const float dTime, const UpdateData* data) {};

		//ComponentBase(GameObjectBase* owner);
	//private:
	//	GameObjectBase* _gObject;
};