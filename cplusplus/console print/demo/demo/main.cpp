#include "tinyformat.h"

void main()
{
	std::string s = "world";
	tfm::printfln("hello,%s", s);
	std::string d = tfm::format("hello,%s", s);
	tfm::printfln("hello, %d", 1);
}