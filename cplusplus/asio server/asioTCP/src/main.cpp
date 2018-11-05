#include "tinyformat.h"
#include "boost/asio.hpp"

using boost::asio::ip::tcp;

class Session
	: public std::enable_shared_from_this<Session>
{
public:
	Session(tcp::socket s)
	 : socket_(std::move(s)){}

	void start()
	{
		do_read();
	}
private:
	void do_read()
	{
		auto self(shared_from_this());
		socket_.async_read_some(boost::asio::buffer(data_, max_length), 
			[this, self](boost::system::error_code ec, std::size_t length)
			{
				if (!ec)
				{
					self->do_write(length);
				}
				else
				{
					tfm::printfln("aync_read error, %s", ec.message());
				}
			}
		);
	}

	void do_write(std::size_t length)
	{
		auto self(shared_from_this());
		boost::asio::async_write(socket_, boost::asio::buffer(data_, length), 
			[this, self](boost::system::error_code ec, std::size_t)
			{
				if (!ec)
				{
					do_read();
				}
				else
				{
					tfm::printfln("do_write error : ", ec.message());
				}

			}
		);
	}

	tcp::socket socket_;
	enum{max_length = 1024};
	char data_[max_length];
};

class Server
{
public:
	Server(boost::asio::io_context& ioc, short port)
		: acceptor_(ioc, tcp::endpoint(tcp::v4(), port))
	{
		do_accept();
	}

private:
	void do_accept()
	{
		acceptor_.async_accept(
			[this](boost::system::error_code ec, tcp::socket s) 
		   {
				if (!ec)
				{
					std::make_shared<Session>(std::move(s))->start();
				}
				else
				{
					tfm::printfln("do_accept error: %s", ec.message());
				}
				this->do_accept();
		   }
		);
	}
	tcp::acceptor acceptor_;

};

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: async tcp echo server <port>\n" << std::endl;
			return 1;
		}
		boost::asio::io_context io_context;
		Server s(io_context, std::atoi(argv[1]));
		io_context.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}
}