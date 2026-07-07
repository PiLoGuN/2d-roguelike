#pragma once

#include "../Base/GameObjectComponent.h"

class BasicMovement : public GameObjectComponent {
	public:
		float speed;
		CircleShape shapeToMove;

		BasicMovement(GameObjectBase* owner) : GameObjectComponent(owner) {};

		void Start() {};
		void Update(float dTime) override;

		void Move(Vector2f movement);
	private:
		
};