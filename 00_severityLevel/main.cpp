#include <glog/logging.h>
#include <iostream>

void outputLogInfo();

/*!
* severity log info control messages of a given severity are \
* logged not only in the logfile for that severity, but also \
* in all logfiles of lower severity.
* @link http://rpg.ifi.uzh.ch/docs/glog.html#severity
* @link https://github.com/google/glog/blob/1b7d54143122d3a5be2dac3502f0a2f10de5838d/src/glog/log_severity.h#L53
*/
int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);

	// default 
	outputLogInfo();

	// output: INFO, WARNING, ERROR, FATAL log
	std::cout << "--- set log severity level to INFO ---" << std::endl;
	FLAGS_stderrthreshold = google::GLOG_INFO;
	outputLogInfo();

	// output: WARNING, ERROR, FATAL log
	std::cout << "--- set log severity level to WARNING ---" << std::endl;
	FLAGS_stderrthreshold = google::GLOG_WARNING;
	outputLogInfo();

	// output: ERROR, FATAL log
	std::cout << "--- set log severity level to ERROR ---" << std::endl;
	FLAGS_stderrthreshold = google::GLOG_ERROR;
	outputLogInfo();

	// output: FATAL log
	std::cout << "--- set log severity level to FATAL ---" << std::endl;
	FLAGS_stderrthreshold = google::GLOG_FATAL;
	outputLogInfo();
}

/*!
Output different level log info
*/
void outputLogInfo()
{
	LOG(INFO)    << "Hello,GLOG! This INFO level log";
	LOG(WARNING) << "Hello,GLOG! This WARNING level log";
	LOG(ERROR)   << "Hello,GLOG! This ERROR level log";
	//LOG(FATAL)   << "Hello,GLOG! This FATAL level log";// terminates the program (after the message is logged)
}