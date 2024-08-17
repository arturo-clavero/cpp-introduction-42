/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:46:40 by artclave          #+#    #+#             */
/*   Updated: 2024/08/16 16:31:46 by artclave         ###   ########.fr       */
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
#include <cstdlib> 
#include <algorithm>
#include <string> // For std::to_string

#define PURPLE "\033[38;2;0;0;205m"
#define BLUE "\033[38;2;135;206;250m"
#define RED "\033[38;2;255;0;0m"
#define RESET "\033[0m"


typedef std::map<std::string, std::string> tMap;
typedef	std::pair<std::string, std::string> tPair;

class	BitcoinExchange{
	private:
		tMap		_map;
		int			cont_digits(std::string const & str, int const max)const;
		int			incorrect_format(std::string  str)const;
		int			valid_date(int const year, int const month, int const day)const;

	public:
	//orthodox
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & other);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &other);
	//other
		void	get_rates(std::string const & name);
	//getters
		tMap	getMap() const;
};

#endif