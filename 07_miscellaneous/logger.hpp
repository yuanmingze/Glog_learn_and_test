#pragma once
#include <glog/logging.h>
#include <glog/raw_logging.h>

/**
*  logger class
*/
class logger
{
public:
	/**
	* constructor with main function parameters
	* @param argc: form main funciton
	* @return argv: form main funciton
	*/
	logger(int argc, char* argv[]);

	/**
	* Issues a series of barks.
	*/
	~logger();
};
