#pragma once

//#include "../../Base/GameObjectBase.h"

#include "UpdateData.h"
#include <iostream>;

class ComponentBase {
	public:
		//GameObjectBase* GetOwner();

		virtual void Start(const UpdateData& data) {};
		//virtual void Update(const float dTime, const UpdateData& data) { std::cout << "Idiot :)" << std::endl; };
		virtual void Update(const float dTime, const UpdateData& data) { };

		virtual std::string GetName() { return "COMPONENT BASE"; };

		//ComponentBase(GameObjectBase* owner);
	//private:
	//	GameObjectBase* _gObject;
};