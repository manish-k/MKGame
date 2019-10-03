/**
	game_object.h
	Purpose: GameObject class declarations.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/


#pragma once

#include <stdlib.h>
#include <time.h>

class GameObject
{
public:
	int id; // unique game object identifier
	bool enabled; // currently active in the game loop or not

	/**
	Class Constructor
	*/
	GameObject();
	
	/**
	Class Destructor
	*/
	~GameObject();
	
	/**
	This function will be called whenever object will be entered in the game loop.
	*/
	virtual void on_enable() = 0;
	
	/**
	Local game object update loop.
	*/
	virtual void update(double dt) = 0;
	
	/**
	This function will be called whenever object will be removed from the game loop.
	*/
	virtual void on_disable() = 0;
	
	/**
	Rendering function for object
	*/
	virtual void render();
};