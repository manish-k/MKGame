/**
	game_enemy.cpp
	Purpose: Class defining enemy behaviour.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "game_enemy.h"
#include "event_manager.h"

GameEnemy::GameEnemy(std::string name, int health, int power)
{
	this->name = name;
	this->health = health;
	this->attack_power = power;

	// grant random haste
	srand(time(NULL));
	attack_cooldown -= (rand() % 10) * 0.1;
}

void GameEnemy::on_enable()
{
	t_callable hero_attack_cb = std::bind(&GameEnemy::on_hero_attack, this, std::placeholders::_1);
	EventManager::i()->add_listener("hero_attack", this, hero_attack_cb);
}

void GameEnemy::update(double dt)
{
	last_attack_time += dt;
	if (last_attack_time > this->attack_cooldown) //attack cooldown
	{
		this->attack();
	}
}

void GameEnemy::on_disable()
{
	EventManager::i()->remove_listeners(this);
}

void GameEnemy::attack()
{
	EventManager::i()->dispatch_event("enemy_attack", this->attack_power);
	this->last_attack_time = 0;
}

void GameEnemy::on_hero_attack(int damage)
{
	std::cout << this->name <<" received damage " << damage << " from hero\n";
	this->health -= damage;

	if (this->health <= 0)
	{
		std::cout << this->name << " died\n";
		EventManager::i()->dispatch_event("enemy_died", this->id);
	}
}
