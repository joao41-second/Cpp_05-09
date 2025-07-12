/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:24:12 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/12 11:57:35 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN
#define INTERN

#include "AForm.hpp"
#include <string>

class AForm;


class Intern
{
	
	public:
	Intern();
	Intern(Intern &copy);
	~Intern();
	Intern &operator =(Intern & copy);

 	AForm* makeForm(std::string reques,std::string name);

	class NotValidForm : public std::exception
	{
		public:
			virtual const char *what() const throw();

	};
};



#endif
