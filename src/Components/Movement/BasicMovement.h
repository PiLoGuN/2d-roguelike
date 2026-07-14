#pragma once

#include "../Base/GameObjectComponent.h"

class BasicMovement : public GameObjectComponent {
	public:
		float speed;
		std::shared_ptr<sf::Shape> shapeToMove;

		BasicMovement(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape) : GameObjectComponent(owner), speed(1000), shapeToMove(shape) {};

		//using GameObjectComponent::GameObjectComponent;

		void Start(const UpdateData& data) override;
		void Update(const float dTime, const UpdateData& data) override;

		std::string GetName() override { return "MOVEMENT"; };

		void Move(Vector2f movement);
	private:
		Vector2f _movementBase;
		bool _dlp = false;
};