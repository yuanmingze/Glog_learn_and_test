#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <windows.h>
#include <glog/logging.h>
#include <fstream>


void bar(int x) {
	CHECK_EQ(x, 1);
}

void foo(int x) {
	bar(x + 1);
}

/*!
*  The signal handler can be installed by google::InstallFailureSignalHandler().
* @link http://rpg.ifi.uzh.ch/docs/glog.html#signal
*/
int main(int argc, char** argv) {
	//  signal handler installe
	google::InstallFailureSignalHandler();

	// customize the destination by InstallFailureWriter()
	google::InstallFailureWriter([](const char* data, int size)
	{
		std::ofstream fs("glog_dump.log", std::ios::app);
		std::string str = std::string(data, size);
		fs << std::string(data, size);
		fs.close();
		LOG(ERROR) << str;
	});
	
	foo(1);
}