boost::filesystem::path p("d:\\data");
for (boost::filesystem::directory_iterator end_iter, it(p); it != end_iter; ++it)
{
	boost::filesystem::remove_all(it->path());
}