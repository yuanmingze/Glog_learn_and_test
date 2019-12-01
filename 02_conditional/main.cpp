#include <glog/logging.h>
#include <iostream>

/*!
* log a message under certain conditions
* @link http://rpg.ifi.uzh.ch/docs/glog.html#conditional
*/
int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
	FLAGS_stderrthreshold = google::GLOG_INFO;
	
	int num_cookies = 11;

	// "Got lots of cookies" message is logged only when the variable num_cookies exceeds 10
	LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

	std::cout << "--- LOG_EVERY_N ---" << std::endl;
	// only when the variable num_cookies exceeds 10
	for(int i = 0; i < 11; i++)
	{
		LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
	}

	std::cout << "--- LOG_IF_EVERY_N ---" << std::endl;
	for (num_cookies = 0; num_cookies < 1035; num_cookies++)
	{
		LOG_IF_EVERY_N(INFO, (num_cookies > 1024), 10) << "Got the " << google::COUNTER << "th big cookie";
	}

	std::cout << "--- LOG_FIRST_N ---" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		LOG_FIRST_N(INFO, 3) << "Got the " << google::COUNTER << "th cookie";
	}
}