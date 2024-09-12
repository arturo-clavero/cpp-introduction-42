/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:40:15 by artclave          #+#    #+#             */
/*   Updated: 2024/09/12 16:32:27 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Invalid arguments\n";
		return 2;
	}
	RPN op(av[1]);
	std::cout<<op.solve()<<"\n";
}