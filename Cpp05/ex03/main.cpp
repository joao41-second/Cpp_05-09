#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
 	Bureaucrat *ola = NULL;
	Intern  osvaldo;
	AForm        *minishel = NULL;
	try{
	  ola = new Bureaucrat("osvaldo",5);
	 minishel = osvaldo.makeForm("PresidentialPardonForm", "elias");
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}
	

	ola->signAForm(*minishel);

	ola->executeForm(*minishel);

		

	std::cout << "status form : name:" << minishel->get_name()  << " sign  ? "<< minishel->get_signed() << std::endl;
	if(ola != NULL)
		delete ola;
	if(minishel != NULL)
		delete minishel;

	

}
