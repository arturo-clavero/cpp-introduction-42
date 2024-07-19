/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:40:15 by artclave          #+#    #+#             */
/*   Updated: 2024/07/20 05:30:34 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac < 2){
		std::cerr<<"Not enough arguments\n";
		return 2;
	}
	std::string	op = "+-*/ ";
	for (int i = 0; av[1][i]; i++){
		if (!std::isdigit(av[1][i]) && op.find(av[1][i]) == std::string::npos) {
			std::cerr<<"Error\n";
			return 2;
		}
	}
	rpn(av[1]);
}