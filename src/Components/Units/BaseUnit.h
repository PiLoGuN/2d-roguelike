#pragma once

#include "../Base/GameObjectComponent.h"

class BaseUnit : public GameObjectComponent {
	public:
		virtual void Damage(const float damage);
		virtual void Heal(const float heal);

		std::string unitName = "Dave";
	private:
		float _health = 100;
		float _maxHealth = 100;

		virtual void Death(const float killingDamage);
};