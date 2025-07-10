#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include "Bureaucrat.hpp"

int main()
{
 	Bureaucrat *ola = NULL;
	try{
	  ola = new Bureaucrat("osvaldo",150);
	  std::cout << ola << std::endl;
	  ola->decrement();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}
	if(ola != NULL)
		delete ola;
	try{
	  ola = new Bureaucrat("osvaldo",1);
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}
	if(ola != NULL)
		delete ola;
	try{
	  ola = new Bureaucrat("osvaldo",35);
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}

	if(ola != NULL)
		delete ola;

}
