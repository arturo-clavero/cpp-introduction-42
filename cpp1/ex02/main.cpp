/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:15:50 by arturo            #+#    #+#             */
/*   Updated: 2024/06/01 19:30:13 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	&str_reference = str;
	std::string	*str_pointer = &str;

	std::cout<<"Memory address of string:           "<<&str<<"\n";
	std::cout<<"Memory address of string reference: "<<&str_reference<<"\n";
	std::cout<<"Memory address of string pointer:   "<<str_pointer<<"\n\n";
	std::cout<<"Value of string:           "<<str<<"\n";
	std::cout<<"Value of string reference: "<<str_reference<<"\n";
	std::cout<<"Value of string pointer:   "<<*str_pointer<<"\n";
}