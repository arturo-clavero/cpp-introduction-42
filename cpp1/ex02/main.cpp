/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:15:50 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:31:15 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	&stringREF = str;
	std::string	*stringPTR = &str;

	std::cout<<"Memory address of string:           "<<&str<<"\n";
	std::cout<<"Memory address of string reference: "<<&stringREF<<"\n";
	std::cout<<"Memory address of string pointer:   "<<stringPTR<<"\n\n";
	std::cout<<"Value of string:           "<<str<<"\n";
	std::cout<<"Value of string reference: "<<stringREF<<"\n";
	std::cout<<"Value of string pointer:   "<<*stringPTR<<"\n";
}