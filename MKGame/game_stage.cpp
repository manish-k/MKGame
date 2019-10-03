/**
	game_stage.cpp
	Purpose: Stage class where all enemies and hero are present and interacting
	with each oter.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "director.h"
#include "game_stage.h"
#include "event_manager.h"
#include "game_enemy.h"
#include "game_hero.h"


GameStage::GameStage()
{
	GameHero * hero = new GameHero("Muradin", 100, 5);
	Director::i()->add_game_object(hero);
	this->active_stage_objects[hero->id] = hero;

	GameEnemy * enemy = new GameEnemy("Skeleton Captain", 30, 2);
	Director::i()->add_game_object(enemy);
	this->active_stage_objects[enemy->id] = enemy;

	enemy = new GameEnemy("Skeleton Warrior", 20, 3);
	Director::i()->add_game_object(enemy);
	this->active_stage_objects[enemy->id] = enemy;
}

void GameStage::on_enable()
{
	t_callable enemy_died_cb = std::bind(&GameStage::on_enemy_died, this, std::placeholders::_1);
	EventManager::i()->add_listener("enemy_died", this, enemy_died_cb);

	t_callable hero_died_cb = std::bind(&GameStage::on_hero_died, this, std::placeholders::_1);
	EventManager::i()->add_listener("hero_died", this, hero_died_cb);
}

void GameStage::update(double dt)
{

}

void GameStage::on_disable()
{
	EventManager::i()->remove_listeners(this);
}

void GameStage::on_enemy_died(int id)
{
	Director::i()->remove_game_object(this->active_stage_objects[id]);
	this->active_stage_objects.erase(id);

	//spawn new enemy in the game
	GameEnemy * enemy = new GameEnemy("Skeleton Warrior", 20, 2);
	Director::i()->add_game_object(enemy);
	this->active_stage_objects[enemy->id] = enemy;
}

void GameStage::on_hero_died(int id)
{
	Director::i()->remove_game_object(this->active_stage_objects[id]);
	this->active_stage_objects.erase(id);
	std::cout << "Game Over!\n";
}
