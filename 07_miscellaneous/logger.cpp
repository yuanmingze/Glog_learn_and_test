#include <glog/logging.h>
#include <fstream>

#include "logger.hpp"

logger::logger(int argc, char* argv[])
{
	// parser CLI parameter
	google::ParseCommandLineFlags(&argc, &argv, true);

	google::InitGoogleLogging(argv[0]);

	// threshold of GLOG
	FLAGS_stderrthreshold = google::GLOG_INFO;

	// Set color messages logged to stderr (if supported by terminal)
	FLAGS_colorlogtostderr = true;

	// change the destination file of google::GLOG_INFO, set output log to file prefix
	google::SetLogDestination(google::GLOG_INFO, "INFO_");

	// change the destination file of google::GLOG_WARNING, set output log to file prefix 
	google::SetLogDestination(google::GLOG_WARNING, "WARNING_");

	// change the destination file of google::GLOG_ERROR, set output log to file prefix  
	google::SetLogDestination(google::GLOG_ERROR, "ERROR_");

	// Sets the maximum number of seconds which logs may be buffered for.
	FLAGS_logbufsecs = 0;

	// Sets the maximum log file size (in 100MB).
	FLAGS_max_log_size = 100;

	// Sets to avoid logging to the disk if the disk is full.
	FLAGS_stop_logging_if_full_disk = true;

	// extension as a suffix to log file name
	google::SetLogFilenameExtension(".log");

	// catch core dumped
	google::InstallFailureSignalHandler();

	// output SIGSEGV to file
	google::InstallFailureWriter([](const char* data, int size)
	{
		std::ofstream fs("glog_dump.log", std::ios::app);
		std::string str = std::string(data, size);
		fs << std::string(data, size);
		fs.close();
		LOG(ERROR) << str;
	});
}

logger::~logger()
{
	google::ShutdownGoogleLogging();
}