// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "director.h"
#include "game_stage.h"

int main()
{	
	GameStage * stage = new GameStage();
	Director::i()->add_game_object(stage);

	Director::i()->start_game_loop();

	Director::i()->remove_game_object(stage);
	free(stage);
}