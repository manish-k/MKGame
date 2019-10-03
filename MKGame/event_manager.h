/**
	event_manager.h
	Purpose: EventManager class declarations.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include<string>
#include<functional>
#include<iostream>
#include "game_object.h"
#include "types.h"

class EventManager
{
	t_object_cb_map event_callback_map; //mapping for events to associated listeners

	/**
	Class constructor. Private for singleton class.
	*/
	EventManager();

	/**
	Class destructor.
	*/
	~EventManager();

public:
	/**
	Initialize and returns the static singleton instance.

	@return EventManager instance
	*/
	static EventManager * i();
	
	/**
	Add a listener callback for a event associate with a game object class.

	@param event name.
	@param target class.
	@param callback to be triggered when event occurs in the game.
	*/
	void add_listener(std::string event_name, GameObject * listener_object, t_callable cb);
	
	/**
	Dispatch event to other game objects along with integer data.

	@param event name.
	@param integer value to send to listeners.
	*/
	void dispatch_event(std::string event_name, int val);
	
	/**
	Remove all listeners callback for a class.

	@param class object which is listening.
	*/
	void remove_listeners(GameObject *listener_object);
	
	/**
	Remove all listners from event manager.
	*/
	void remove_all_listeners();
};