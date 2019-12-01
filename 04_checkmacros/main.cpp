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

	CHECK(num_cookies == 11) << "Write failed!";

	CHECK_EQ(std::string("abc")[1], 'b');

	int counter = 11;
	CHECK_NOTNULL(&counter);

	struct S {
		S(int * ptr) : ptr_(CHECK_NOTNULL(ptr)) {}
		int * ptr_;
	};

	struct S glog_s(nullptr);
}