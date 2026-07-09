#pragma once

#include "../Base/GameObjectComponent.h"

struct OffsetScalePair {
	Vector2f scale;
	Vector2f offset;

	OffsetScalePair() = default;

	OffsetScalePair(Vector2f scaleT, Vector2f offsetT) {
		scale = scaleT;
		offset = offsetT;
	}
};

class SpriteDrawerBasic : public GameObjectComponent {
	public: 

		void Update(const float dTime, const UpdateData* data) override;

		OffsetScalePair position;
		OffsetScalePair size;

		SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape);
		SpriteDrawerBasic(GameObjectBase* owner, sf::Shape* shape, OffsetScalePair pos, OffsetScalePair size);
	private:
		sf::Shape* _shape;
		
};