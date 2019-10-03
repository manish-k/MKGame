/**
	types.h
	Purpose: All type definitions of the system.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include<functional>
#include<unordered_map>
#include "game_object.h"

typedef std::function<void(int)> t_callable;
typedef std::unordered_map<GameObject *, t_callable> t_callable_map;
typedef std::unordered_map<std::string, t_callable_map> t_object_cb_map;