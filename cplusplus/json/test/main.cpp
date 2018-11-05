#include "json.hpp"
#include <string>
#include <iostream>
#include <fstream>
using json= nlohmann::json;

void main()
{
	json j;
	j["pi"] = 3.14;
	j["answer"]["everything"] = 42;
	j["list"] = { 1,0,2 };
	j["object"] = { {"currency", "USD"}, {"value", 42.99} };

	/*auto j2 = R"(
  {
	"happy": true,
	"pi": 3.141
  }
)"_json;*/
	std::cout << std::setw(4) << j << std::endl;

	std::string s = j.dump();

	std::ofstream file("file.json");
	file << std::setw(4) << j << std::endl;

	json j2;
	std::ifstream file2("file.json");
	file2 >> j2;
	
	for (auto& i : j2["list"])
	{
		std::cout << i << std::endl;
	}

	std::string m = j2["object"].dump();
	std::string n = j2["answer"]["everything"].dump();

}