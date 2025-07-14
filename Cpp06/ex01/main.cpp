/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:38:26 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 10:02:40 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Data.hpp"
#include "Serialazer.hpp"
#include "colors.hpp"
#include <iostream>

#include <stdint.h>
int main()
{
	Data *data = new Data("ola");

	std::cout << YELLOW << data->get_name() <<  RESET<< std::endl;

	uintptr_t save_int = Serialazer::serialaze(data);

	std::cout << RED << save_int << RESET << std::endl;

	Data *move = Serialazer::deserialize(save_int);

	std::cout << YELLOW << move->get_name() <<  RESET<<std::endl;


}
