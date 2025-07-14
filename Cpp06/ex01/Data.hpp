/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:34:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 09:43:38 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <string>

#ifndef DATA
#define DATA

class Data
{
	private:
		std::string _name;
	public:
		Data(std::string name);
		Data(Data& copy);
		~Data();
		Data& operator =(Data &copy);
		std::string get_name();
	

};

#endif
