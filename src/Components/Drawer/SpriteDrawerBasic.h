#pragma once

#include "../Base/GameObjectComponent.h"
#include "OffsetScalePair.h"

class SpriteDrawerBasic : public GameObjectComponent {
	public: 

		void Update(const float dTime, const UpdateData& data) override;

		OffsetScalePair position;
		Vector2f size = Vector2f(1,1);

		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape, OffsetScalePair pos);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::shared_ptr<sf::Shape> shape, OffsetScalePair pos, Vector2f size);

		virtual std::string GetName() override { return "DRAWER"; };
	private:
		std::shared_ptr<sf::Shape> _shape;
		
};