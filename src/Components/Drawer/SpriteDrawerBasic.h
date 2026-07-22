#pragma once

#include "../Base/GameObjectComponent.h"
#include "OffsetScalePair.h"
#include "RenderOrderer.h"

class SpriteDrawerBasic : public GameObjectComponent {
	public: 

		void Update(const float dTime, const UpdateData& data) override;
		void RenderUpdate(const float dTime, const UpdateData& data) override;

		virtual void Resized() = 0;

		//Prohibits this object from rendering itself 
		//bool customRendering;

		int renderOrder = 0;

		OffsetScalePair position;
		OffsetScalePair size;

		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos);
		SpriteDrawerBasic(std::shared_ptr<GameObjectBase> owner, std::unique_ptr<sf::Shape> shape, const UpdateData& data, int priority, OffsetScalePair pos, OffsetScalePair size);

		~SpriteDrawerBasic();


		virtual std::string GetName() override { return "DRAWER"; };
	protected:
		std::unique_ptr<sf::Shape> _shape;

		int _transformCallbackId = -1;
		//Window should ALWAYS outlive the renderers
		sf::Window* _window;
};