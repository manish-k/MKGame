/**
	event_manager.cpp
	Purpose: EventManager class will help game objects to communicate with each other using events.
	This is one to many communication system where callbacks will be triggered for events in the same
	frame. 

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "event_manager.h"

static EventManager * instance = NULL;

EventManager::EventManager()
{

}

EventManager::~EventManager()
{
	instance->event_callback_map.clear();
}

EventManager * EventManager::i()
{
	if (instance == NULL)
	{
		instance = new EventManager;
	}

	return instance;
}

void EventManager::add_listener(std::string event_name, GameObject * listener_object, t_callable cb)
{
	t_object_cb_map::iterator e_itr = this->event_callback_map.find(event_name);
	if (e_itr != this->event_callback_map.end())
	{
		e_itr->second[listener_object] = cb;
	}
	else
	{
		// create a map for new event
		t_callable_map map = t_callable_map();
		map[listener_object] = cb;
		this->event_callback_map[event_name] = map;
	}
}

void EventManager::dispatch_event(std::string event_name, int val)
{
	// creating a clone for event_callback_map because game objects
	// can be added in between the iteration which will cause a runtime crash.
	t_object_cb_map clone = this->event_callback_map;
	t_object_cb_map::iterator e_itr = clone.find(event_name);
	if (e_itr != clone.end())
	{
		for (auto itr = e_itr->second.begin(); itr != e_itr->second.end(); ++itr)
		{
			itr->second(val);
		}
	}
}

void EventManager::remove_listeners(GameObject * listener_object)
{
	for (auto itr = this->event_callback_map.begin(); itr != this->event_callback_map.end(); ++itr)
	{
		itr->second.erase(listener_object);
	}
}

void EventManager::remove_all_listeners()
{
	this->event_callback_map.clear();
}
