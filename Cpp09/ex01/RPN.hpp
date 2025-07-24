/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:50:49 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/24 12:53:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RPN_HPP
#define  RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <string>


#define valid_char std::string( "+-/* ")

class RPN
{
	private:
		std::stack<int> _stack;
		std::string 	_save;
	public:
		RPN(std::string input);
		RPN(const RPN & copy );
		~RPN();
		RPN &operator = (RPN const &copy);
		void exec();
	
		class error_input : public std::exception
		{
			virtual const char * what() const throw();
		};
};

#endif
