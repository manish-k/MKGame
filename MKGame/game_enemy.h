/**
	game_enemy.h
	Purpose: GameEnemy declarations.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include "game_object.h"
#include "constants.h"
#include "types.h"

class GameEnemy : public GameObject
{
	std::string name = "";
	int health = 0;
	int attack_power = 0;
	double last_attack_time = 0;
	double attack_cooldown = BASE_COOLDOWN;

public:
	GameEnemy(std::string name, int health, int power);
	void on_enable() override;
	void update(double dt) override;
	void on_disable() override;
	void attack();
	void on_hero_attack(int damage);
};