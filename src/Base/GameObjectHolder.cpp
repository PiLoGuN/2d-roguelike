#include "GameObjectHolder.h"

typedef std::shared_ptr<GameObjectBase> objectSharedPtr;

void GameObjectHolder::AddObject(objectSharedPtr object) {
	_objects.push_back(object);
}
objectSharedPtr GameObjectHolder::GetObject(int id) {
	return _objects[id];
}

//void GameObjectHolder::AddObject(std::shared_ptr<GameObjectBase> object)
//{}

bool GameObjectHolder::RemoveObject(int id) {
	_objects.erase(_objects.begin() + id);
	return true;
}

bool GameObjectHolder::RemoveObject(GameObjectBase* object) {
	for (size_t i = 0; i < _objects.size(); i++)
	{
		if (_objects[i].get() == object) {
			RemoveObject(i);
			return true;
		}
	}
	return false;
}

void GameObjectHolder::Start(const UpdateData& data) {
	for (size_t i = 0; i < _objects.size(); i++)
	{
		_objects[i]->Start(data);
	}
}

void GameObjectHolder::Update(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < _objects.size(); i++)
	{
		_objects[i]->Update(dTime, data);
	}
}