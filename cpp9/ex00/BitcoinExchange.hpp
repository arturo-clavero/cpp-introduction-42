/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:46:40 by artclave          #+#    #+#             */
/*   Updated: 2024/07/22 12:03:54 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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