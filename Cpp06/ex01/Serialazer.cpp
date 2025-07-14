/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialazer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:32:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 10:15:05 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Serialazer.hpp"
#include "colors.hpp"
#include <bits/types.h>
#include <stdint.h>


Serialazer::Serialazer()
{
	std::cout << "start the  Scalar Converter" << std::endl;
}

Serialazer::Serialazer(Serialazer & copy)
{

	std::cout << "start the Scalar Converter copy" << std::endl;
	*this = copy;
}

Serialazer::~Serialazer()
{

	std::cout << "end the Scalar Converter" << std::endl;
}

Serialazer & Serialazer::operator=(Serialazer &copy)
{
	if(this == &copy)
		return (*this);
	return *this;
}

uintptr_t Serialazer::serialaze(Data *data)
{
	uintptr_t nb;
	nb = reinterpret_cast <uintptr_t>( data);
	return nb;
}

Data * Serialazer::deserialize(uintptr_t nb)
{
	Data * data;


	data = reinterpret_cast<Data*>(nb);
	return data;
}
