#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Formatters/MessageOnlyFormatter.h>

	static plog::RollingFileAppender<plog::TxtFormatter> fileAppender("testYanhui.log", 5000000, 3); 
	static plog::ColorConsoleAppender<plog::MessageOnlyFormatter> consoleAppender; 
	plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); 