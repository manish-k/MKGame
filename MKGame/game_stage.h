/**
	game_stage.h
	Purpose: GameStage class declarations.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include "game_object.h"
#include "constants.h"
#include "types.h"

class GameStage : public GameObject
{
	std::unordered_map<int, GameObject *> active_stage_objects;

public:
	GameStage();
	virtual void on_enable() override;
	virtual void update(double dt) override;
	virtual void on_disable() override;
	void on_enemy_died(int id);
	void on_hero_died(int id);
};