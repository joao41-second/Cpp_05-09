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

#include <iostream>

#define MAX_VAL 750
/*
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/

int main()
{


	 Array<int> ok_ (50);

	 Array<int> end (50);

	try 
	{
		ok_[2] = 25;


	 	const Array<int> ok = ok_;
		ok[2] = 2;
		std::cout << ok_[2] << std::endl;
		std::cout << ok[2] << std::endl;
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
