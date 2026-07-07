#include "GameObjectBase.h"


void GameObjectBase::Start() {
	for (size_t i = 0; i < componentCount; i++)
	{
		(*components[i]).Start();
	}
}

void GameObjectBase::Update(float dTime) {

}

