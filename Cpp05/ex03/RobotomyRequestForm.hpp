/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:18:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:18:09 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#ifndef FROM2
#define FROM2

class AForm;
class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
	public:
	  RobotomyRequestForm();
	  RobotomyRequestForm(std::string name_file);
	  RobotomyRequestForm(RobotomyRequestForm&copy);
	  ~RobotomyRequestForm();
	  RobotomyRequestForm & operator=(const RobotomyRequestForm &copy);

	  void exexecute(Bureaucrat  & executor);

	
};

#endif


