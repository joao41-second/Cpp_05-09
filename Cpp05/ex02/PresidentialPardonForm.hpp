/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:35:16 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:23:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROM3
#define FROM3

#include "AForm.hpp"
class AForm;
class PresidentialPardonForm: public AForm
{
	private:
		std::string _shrubbery;
	public:
	  PresidentialPardonForm();
	  PresidentialPardonForm(PresidentialPardonForm&copy);
	  ~PresidentialPardonForm();
	  PresidentialPardonForm & operator=(const PresidentialPardonForm &copy);

	
};

#endif
