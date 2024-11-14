/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:16:52 by madamou           #+#    #+#             */
/*   Updated: 2024/11/10 18:59:39 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include "../../../includes/includes.hpp"
#include "../Client/Client.hpp"
#include "../Request/Request.hpp"
#include <map>
#include <ostream>

# define MAX_CLIENTS 100
# define MAX_EVENTS 1000
# define PORT 9999

struct Data ;

class Server {
	private:
		int _socket_fd;
		std::string _host[2];
		std::map<int, Client*> _clientMap;
		void addToEpoll(int fd, uint32_t events);
			int waitFdsToBeReady(void);
		void _parseClientHeader(Client *client);
		void _parseClientBody(Client *client);
		void	_parseRequestLine( std::string line, Request *clientRequest);
	public:
		Server();
		
		~Server();

		void	init();
		// static void	handleClient( int clientFd );
		void addClientToMap(Client *client);
		bool ifClientInServer(int fd) const;
		Client *getClient(int fd);
		void removeClientInMap(int fd);
    	void addData(Data* data);
		int getSocketFd() const;
		bool isServerHost(std::string const &str) const;
		int nbOfClient(void) const;
		void addClientRequest(int fd);
    Data *_data;

    //request Parsing
    bool checkAllowMethodes(std::string methodes);
};

#endif