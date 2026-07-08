#pragma once

#include "../Base/GameObjectComponent.h"

class BasicMovement : public GameObjectComponent {
	public:
		float speed;
		CircleShape* shapeToMove;

		BasicMovement(GameObjectBase* owner) : GameObjectComponent(owner), speed(1000), shapeToMove(NULL) {};

		void Start() override;
		void Update(const float dTime) override;

		void Move(Vector2f movement);
	private:
		Vector2f _movementBase;
		bool _dlp = false;
};