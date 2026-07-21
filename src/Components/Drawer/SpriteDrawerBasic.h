#pragma once

#include "../Base/GameObjectComponent.h"
#include "OffsetScalePair.h"
#include "RenderOrderer.h"

class SpriteDrawerBasic : public GameObjectComponent {
	public: 

		void Update(const float dTime, const UpdateData& data) override;
		void RenderUpdate(const float dTime, const UpdateData& data) override;

		//Prohibits this object from rendering itself 
		//bool customRendering;

		int renderOrder = 0;

		OffsetScalePair position;
		Vector2f size = Vector2f(1,1);

		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority, OffsetScalePair pos);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, int priority, OffsetScalePair pos, Vector2f size);

		~SpriteDrawerBasic();


		virtual std::string GetName() override { return "DRAWER"; };
	private:
		std::unique_ptr<sf::Shape> _shape;
};