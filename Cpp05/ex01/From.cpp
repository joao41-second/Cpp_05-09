/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:18:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/10 16:43:00 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FROM_CPP
#define FROM_CPP

#include <cmath>
#include <cstddef>
#include <exception>
#include <ostream>
#include <string>
class Form
{
	private:
		const std::string _name;
		bool _signed;
		const size_t _sign_it;
		const size_t _execute_it;
		void error(size_t);

	public:
		Form();
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		std::string get_name();
		bool get_signed();
		size_t get_sing_it();
		size_t get_execute_it();
		void signForm(); // if Bureaucrat to have rank sign the Form  
		void beSigned(); // print if form this signed or not signed

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*wait() const throw();
		};
		class GradeTooHighException
		{
			public:
				virtual const char* wait()  const  throw();
		};

};

std::ostream operator <<(std::ostream &o, Form *str);

#endif
