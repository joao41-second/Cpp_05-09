

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <ostream>
#include <string>
class Bureaucrat
{

	private:
		const std::string name;
		int rank;
		void setgrad();

	public:
		Bureaucrat(std::string name,int rank);
		Bureaucrat(Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat &copy);





};

std::ostream &operator <<(std::ostream &o,Bureaucrat &copy);


#endif
