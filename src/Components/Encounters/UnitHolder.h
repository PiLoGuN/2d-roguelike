#pragma once

#include "../Units/BaseUnit.h"

struct UnitHolder {
	Vector2f holderPosition;

	//std::vector<GameObjectBase&> units;
	std::vector<std::shared_ptr<GameObjectBase>> units;
};