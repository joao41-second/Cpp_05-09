/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:52:03 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 11:05:01 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

int main(void )
{
	Base *base = Base::generate();

	Base::identify(*base);
	base->identify(base);


	delete base;

}
