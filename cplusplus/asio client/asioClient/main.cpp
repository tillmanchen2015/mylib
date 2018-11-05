#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n"; 
			return 1;
		}

		boost::asio::io_context ioc;
		
		tcp::socket s(ioc);
		tcp::resolver resolver(ioc);
		boost::asio::connect(s, resolver.resolve(argv[1], argv[2]));

		std::cout << "enter message: ";
		char request[1024];
		std::cin >> request;
		
		std::size_t request_len = std::strlen(request);
		boost::asio::write(s, boost::asio::buffer(request, request_len));

		char reply[1024];
		std::size_t replay_len = boost::asio::read(s, boost::asio::buffer(reply, 1024));
		//std::size_t replay_len = s.read_some(boost::asio::buffer(reply, 1024));
		std::cout << "reply is ";
		std::cout << reply;


	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}