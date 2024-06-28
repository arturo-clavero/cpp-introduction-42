/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:27:11 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:29:36 by arturo           ###   ########.fr       */
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
	std::map<std::string, void(Harl::*)()>myMap;
	myMap["DEBUG"] = &Harl::debug;
	myMap["INFO"] = &Harl::info;
	myMap["WARNING"] = &Harl::warning;
	myMap["ERROR"] = &Harl::error;
	auto found = myMap.find(level);
	if (found != myMap.end())
	(this->*(found->second))();
}
