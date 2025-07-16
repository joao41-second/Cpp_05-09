/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 15:06:32 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"
#include <algorithm>
#include <ostream>

int main()
{


	 Array<int> ok_ (50);

	 Array<int> end (50);

	try 
	{
		ok_[2] = 25;


	 	Array<int> ok = ok_;
		ok[2] = 2;
		std::cout << ok_[2] << std::endl;
		std::cout << ok[2] << std::endl;		
		end = ok_;
		std::cout << ok_[2] << std::endl;	
		std::cout << end[2] << std::endl;
		end[2] = 55;
		std::cout << ok_[2] << std::endl;	
		std::cout << end[2] << std::endl;


	}
	catch (const std::exception &e)
	{
		std::cout << "error  " << e.what()  << std::endl;
	}


}
