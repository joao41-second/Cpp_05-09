
#ifndef FROM_HPP
#define FROM_HPP

#include <cmath>
#include <cstddef>
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		const size_t _execute_it;
		const size_t _sign_it;
		bool _signed;
		bool error(size_t);

	public:
		AForm(std::string name,size_t sign_it,size_t execute_it);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		std::string get_name();
		bool get_signed();
		size_t get_sing_it();
		size_t get_execute_it();

		void beSigned(Bureaucrat &brucart); // print if form this signed or not signed
		virtual void exexecute(Bureaucrat & executor) = 0;

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

std::ostream &operator <<(std::ostream &oi, AForm &copy);

#endif
