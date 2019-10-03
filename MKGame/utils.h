/**
	utils.h
	Purpose: Utility functions declaration.

	@author Manish Kaushal
	@version 1.0 3/10/19
*/

#pragma once

#include <chrono>
#include <thread>

/**
	Get system current time

	@return current time.
*/
std::chrono::time_point<std::chrono::system_clock> getCurrentTime();

/**
	Get time passed since given past value.

	@param old time value.
	@return time passed in seconds.
*/
double elapsedSecondsSince(std::chrono::time_point<std::chrono::system_clock> time);