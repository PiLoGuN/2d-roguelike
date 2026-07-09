#pragma once

#include "../Base/GameObjectComponent.h"

class BasicMovement : public GameObjectComponent {
	public:
		float speed;
		sf::Shape* shapeToMove;

		BasicMovement(GameObjectBase* owner) : GameObjectComponent(owner), speed(1000), shapeToMove(NULL) {};

		void Start() override;
		void Update(const float dTime, const UpdateData* data) override;

		void Move(Vector2f movement);
	private:
		Vector2f _movementBase;
		bool _dlp = false;
};