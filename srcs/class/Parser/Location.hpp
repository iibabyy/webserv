/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:55:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/14 19:42:01 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

#include "../../../includes/includes.hpp"
#include "../../../includes/utils.hpp"
#include "Parser.hpp"
#include <ostream>
#include <string>
#include <vector>

struct Data;

struct	Location {
	private:
		std::string									_location;
		bool										_internal;
		std::string									_root;
		std::map<std::string, std::string>			_cgi;
		std::string									_redirect;
		int											_allowedMethods;
		long long									_client_max_body_size;
		std::vector<std::string>					_index;
		int											_autoIndex;
		std::string									_uploadFolder;
    	std::map<std::string, std::string>			_errorPages;

    	void										assignKeyValue(std::string &key, std::string &value);

	public:
		Location();
		~Location();

		/*	GETTER	*/
		const std::string	 						&location( void ) const;
		bool				 						internal( void ) const;
		const std::string 							&root( void ) const;
		const std::map<std::string, std::string>	&cgi( void ) const;
		const std::string							&redirect( void ) const;
		const int									&allowedMethods( void ) const;
		const long long								&maxBodySize( void ) const;
		const std::vector<std::string>				&index( void ) const;
		const int									&autoIndex( void ) const;
		const std::string							&uploadFolder( void ) const;
		const std::string							&getErrorPage(const std::string &code) const;
		/*	SETTER	*/
		void										location( std::string &newLocation );
		void										root( std::string &newRoot );
		void										cgi( std::string &newCgi );
		void										redirect( std::string &newRedirect );
		void										handleAllowedMethods( std::string &value );
		void										allowedMethods( int newAllowedMethods );
		void										handleMaxBodySize( std::string &value );
		void										maxBodySize( long long newMaxBodySize );
		void										index( std::string &newIndex );
		void										handleAutoIndex( std::string &value );
		void										autoIndex( const int & newAutoIndex );
		void										uploadFolder( std::string &newUploadFolder );
		void 										addCgi(std::string &cgi);
		void										addLocationLine(std::string &line);
		void										setErrorPage(std::string &value);

		bool										errorPageIsSet(const std::string &code) const;
};

std::ostream& operator<<(std::ostream& os, const Location& location);
#endif
