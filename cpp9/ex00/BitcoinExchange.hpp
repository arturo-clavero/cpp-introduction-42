/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:46:40 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 13:32:22 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <stdlib.h>

typedef std::map<std::string, std::string> tMap;
typedef	std::pair<std::string, std::string> tPair;

class	BitcoinExchange{
	private:
		static int	cont_digits(std::string str, int max);
		static int	incorrect_format(std::string &str);
		static int	valid_date(int year, int month, int day);

	public:
	//MEMBER FUNCTION
		void	get_rates(std::string name);
		tMap	init_map(char **av);
};

#endif