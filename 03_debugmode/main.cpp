#include <glog/logging.h>
#include <iostream>

/*!
* "debug mode" logging macros only have an effect in debug mode
* @link http://rpg.ifi.uzh.ch/docs/glog.html#debug
*/
int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	FLAGS_stderrthreshold = google::GLOG_INFO;

	int num_cookies = 11;
	
	DLOG(INFO) << "Found cookies";
	DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";
	DLOG_EVERY_N(WARNING, 10) << "Got the " << google::COUNTER << "th cookie";
}