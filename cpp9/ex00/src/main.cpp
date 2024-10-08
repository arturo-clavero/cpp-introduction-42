/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:49:56 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 01:00:12 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Error: invalid arguments, send the name of the texted file to be tested (as a single string)\n";
		exit (2);
	}
	try {
		BitcoinExchange bitcoin;
		bitcoin.get_rates(av[1]);
	}catch(std::exception &e){
		std::cerr<<RED<<"Error: "<<e.what()<<RESET;
	}
	return 0;
}