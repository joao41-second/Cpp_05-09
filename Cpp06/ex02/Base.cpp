/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:41:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 11:04:31 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>




Base::~Base()
{

 std::cout << "end base" << std::endl;
}


Base * Base::generate()
{
	srand(static_cast<unsigned int>(time(0)));
	int i = random();

	if(i % 2 == 0)
		return new A(); 
	else if(i/2 % 2 == 0)
		return new B(); 
	else 
		return new C();  
}


void Base::identify(Base* p)
{
	std::cout <<"* pointer *" << std::endl;
	if(dynamic_cast<A*>(p))
		std::cout << "class A"  << std::endl;
	if(dynamic_cast<B*>(p))
		std::cout << "class B"  << std::endl;
	if(dynamic_cast<C*>(p))
		std::cout << "class C"  << std::endl;
}


void Base::identify(Base& p)
{
	Base *p_ = &p;
	std::cout << "& Reference &" << std::endl;
	if(dynamic_cast<A*>(p_))
		std::cout << "class A"  << std::endl;
	if(dynamic_cast<B*>(p_))
		std::cout << "class B"  << std::endl;
	if(dynamic_cast<C*>(p_))
		std::cout << "class C"  << std::endl;
}



