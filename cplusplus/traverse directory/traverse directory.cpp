#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

//non-recursive
int main()
{
  path p = current_path();
  directory_iterator it{p};
  while (it != directory_iterator{})
    std::cout << *it++ << '\n';
}

//recursive
std::vector<boost::filesystem::path> traverse_if_directory(boost::filesystem::path f, std::vector<boost::filesystem::path>& fileList)
{
	boost::system::error_code ec;

	if (boost::filesystem::is_directory(f))
	{
		for (boost::filesystem::recursive_directory_iterator it(f, ec), eit; it != eit; it.increment(ec))
		{
			if (ec) 
			{
				it.pop();
				continue;
			}
			if (!boost::filesystem::is_directory(it->path())) 
			{
				fileList.push_back(it->path());
			}
		}
	}
	else 
	{
		fileList.push_back(f);
	}

	return fileList;
}