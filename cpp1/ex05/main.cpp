/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:16:12 by arturo            #+#    #+#             */
/*   Updated: 2024/06/03 15:51:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
/*
Harl also has a public member function that calls the four member functions above
depending on the level passed as parameter:
void
complain( std::string level );
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own.
*/
class Harl
{
	private:
		void	debug(void)
		{
			std::cout<<"This is a debugging message\n";
		}
		void	info(void)
		{
			std::cout<<"This is some info\n";
		}	
		void	warning(void)
		{
			std::cout<<"This is a warning\n";
		}	
		void	error(void)
		{
			std::cout<<"This is an error\n";
		}
	public:
		void	complain(std::string level)
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
};

int	main(void)
{
	Harl	test;

	test.complain("DEBUG");
}