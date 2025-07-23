/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:59:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/23 11:58:55 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <exception>
#include <iostream>
#include <map>
#include <string>
#include "colors.hpp"
#include <limits.h>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <ostream>
#include <string>


class BitcoinExchange
{
	private:
		std::map<std::string,float> _db;
		void add_db(std::string line);
		bool chek_data(std::string line);
		void Exchange(std::string line);
		
		
	public:
		BitcoinExchange(std::string db);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange & operator=(const BitcoinExchange & bit);
		void exec_file(std::string file);
		
		class Error_db : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
