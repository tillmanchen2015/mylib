// crashme.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <chrono>

int main()
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	char* p = new char();
	p = NULL;
	*p = 'd';
	return 0;
}

