/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:35:16 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:21:50 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM1
#define FORM1

#include "AForm.hpp"
#include <string>

class AForm;
class Bureaucrat;
class ShrubberyCreationForm: public AForm
{
	private:
		std::string _shrubbery;
	public:
	  ShrubberyCreationForm();
	  ShrubberyCreationForm(std::string name_file);
	  ShrubberyCreationForm(ShrubberyCreationForm& copy);
	  ~ShrubberyCreationForm();
	  ShrubberyCreationForm & operator=(const ShrubberyCreationForm &copy);

	  void exexecute(Bureaucrat  & executor);

	
};

#endif
