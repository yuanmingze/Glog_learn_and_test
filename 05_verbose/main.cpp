#include <glog/logging.h>
#include <iostream>

#include "test_vlog.h"

/*!
*  VLOG macro allows user to define own numeric logging levels.
*  the program parameters, e.g. --vmodule=test_vlog=2,main=1 --v=0 \
*	Print VLOG(1) and lower messages from test_vlog.{cpp,h}, and print VLOG(0) and lower messages from elsewhere
* @link http://rpg.ifi.uzh.ch/docs/glog.html#verbose
*/
int main(int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true); // with CLI parameter "--logtostderr=1", default the log output to stderror, not to log file
	google::InitGoogleLogging(argv[0]);
	FLAGS_stderrthreshold = google::GLOG_INFO;

	FLAGS_v = 1;

	VLOG(1) << "main.cpp: I'm printed when you run the program with --v=1 or higher";

	VLOG(2) << "main.cpp: I'm printed when you run the program with --v=2 or higher";

	foo_vlog();
}