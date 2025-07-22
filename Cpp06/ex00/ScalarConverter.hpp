/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:12:10 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/13 10:54:53 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCALAR
#define SCALAR


#include <iostream>
#include "colors.hpp"

class ScalarConverter 
{
	public:
		static  void convert(const std::string str);
	private: 
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();
		ScalarConverter& operator =(const ScalarConverter &copy);

	static	bool is_char(std::string str);
	static	bool is_int(std::string str);	
	static	bool is_float(std::string str);
	static	bool is_double(std::string str);

	static	void from_char(std::string str);
	static	void from_int(std::string str);
	static	void from_float(std::string str);
	static	void from_double(std::string str);

};

#endif

