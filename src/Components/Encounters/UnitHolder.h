#pragma once

#include "../Units/BaseUnit.h"

struct UnitHolder {
	Vector2f holderPosition;

	BaseUnit** units;
};