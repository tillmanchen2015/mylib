int c = 0;
try
{
	std::string a = "a11d2";
	 c = std::stoi(a);
}
catch (...) 	// or catch(std::invalid_argument
{
	int b = 3;
}

if a is "11ad2", no exception is thrown. c is 11 at last.
