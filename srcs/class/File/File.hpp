/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:36:18 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/15 19:19:49 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.hpp"

#ifndef FILE_HPP
# define FILE_HPP

class File {
	private:
		std::string					_content;
		std::string					_contentDisposition;
		std::string					_name;
		std::string					_filename;
		std::string					_contentType;
		std::map<std::string, std::string>		_others;
	public:
		File();
		~File();
		// File( const File& other );
		// File& operator=( const File& other );

		const std::string&	contentDisposition( void );
		const std::string&	content( void );
		const std::string&	name( void );
		const std::string&	filename( void );
		const std::string&	contentType( void );
		
		// search a the value of key, throw an std::exception if not found
		std::string			get( std::string key );

		void	content( std::string newContent );
		void	contentDisposition( std::string newContentDisposition );
		void	name( std::string newName );
		void	filename( std::string newFilename );
		void	contentType( std::string newContentType );
		void	set( std::string key, std::string value );
};

#endif