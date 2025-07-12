#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
 	Bureaucrat *ola = NULL;
	AForm        *minishel = NULL;
	AForm        *form2 = NULL;
	AForm        *form3 = NULL;
	try{
	  ola = new Bureaucrat("osvaldo",5);
	  minishel = new ShrubberyCreationForm("new2.txt");
	  form2 = new RobotomyRequestForm("antomio");
	  form3 = new PresidentialPardonForm("antomio end");
	  std::cout << ola << std::endl;
	  ola->increment();
	  std::cout << ola << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<"error : " << e.what() << std::endl;
	}


	ola->signAForm(*minishel);

		std::cout <<"---------- " << std::endl;
	ola->executeForm(*minishel);

		std::cout <<"---------- " << std::endl;

	ola->signAForm(*form2);

		std::cout <<"---------- " << std::endl;
	ola->executeForm(*form2);

		std::cout <<"---------- " << std::endl;

	ola->signAForm(*form3);

		std::cout <<"---------- " << std::endl;
	ola->executeForm(*form3);

		std::cout <<"---------- " << std::endl;
		

	std::cout << "status form : name:" << minishel->get_name()  << " sign  ? "<< minishel->get_signed() << std::endl;
	if(ola != NULL)
		delete ola;
	if(minishel != NULL)
		delete minishel;
	if(form2 != NULL)
		delete form2;
	if(form3 != NULL)
		delete form3;


	

}
