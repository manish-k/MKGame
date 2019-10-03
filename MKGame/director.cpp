/**
	director.cpp
	Purpose: Director class is a singleton tha controls the whole game.It includes 
	managing updates of game objects, memory management, input processing and much more.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "director.h"
#include "constants.h"

static Director * instance = NULL;

Director::Director()
{
	this->active_game_objects = std::vector<GameObject *>();
	this->object_count = 0;
}

Director * Director::i()
{
	if (instance == NULL)
	{
		instance = new Director;
	}

	return instance;
}

int Director::get_new_object_id()
{
	return ++this->object_count;
}

void Director::start_game_loop()
{
	double frame_time_ms = 1.0 / FPS * 1000;
	auto last_frame_time = getCurrentTime();

	// Game loop with fixed time steps. Current assumption is that each frame will 
	// processed in 1/FPS secs.
	while (true)
	{
		auto current_frame_time = getCurrentTime();
		auto elapsed_time = elapsedSecondsSince(last_frame_time);

		update(elapsed_time);

		last_frame_time = current_frame_time;
		auto sleep_time = int(frame_time_ms - elapsedSecondsSince(current_frame_time) * 1000);

		//std::cout << "Frame Time: " << elapsed_time << ", Sleeping for " << sleep_time << "ms\n";

		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
	}
}

void Director::add_game_object(GameObject * obj)
{
	this->active_game_objects.push_back(obj);
	obj->enabled = true;
	obj->on_enable();
}

void Director::remove_game_object(GameObject * obj)
{
	auto it = std::find(this->active_game_objects.begin(), this->active_game_objects.end(), obj);
	if (it != this->active_game_objects.end())
	{
		this->active_game_objects.erase(it);
		obj->enabled = false;
		obj->on_disable();

		// queue for deallocation in next frame
		this->objects_to_dealloc.push_back(obj);
	}
}

void Director::update(double dt)
{
	//mouse and keyboard events

	//invoke scheduler

	//process message queue

	//call update on all active game objects
	auto clone = this->active_game_objects;
	for (auto itr = clone.begin(); itr != clone.end(); ++itr)
	{

		GameObject * object = *itr;
		if (object->enabled) // object can be deallocated in between iterations
		{
			object->update(dt);
		}
	}

	//dealloc game objects that are removed from game
	for (auto itr = this->objects_to_dealloc.begin(); itr != this->objects_to_dealloc.end(); ++itr)
	{
		free(*itr);
	}
	this->objects_to_dealloc.clear();

	//renderer
}
