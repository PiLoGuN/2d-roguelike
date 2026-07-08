#include "BaseUnit.h"
#include <iostream>

void BaseUnit::Damage(const float damage) {
	_health -= damage;
	if (_health <= 0) {
		Death(damage);
	}
}

void BaseUnit::Heal(const float heal) {
	_health += heal;
	if (_health >= _maxHealth) {
		_health = _maxHealth;
	}
}

void BaseUnit::Death(const float killingDamage) {
	std::cout << "Dead X0 , (Implement death)" << std::endl;
}