#include "GlobalData.hpp"
#include "../Client/Client.hpp"
#include "../RawBits/RawBits.hpp"
#include "../Parser/Parser.hpp"
#include "../../../includes/includes.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/epoll.h>
#include <sys/select.h>
#include <vector>

const std::string getMessageCode(int code) {
	std::map<int, std::string> codes_responses;

	codes_responses[100] = "Continue";
	codes_responses[101] = "Switching Protocols";
	codes_responses[102] = "Processing";
	codes_responses[103] = "Early Hints";
	codes_responses[200] = "OK";
	codes_responses[201] = "Created";
	codes_responses[202] = "Accepted";
	codes_responses[203] = "Non-Authoritative Information";
	codes_responses[204] = "No Content";
	codes_responses[205] = "Reset Content";
	codes_responses[206] = "Partial Content";
	codes_responses[207] = "Multi-Status";
	codes_responses[208] = "Already Reported";
	codes_responses[210] = "Content Different";
	codes_responses[226] = "IM Used";
	codes_responses[300] = "Multiple Choices";
	codes_responses[301] = "Moved Permanently";
	codes_responses[302] = "Found";
	codes_responses[303] = "See Other";
	codes_responses[304] = "Not Modified";
	codes_responses[305] = "Use Proxy";
	codes_responses[307] = "Temporary Redirect";
	codes_responses[308] = "Permanent Redirect";
	codes_responses[310] = "Too many Redirects";
	codes_responses[400] = "Bad Request";
	codes_responses[401] = "Unauthorized";
	codes_responses[402] = "Payment Required";
	codes_responses[403] = "Forbidden";
	codes_responses[404] = "Not Found";
	codes_responses[405] = "Method Not Allowed";
	codes_responses[406] = "Not Acceptable";
	codes_responses[407] = "Proxy Authentication Required";
	codes_responses[408] = "Request Time-out";
	codes_responses[409] = "Conflict";
	codes_responses[410] = "Gone";
	codes_responses[411] = "Length Required";
	codes_responses[412] = "Precondition Failed";
	codes_responses[413] = "Request Entity Too Large";
	codes_responses[414] = "Request-URI Too Long";
	codes_responses[415] = "Unsupported Media Type";
	codes_responses[416] = "Requested range unsatisfiable";
	codes_responses[417] = "Expectation failed";
	codes_responses[418] = "I'm a teapot";
	codes_responses[419] = "Page expired";
	codes_responses[421] = "Bad mapping / Misdirected Request";
	codes_responses[422] = "Unprocessable entity";
	codes_responses[423] = "Locked";
	codes_responses[424] = "Method failure";
	codes_responses[425] = "Too Early";
	codes_responses[426] = "Upgrade Required";
	codes_responses[427] = "Invalid digital signature";
	codes_responses[428] = "Precondition Required";
	codes_responses[429] = "Too Many Requests";
	codes_responses[431] = "Request Header Fields Too Large";
	codes_responses[449] = "Retry With";
	codes_responses[450] = "Blocked by Windows Parental Controls";
	codes_responses[451] = "Unavailable For Legal Reasons";
	codes_responses[456] = "Unrecoverable Error";
	codes_responses[444] = "No Response";
	codes_responses[495] = "SSL Certificate Error";
	codes_responses[496] = "SSL Certificate Required";
	codes_responses[497] = "HTTP Request Sent to HTTPS Port";
	codes_responses[498] = "Token expired/invalid";
	codes_responses[499] = "Client Closed Request";
	codes_responses[500] = "Internal Server Error";
	codes_responses[501] = "Not Implemented";
	codes_responses[502] = "Bad Gateway or Proxy Error";
	codes_responses[503] = "Service Unavailable";
	codes_responses[504] = "Gateway Time-out";
	codes_responses[505] = "HTTP Version not supported";
	codes_responses[506] = "Variant Also Negotiates";
	codes_responses[507] = "Insufficient storage";
	codes_responses[508] = "Loop detected";
	codes_responses[509] = "Bandwidth Limit Exceeded";
	codes_responses[510] = "Not extended";
	codes_responses[511] = "Network authentication required";
	codes_responses[520] = "Unknown Error";
	codes_responses[521] = "Web Server Is Down";
	codes_responses[522] = "Connection Timed Out";
	codes_responses[523] = "Origin Is Unreachable";
	codes_responses[524] = "A Timeout Occurred";
	codes_responses[525] = "SSL Handshake Failed";
	codes_responses[526] = "Invalid SSL Certificate";
	codes_responses[527] = "Railgun Error";
	return codes_responses[code];
}

void GlobalData::sendResponse(std::ifstream &file, int fd, Client *client) {
	std::ostringstream buffer;
	buffer << file.rdbuf();
	std::string html_content = buffer.str();
	int code;

	code = atoi(client->getRequest()->getResponsCode().c_str());
	std::ostringstream oss;
    std::string response = "HTTP/1.1" + client->getRequest()->getResponsCode() + getMessageCode(code)+ "\r\n";
    response += "Content-Type: text/html\r\n";
	oss << html_content.size();
    response += "Content-Length: " + oss.str() + "\r\n";
    response += "\r\n";

    response += html_content;

	send(fd, response.c_str(), response.size(), MSG_EOR);
}