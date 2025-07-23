/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:59:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/23 11:34:11 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <exception>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string,float> _db;
		std::map<std::string,float> _file_db;
		void set_db_and_file_db(std::string db,std::string file_db);
		void add_db_and_file_db(std::string db,std::string file_db);
		
	public:
		BitcoinExchange(std::string db,std::string file_db);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange & operator=(const BitcoinExchange & bit);
		void exec_file();
		
		class Error_db : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
