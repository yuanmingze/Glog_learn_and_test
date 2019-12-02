#include "logger.hpp"

/*!
*  The signal handler can be installed by google::InstallFailureSignalHandler().
* @link http://rpg.ifi.uzh.ch/docs/glog.html#signal
*/
int main(int argc, char* argv[])
{
	logger log(argc, argv);
	LOG(ERROR) << "LOG";
	VLOG(3) << "VLOG";
	DLOG(ERROR) << "DLOG";
	DVLOG(3) << "DVLOG";
	SYSLOG(ERROR) << "SYSLOG";
	PLOG(ERROR) << "PLOG";
	RAW_LOG(ERROR, "RAW_LOG");// multi-thread safe
	return 0;
}