#pragma once

//#include <iostream>
#include <vector>
#include <memory>
#include "GameObjectBase.h"
//#include <SFML/Graphics.hpp>

#include "../Components/Base/UpdateData.h"

class GameObjectHolder {
	public:
		void AddObject(std::shared_ptr<GameObjectBase> object);
		bool RemoveObject(int id);
		bool RemoveObject(GameObjectBase* object);
		std::shared_ptr<GameObjectBase> GetObject(int id);

		void Start(const UpdateData& data);
		void Update(const float dTime, const UpdateData& data);
	private:
		std::vector<std::shared_ptr<GameObjectBase>> _objects;
};