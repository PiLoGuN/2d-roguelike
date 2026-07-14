#pragma once

#include "../Units/BaseUnit.h"

struct UnitHolder {
	Vector2f holderPosition;

	//std::vector<GameObjectBase&> units;
	//std::vector<std::shared_ptr<GameObjectBase>> units;
	std::vector<std::shared_ptr<GameObjectBase>> units;

	UnitHolder() = default;
	UnitHolder(std::vector<std::shared_ptr<GameObjectBase>> unitsTemp);

	//UnitHolder() : holderPosition(Vector2f(0, 0)) = default;
};