#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

int main(int argc, char** argv)
{
	try
	{
		if (argc != 4 && argc != 5)
		{
			std::cerr <<
				"Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
				"Example:\n" <<
				"    http-client-sync www.example.com 80 /\n" <<
				"    http-client-sync www.example.com 80 / 1.0\n";
			return EXIT_FAILURE;
		}


		auto const host = argv[1];
		auto const port = argv[2];
		auto const target = argv[3];
		int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;

		boost::asio::io_context ioc;

		tcp::resolver resolver{ ioc };
		tcp::socket socket{ ioc };

		auto const results = resolver.resolve(host, port);

		boost::asio::connect(socket, results.begin(), results.end());

		http::request<http::string_body> req{ http::verb::get, target, version };
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(socket, req);

		boost::beast::flat_buffer buffer;

		http::response<http::dynamic_body> res;

		http::read(socket, buffer, res);

		std::cout << res << std::endl;

		boost::system::error_code ec;
		socket.shutdown(tcp::socket::shutdown_both, ec);

		if (ec && ec!=boost::system::errc::not_connected)
		{
			throw boost::system::system_error{ ec };
		}


	}
	catch (const std::exception& e)
	{
		std::cerr << "eception : " << e.what() << std::endl;
	}
}