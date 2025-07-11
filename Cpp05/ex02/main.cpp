#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
 	Bureaucrat *ola = NULL;
	AForm        *minishel = NULL;
	try{
	  ola = new Bureaucrat("osvaldo",15);
	  minishel = new ShrubberyCreationForm();
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}


	ola->signAForm(*minishel);
//
		std::cout <<"---------- " << std::endl;
	ola->executeForm(*minishel);

		std::cout <<"---------- " << std::endl;
		

	std::cout << "status form : name:" << minishel->get_name()  << " sign  ? "<< minishel->get_signed() << std::endl;
	if(ola != NULL)
		delete ola;
	if(minishel != NULL)
		delete minishel;


	

}
