/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:27:11 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 20:58:02 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout<<"This is a debugging message\n";
}

void	Harl::info(void)
{
	std::cout<<"This is some info\n";
}	

void	Harl::warning(void)
{
	std::cout<<"This is a warning\n";
}	

void	Harl::error(void)
{
	std::cout<<"This is an error\n";
}

void	Harl::complain(std::string level)
{
	void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	arrayLevels[4] = {"DEBUG", "COMPLAIN", "INFO", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == arrayLevels[i])
			(this->*functions[i])();
	}
}
