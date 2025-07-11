#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Bureaucrat.hpp"

int main()
{
 	Bureaucrat *ola = NULL;
	Form        *minishel = NULL;
	try{
	  ola = new Bureaucrat("osvaldo",150);
	  minishel = new Form("mini",150,15);
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}


	ola->signForm(*minishel);

	std::cout << "status form : name:" << minishel->get_name()  << " sign  ? "<< minishel->get_signed() << std::endl;
	if(ola != NULL)
		delete ola;
	if(minishel != NULL)
		delete minishel;


	

}
