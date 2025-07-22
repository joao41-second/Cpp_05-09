

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <cstddef>
#include <exception>
#include <ostream>
#include <string>

class AForm;
class Bureaucrat
{

	private:
		const std::string _name;
		size_t		  _grade;
		void setgrad(size_t grade);
	public:
		Bureaucrat(std::string name,size_t grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);
		std::string 	getName() const ;
		size_t		getGrade() const ;
		void 		increment();
		void 		decrement();

		void		signAForm(AForm &form);	
		void executeForm(AForm &form);


	class GradeTooHighException : public std::exception
	{
		public:
			virtual	const char *what()const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what()const throw();
	};
};

std::ostream &operator << (std::ostream &o,Bureaucrat *copy);
#endif
