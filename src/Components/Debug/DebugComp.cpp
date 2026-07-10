#include "../Base/GameObjectComponent.h"
#include <iostream>

class DebugComp : public GameObjectComponent {
	public: 
		void Start() override {
			std::cout << "ALL THOSE LIMITS I WILL OVERRIDE";
			std::cout << (GetOwner()->GetPosition().x) << ", " << (GetOwner()->GetPosition().y) << " Position" << std::endl;
		}
		/*DebugComp(GameObjectBase* owner) {
			base.
		}*/
		//DebugComp(GameObjectBase* owner) : GameObjectComponent(owner) {};

		void Update(const float dTime, const UpdateData& data) override {
			if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
				//I was debugging the basic movement script because of ts, burn in hell
				GetOwner()->SetPosition(GetOwner()->GetPosition() + Vector2f(1, 0));
				Blaze();
			}
		}

		DebugComp(GameObjectBase& owner) : GameObjectComponent(owner) {};

		void Blaze() {
			std::cout << (GetOwner()->GetPosition().x) << ", " << (GetOwner()->GetPosition().y) << " Position" << std::endl;
		}
};