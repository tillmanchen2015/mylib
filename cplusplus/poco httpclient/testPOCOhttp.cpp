// testPOCOhttp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include <Poco/Net/HTTPCredentials.h>
#include "Poco/StreamCopier.h"
#include "Poco/NullStream.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include <iostream>

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;

bool doRequest(Poco::Net::HTTPClientSession& session, Poco::Net::HTTPRequest& request, Poco::Net::HTTPResponse& response)
{
	session.setTimeout(Poco::Timespan(1));
	session.sendRequest(request);
	std::istream& rs = session.receiveResponse(response);
	std::cout << response.getStatus() << " " << response.getReason() << std::endl;
	if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED)
	{
		StreamCopier::copyStream(rs, std::cout);
		return true;
	}
	else
	{
		Poco::NullOutputStream null;
		StreamCopier::copyStream(rs, null);
		return false;
	}
}

int main1()
{
	try
	{
		URI uri("http://httpbin.org/get");
		std::string path(uri.getPathAndQuery());
		if (path.empty()) path = "/";

		std::string username;
		std::string password;
		Poco::Net::HTTPCredentials::extractCredentials(uri, username, password);
		Poco::Net::HTTPCredentials credentials(username, password);

		HTTPClientSession session(uri.getHost(), uri.getPort());
		HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
		HTTPResponse response;
		if (!doRequest(session, request, response))
		{
			credentials.authenticate(request, response);
			if (!doRequest(session, request, response))
			{
				std::cerr << "Invalid username or password" << std::endl;
				return 1;
			}
		}
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
		return 1;
	}
	return 0;
}
