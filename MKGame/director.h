/**
	director.h
	Purpose: Declaration of Director class

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include <vector>
#include <iostream>
#include "game_object.h"
#include "utils.h"


class Director
{
	std::vector<GameObject *> active_game_objects;
	std::vector<GameObject *> objects_to_dealloc;
	int object_count; // counter for game objects initialized during game lifetime

	/**
	Class constructor. Private for singleton class.
	*/
	Director();
	void update(double dt);

public:
	/**
	Initialize and returns the static singleton instance.

	@return Director instance
	*/
	static Director * i();

	/**
	Returns the unique int id for the game objects.

	@return integer id
	*/
	int get_new_object_id();

	/**
		Start the fixed time game update loop.
	*/
	void start_game_loop();

	/**
		Add a game object in the current game loop.

		@param game object pointer
	*/
	void add_game_object(GameObject * obj);

	/**
		Remove a game object in the current game loop and also
		mark it for deallocation.

		@param game object pointer
	*/
	void remove_game_object(GameObject * obj);
};