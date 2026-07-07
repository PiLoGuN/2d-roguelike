#include "BasicMovement.h"
#include <iostream>

void BasicMovement::Update(float dTime) override {

	Vector2f movementBase = Vector2f(0, 0);

	std::cout << "ss";

	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		//GetOwner()->SetPosition(GetOwner()->GetPosition() + Vector2f(0.01, 0));
		movementBase = Vector2f(0.01, 0);
	}
	Move(movementBase);
}

void BasicMovement::Move(Vector2f movement) {
	GetOwner()->SetPosition(GetOwner()->GetPosition() + movement);

}