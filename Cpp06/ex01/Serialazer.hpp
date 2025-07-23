/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialazer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:31:05 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 10:01:04 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/types.h>

#include <stdint.h>

#ifndef SERIALAZER
#define SERIALAZER

#include "Data.hpp"

class Serialazer
{
	public:
		static uintptr_t serialaze(Data *data);
		static Data* deserialize(uintptr_t raw);
	private: 
		Serialazer();
		Serialazer(Serialazer const & copy);
		~Serialazer();
		Serialazer& operator =(Serialazer const &copy);

};

#endif
