/**
	game_hero.h
	Purpose: GameHero declarations.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include "game_object.h"
#include "constants.h"
#include "types.h"

class GameHero : public GameObject
{
	std::string name = "";
	int health = 0;
	int attack_power = 0;
	double last_attack_time = 0;
	double attack_cooldown = BASE_COOLDOWN;

public:
	GameHero(std::string name, int health, int power);
	void on_enable() override;
	virtual void update(double dt) override;
	virtual void on_disable() override;
	void attack();
	void on_enemy_attack(int damage);
};