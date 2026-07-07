#include "../Base/ComponentBase.h"
#include <iostream>

class DebugComp : public ComponentBase {
	public: 
		void Start() override {
			std::cout << "ALL THOSE LIMITS I WILL OVERRIDE";
		}
};