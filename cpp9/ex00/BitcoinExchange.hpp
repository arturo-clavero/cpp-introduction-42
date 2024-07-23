/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:46:40 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 10:53:27 by arturo           ###   ########.fr       */
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
		tMap	map;
		int	cont_digits(std::string str, int max);
		int	incorrect_format(std::string &str);
		int	valid_date(int year, int month, int day);

	public:
	//ORTHODOX:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &og);
		BitcoinExchange	&operator=(BitcoinExchange const &og);
		~BitcoinExchange();
	//MEMBER FUNCTION
		void	get_rates(std::string name);
};

#endif