#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

using tcp = boost::asio::ip::tcp;
namespace websocket = boost::beast::websocket;

int main(int argc, char** argv)
{
	try
	{
		/*if (argc != 4)
		{
			std::cerr <<
				"Usage: websocket-client-sync <host> <port> <text>\n" <<
				"Example:\n" <<
				"    websocket-client-sync echo.websocket.org 80 \"Hello, world!\"\n";
			return EXIT_FAILURE;
		}*/
		auto const host ="127.0.0.1";
		auto const port = "8080";
		auto const text = "hello,cat";

		boost::asio::io_context ioc;
		tcp::resolver resolver{ ioc };
		websocket::stream<tcp::socket> ws{ ioc };

		auto const results = resolver.resolve(host, port);

		boost::asio::connect(ws.next_layer(), results.begin(), results.end());

		ws.handshake(host, "/");

		ws.write(boost::asio::buffer(std::string(text)));

		boost::beast::multi_buffer buffer;

		ws.read(buffer);

		ws.close(websocket::close_code::normal);

		std::cout << boost::beast::buffers(buffer.data()) << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}