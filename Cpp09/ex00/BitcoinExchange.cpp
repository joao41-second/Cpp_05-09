/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:52:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/23 12:07:29 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>
#include <ostream>
#include <string>

bool BitcoinExchange::chek_data(std::string line)
{
	int year,day,month;
	year 	= std::atoll(line.substr(0,4).c_str());
	month 	= std::atoll(line.substr(5,2).c_str());
	day	= std::atoll(line.substr(8,2).c_str());
	
	if(year < 1900)
		return false;
	if(year <= 0 || day <= 0 || day <= 0)
		return false;
	if(day > 31 
		|| (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		|| (month == 2 && day > 29)
		|| (month > 12))
		return false;	
	return true;
}

void BitcoinExchange::add_db(std::string line)
{
	static int max_year = 0;
	if(line[10] != ',' || line[4] != '-' || line[7] != '-'  )
		throw Error_db();
	for(int i = 11;i < (int )line.size();i++)
	{
		if(std::isdigit(line[i]) == false && line[i] != '.' )
		{
			throw Error_db();
		}
	}		
	if(chek_data(line) == false)
	{
			throw Error_db();
	};
	if(max_year == 0)
		max_year =  (int)std::atof(line.substr(0,4).c_str());
	if(max_year >  (int)std::atof(line.substr(0,4).c_str()))
			throw Error_db();
	else
		max_year =  (int)std::atof(line.substr(0,4).c_str());

	if( std::atof(line.substr(11,20).c_str()) < 0 || std::atof(line.substr(11,20).c_str()) > (double)INT_MAX)
			throw Error_db();
 	_db[line.substr(0,10).c_str()] = ((float)std::atof(line.substr(11,20).c_str()));	
}

void BitcoinExchange::Exchange(std::string line)
{
	
	if(line[11] != '|' || line[4] != '-' || line[7] != '-'  )
	{
		std::cout << RED <<"Error: bad input => "<< line  << RESET<< std::endl;
		return;
	}
	for(int i = 12;i < (int )line.size()-1;i++)
	{
		if(std::isdigit(line[i]) == false 
				&& line[i] != '.' 
				&& line[i] != ' ' 
				&& line[i] != '+' 
				&& line[i] != '-')
		{
			std::cout << RED <<"Error: bad input => "<< line  << RESET<< std::endl;
			return;
		}
	}		
	if(chek_data(line) == false)
	{
		std::cout << RED <<"Error: bad input => "<< line  << RESET<< std::endl;
		return;
	}
	
	 if(std::atof(line.substr(12,line.size()).c_str()) < 0)
	 {
		std::cout << RED <<"Error: not a positive number."  << RESET<< std::endl;
		return;
	 }
	 if(std::atof(line.substr(12,line.size()).c_str()) >= INT_MAX)
	 {
		std::cout << RED <<"Error: too large a number"  << RESET<< std::endl;
		return;
	 }
	
	 std::map<std::string,float>::iterator it;
	 it =  _db.lower_bound(line.substr(0,10));
	 if( it->first !=  line.substr(0,10))
	 {
		 it--;
		std::cout << GREEN <<   line.substr(0,10) <<  " => "
		<<  std::atof(line.substr(12,line.size()).c_str()) <<" = "
		<<  it->second * std::atof(line.substr(12,line.size()).c_str())
		<< RESET<< std::endl;
		return;
	 }
		std::cout << GREEN <<   line.substr(0,10) <<  " => "
		<<  std::atof(line.substr(12,line.size()).c_str()) <<" = "
		<<  it->second * std::atof(line.substr(12,line.size()).c_str())
		<< RESET<< std::endl;
}

void BitcoinExchange::exec_file(std::string file)
{
	
	if( file.size() <= 4
			|| file[file.size()-1] != 't'
			|| file[file.size()-2] != 'x'
			|| file[file.size()-3] != 't' 
			|| file[file.size()-4] != '.'
			|| file[file.size()-6] == '/'  )
		throw Error_db();
	std::ifstream file_fd(file.c_str());
	std::string line;
	if(!file_fd )
		throw Error_db();

	std::getline(file_fd,line);
	while (std::getline(file_fd,line))
	{
		Exchange(line);
	}
}



BitcoinExchange::BitcoinExchange(std::string db)
{
	if( db.size() <= 4
		|| db[db.size()-1] != 'v'
		|| db[db.size()-2] != 's'
		|| db[db.size()-3] != 'c' 
		|| db[db.size()-4] != '.'
		|| db[db.size()-6] == '/'  )
		throw Error_db();
	std::ifstream db_fd(db.c_str());
	std::string line;
	if(!db_fd)
		throw Error_db();
	std::getline(db_fd,line);
	while (std::getline(db_fd,line))
	{
		add_db(line);
	}
	std::cout << "start btc" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy):_db(copy._db)
{
	std::cout << "copy BitcoinExchange" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "end btc" << std::endl;
}

const char* BitcoinExchange::Error_db::what() const  throw()
{
	return ("error : the database or input file is not standard format");
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if(this == &copy)
		return *this;
	this->_db = copy._db;
	return *this;
} 
