#include "RenderOrderer.h"
#include "SpriteDrawerBasic.h"

void RenderOrderer::Render(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < _renderingQueue.size(); i++)
	{
		_renderingQueue[i]->RenderUpdate(dTime, data);
	}
}

void RenderOrderer::AddRenderer(SpriteDrawerBasic* renderer) {
	if (_renderingQueue.size() <= 0) {
		_renderingQueue.push_back(renderer);
		return;
	}

	for (size_t i = 0; i < _renderingQueue.size(); i++)
	{
		if (_renderingQueue[i]->renderOrder > renderer->renderOrder) {
			_renderingQueue.insert(_renderingQueue.begin() + i, renderer);
			return;
		}
	}

	_renderingQueue.push_back(renderer);
}

void RenderOrderer::RemoveRenderer(SpriteDrawerBasic* renderer) {
	for (size_t i = 0; i < _renderingQueue.size(); i++)
	{
		if (_renderingQueue[i] == renderer) {
			_renderingQueue.erase(_renderingQueue.begin() + i);
			return;
		}
	}
}

RenderOrderer& RenderOrderer::GetRenderer() {
	static RenderOrderer rend;

	return rend;
}