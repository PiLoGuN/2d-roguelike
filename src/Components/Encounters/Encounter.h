#pragma once
#include "../Base/GameObjectComponent.h"
#include "UnitHolder.h"

class Encounter : public GameObjectComponent {
	public:
		std::vector<UnitHolder>& GetHolders();
		UnitHolder& GetHolders(const int id);

			using GameObjectComponent::GameObjectComponent;

		Encounter(GameObjectBase& owner);
		~Encounter();
	private:
		std::vector<UnitHolder> _holders;
};