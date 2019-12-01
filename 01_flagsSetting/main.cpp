#include <glog/logging.h>
#include <iostream>

/*!
* flags influence glog's output behavior.
* @link http://rpg.ifi.uzh.ch/docs/glog.html#flags
* Config glog set with following different method:
*    - environment variables: prefixing the flag name with "GLOG_", e.g. GLOG_logtostderr=1 
*    - flags on the command line: start application with the command line parameter, e.g. ./foo.exe --logtostderr=1 
*    - global variables FLAGS_* in program:  modifying global variables FLAGS_* @see https://github.com/google/glog/blob/1b7d54143122d3a5be2dac3502f0a2f10de5838d/src/logging.cc#L112
*/
int main(int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true); // with CLI parameter "--logtostderr=1", default the log output to stderror, not to log file
	google::SetLogDestination(google::GLOG_INFO, "./foobar.log");// output log to file "foobar.logyyyymmdd-mmmmm.nnnn".
	google::InitGoogleLogging(argv[0]);

	// with "--logtostderr=1" the log output to stderror not to log file
	LOG(INFO) << "file";
	LOG(INFO) << "stderr";
	
	// output log file not to stderror
	FLAGS_logtostderr = 0;
	LOG(INFO) << "the same file";
}
