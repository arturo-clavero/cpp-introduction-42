/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:40:15 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 05:07:55 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Invalid arguments\n";
		return 2;
	}
	int mode = 0;
	std::cout<<"Would you like to use signed integers? [y/n]\n";
	std::string user_input;
	std::cin>>user_input;
	if (user_input == "y" || user_input == "Y")
		mode = 1;
	std::cout<<BLUE<<"\n\n<"<<av[1]<<">\n"<<RESET;
	RPN op(av[1], mode);
	std::cout<<GREEN<<"The answer is:\t"<<op.solve()<<"\n"<<RESET;
}