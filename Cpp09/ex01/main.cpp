/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:48:29 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/24 13:11:33 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "RPN.hpp"
#include <exception>
#include <ostream>
#include <string>


int main(int argc, char **argv)
{
	if(argc == 2)
	{

		std::string input(argv[1]);
		try
		{
			RPN ok (input);
			ok.exec();
		}
		catch(std::exception &e)
		{
			std::cout << "error :" << e.what() << std::endl;
		}
	}
	else 
	{
		std::cout << "not valid arguments" << std::endl;
	}
}
