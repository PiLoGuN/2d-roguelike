#pragma once

#include "../Base/GameObjectComponent.h"

class BasicMovement : public GameObjectComponent {
	public:
		float speed;
		sf::Shape& shapeToMove;

		BasicMovement(GameObjectBase& owner, sf::Shape& shape) : speed(1000), shapeToMove(shape) {};

		using GameObjectComponent::GameObjectComponent;

		void Start() override;
		void Update(const float dTime, const UpdateData& data) override;

		std::string GetName() override { return "MOVEMENT"; };

		void Move(Vector2f movement);
	private:
		Vector2f _movementBase;
		bool _dlp = false;
};