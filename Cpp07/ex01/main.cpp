/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:39:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 08:50:02 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include "iostream"
#include <string>
#include <vector>

void print(int a)
{
	std::cout<< "int is :"  << a << std::endl;
}
void print_(std::string a)
{
	std::cout<< "int is :"  << a << std::endl;
}

int main()
{

	int nb[5] = {1,2,3,4,5};
//	std::vector<std::string> ok(2);
//	ok[0] = "ola0";
//	ok[1] = "end";
	iter(nb,2,print);



}
