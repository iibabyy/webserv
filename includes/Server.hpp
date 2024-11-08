/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:16:52 by madamou           #+#    #+#             */
/*   Updated: 2024/11/05 01:20:43 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include "includes.hpp"

# define MAX_CLIENTS 100
# define MAX_EVENTS 1000
# define PORT 9999



class Server {
	private:
		int _socket_fd;
		struct sockaddr_in _server_addr;
		int _epoll_fd;
		struct epoll_event *_events;
		void addToEpoll(int fd, uint32_t events);
		void addNewClient(void);
		void removeClient(int fd);
		int waitFdsToBeReady(void);
	public:
		Server();
		
		~Server();

		void	init();
		// static void	handleClient( int clientFd );
		void	run();
		void	signalHandle();
};

#endif