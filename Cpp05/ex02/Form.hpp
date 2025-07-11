
#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"
#include <cmath>
#include <cstddef>
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;
class Form
{
	private:
		const std::string _name;
		const size_t _execute_it;
		const size_t _sign_it;
		bool _signed;
		bool error(size_t);

	public:
		Form(std::string name,size_t sign_it,size_t execute_it);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		std::string get_name();
		bool get_signed();
		size_t get_sing_it();
		size_t get_execute_it();

		void beSigned(Bureaucrat &brucart); // print if form this signed or not signed

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*what() const throw();
		};
		class GradeTooHighException
		{
			public:
				virtual const char* what()  const  throw();
		};

};

std::ostream &operator <<(std::ostream &oi, Form &copy);

#endif
