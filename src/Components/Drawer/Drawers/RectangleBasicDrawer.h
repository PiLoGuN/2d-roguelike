#pragma once
#include "../SpriteDrawerBasic.h"

class RectangleBasicDrawer : public SpriteDrawerBasic {
	public:
		void Resized() override;

		RectangleBasicDrawer(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos, OffsetScalePair size);

		//enum ScalingType{};
	private:
};