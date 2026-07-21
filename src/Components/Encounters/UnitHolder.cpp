#include "UnitHolder.h"

UnitHolder::UnitHolder(std::vector<std::shared_ptr<GameObjectBase>> unitsTemp) {
	units = unitsTemp;
}

Vector2f UnitHolder::GetUnitPosition(int id) {
	return Vector2f((id)/5.0f - id/5, floor((id)/5) * 0.5) + Vector2f(0.125, 0.25);
}