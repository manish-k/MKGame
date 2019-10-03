/**
	game_hero.cpp
	Purpose: Class defining hero behaviour.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "game_hero.h"
#include "event_manager.h"


GameHero::GameHero(std::string name, int health, int power)
{
	this->name = name;
	this->health = health;
	this->attack_power = power;

	// giving enemy some chance to play 
	attack_cooldown += 1;

	std::cout << this->name << " has entered in the scene\n";
}

void GameHero::on_enable()
{
	t_callable enemy_attack_cb = std::bind(&GameHero::on_enemy_attack, this, std::placeholders::_1);
	EventManager::i()->add_listener("enemy_attack", this, enemy_attack_cb);
}

void GameHero::update(double dt)
{
	last_attack_time += dt;
	if (last_attack_time > this->attack_cooldown) //attack cooldown
	{
		this->attack();
	}
}

void GameHero::on_disable()
{
	EventManager::i()->remove_listeners(this);
}

void GameHero::attack()
{
	std::cout << this->name << " used Thunderclap.\n";
	EventManager::i()->dispatch_event("hero_attack", this->attack_power);
	this->last_attack_time = 0;
}

void GameHero::on_enemy_attack(int damage)
{
	std::cout << this->name << " received damage " << damage << " from enemy\n";
	this->health -= damage;

	if (this->health <= 0)
	{
		std::cout << this->name <<" died\n";
		EventManager::i()->dispatch_event("hero_died", this->id);
	}
}
