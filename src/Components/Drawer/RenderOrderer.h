#pragma once

#include <memory>
#include <vector>
#include "../Base/UpdateData.h"
//#include "SpriteDrawerBasic.h"

class SpriteDrawerBasic;

class RenderOrderer {
	public:
		static RenderOrderer& GetRenderer();

		void Render(const float dTime, const UpdateData& data);
		void Resized();

		void AddRenderer(SpriteDrawerBasic* renderer);
		void RemoveRenderer(SpriteDrawerBasic* renderer);

		RenderOrderer() = default;
		RenderOrderer(RenderOrderer const&) = delete;
		void operator=(RenderOrderer const&) = delete;
	private:
		//Genuinely a bad idea, i made components unique for the reason of not needing them owned anywhere outside the GameObject,
		//However, this should HOPEFULLY be fine, because all renderers in their destructor call RemoveRenderer, which in turn will remove this pointer
		std::vector<SpriteDrawerBasic*> _renderingQueue;

		//static RenderOrderer* singleton;
};
