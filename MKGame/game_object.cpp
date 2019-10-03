/**
	game_object.cpp
	Purpose: Parent class for game objects.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/


#include "pch.h"
#include "game_object.h"
#include "director.h"

GameObject::GameObject()
{
	this->id = Director::i()->get_new_object_id();
}

GameObject::~GameObject()
{

}

void GameObject::render()
{
	//Do rendering stuff here in future
}
