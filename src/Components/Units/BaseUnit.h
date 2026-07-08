#pragma once

#include "../Base/GameObjectComponent.h"

class BaseUnit : public GameObjectComponent {
	public:
		virtual void Damage(const float damage);
		virtual void Heal(const float heal);
	private:
		float _health;
		float _maxHealth;

		virtual void Death(const float killingDamage);
};