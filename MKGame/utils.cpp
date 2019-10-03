/**
	utils.cpp
	Purpose: Utility functions to be used in game.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#include "pch.h"
#include "utils.h"

std::chrono::time_point<std::chrono::system_clock> getCurrentTime()
{
	return std::chrono::system_clock::now();
}

double elapsedSecondsSince(std::chrono::time_point<std::chrono::system_clock> old_time)
{
	std::chrono::duration<double> elapsed_seconds = getCurrentTime() - old_time;
	return elapsed_seconds.count();
}
