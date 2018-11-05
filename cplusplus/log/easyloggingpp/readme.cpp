https://github.com/muflihun/easyloggingpp

1. for simplest usage: 
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP
LOG(INFO) << "hello world";

The log is in the same folder as app. Pay attention to INITIALIZE_EASYLOGGINGPP. If you don't have it ,compilation error.

2. el::Loggers::addFlag(el::LoggingFlag::AutoSpacing);
it will automatically add space for each <<. 

3. use config file for logging:
	if (boost::filesystem::exists("d:\\log.conf"))
	{
		el::Configurations conf("d:\\log.conf");
		conf.setGlobally(el::ConfigurationType::Filename, "d:\\my.log");
		el::Loggers::addFlag(el::LoggingFlag::AutoSpacing);
		el::Loggers::reconfigureAllLoggers(conf);
	}
	else
	{
		el::Configurations conf("d:\\log.conf");
		conf.setGlobally(el::ConfigurationType::Filename, "d:\\my.log");
		conf.setGlobally(el::ConfigurationType::Enabled, "true");
		conf.setGlobally(el::ConfigurationType::Format, "%datetime %level %msg");
		conf.setGlobally(el::ConfigurationType::MaxLogFileSize, "2097152");
		conf.setGlobally(el::ConfigurationType::LogFlushThreshold, "100");
		conf.setGlobally(el::ConfigurationType::ToFile, "true");
		conf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");
		conf.setGlobally(el::ConfigurationType::PerformanceTracking, "true");
		conf.setGlobally(el::ConfigurationType::SubsecondPrecision, "3");
		el::Loggers::addFlag(el::LoggingFlag::AutoSpacing);
		el::Loggers::reconfigureAllLoggers(conf);
	}
	LOG(ERROR) << "log type 2";
	
	
4. performance tracking:
	in easylogging++.h, #define ELPP_FEATURE_PERFORMANCE_TRACKING
	
	void performHeavyTask() {
	TIMED_FUNC(timerObj);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	 {
		TIMED_SCOPE(timerBlkObj, "heavy-iter");
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
