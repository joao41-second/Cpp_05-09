/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:21:39 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 11:01:16 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>


#ifndef Base
#define BASE


class Base 
{
	public:
		virtual ~Base();
	static Base * generate(void);

	static void identify(Base& p);	
	static void identify(Base* p);
};



class A : public Base{};
class B : public Base{};
class C : public Base{};



#endif
