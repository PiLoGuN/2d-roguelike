#pragma once
#include "../Base/GameObjectComponent.h"
#include "UnitHolder.h"

class Encounter : public GameObjectComponent {
	public:
		std::vector<UnitHolder>& GetHolders();
		UnitHolder& GetHolders(const int id);

		//using GameObjectComponent::GameObjectComponent;

		virtual std::string GetName() override { return "ENCOUNTER"; };

		void Start(const UpdateData& data) override;
		void Update(const float dTime, const UpdateData& data) override;

		Encounter(std::shared_ptr<GameObjectBase> owner, std::vector<UnitHolder>& holders, const UpdateData& data);
		~Encounter();
	private:
		std::shared_ptr<std::vector<UnitHolder>> _holders;
		void PositionHolderUnits();

		sf::Window* _window;
		int _transformCallbackId = -1;
};