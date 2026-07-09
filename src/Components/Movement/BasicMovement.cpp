#include "BasicMovement.h"
#include <iostream>

static Vector2f GetDirVector(int dir) {
	if (dir == 0) {
		return Vector2f(0, 1);
	}
	else if (dir == 1) {
		return Vector2f(-1, 0);
	}
	else if (dir == 2) {
		return Vector2f(0, -1);
	}
	else {
		return Vector2f(1, 0);
	}
}


void BasicMovement::Update(const float dTime, const UpdateData* data) {

	_movementBase = Vector2f(0, 0);

	//std::cout << "ss";

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		_movementBase += -GetDirVector(0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		_movementBase += GetDirVector(1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		_movementBase += -GetDirVector(2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		_movementBase += GetDirVector(3);
	}

	if (_movementBase.length() > 0) {

		//std::cout << dTime << " " << _movementBase.x << " " << speed << std::endl;

		_movementBase = _movementBase.normalized() * speed * dTime;

		if (Keyboard::isKeyPressed(Keyboard::Key::B) && !_dlp) {
			std::cout << _movementBase.x << " " << _movementBase.y << std::endl;
			std::cout << shapeToMove->getPosition().x << " " << shapeToMove->getPosition().y << std::endl;
		}
		_dlp = Keyboard::isKeyPressed(Keyboard::Key::B);
	}

	//std::cout << dTime << std::endl;
	
	Move(_movementBase);
}

void BasicMovement::Start() {
	//std::cout << shapeToMove->getRadius();
}

void BasicMovement::Move(Vector2f movement) {
	GetOwner()->SetPosition(GetOwner()->GetPosition() + movement);
	Vector2f pos = GetOwner()->GetPosition();
	shapeToMove->setPosition(pos);
	//pos = shapeToMove->getPosition();
	//std::cout << pos.x << ", " << pos.y << std::endl;
}