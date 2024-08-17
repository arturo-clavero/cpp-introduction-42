/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:40:15 by artclave          #+#    #+#             */
/*   Updated: 2024/08/14 16:58:50 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Invalid arguments\n";
		return 2;
	}
	std::cout<<BLUE<<"\n\n<"<<av[1]<<">\n"<<RESET;
	RPN op(av[1]);
	std::cout<<GREEN<<"The answer is:\t"<<op.solve()<<"\n"<<RESET;
}