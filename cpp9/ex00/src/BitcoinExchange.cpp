/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:45 by artclave          #+#    #+#             */
/*   Updated: 2024/08/17 17:35:35 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//ORTHODOX:
BitcoinExchange::BitcoinExchange(){
	std::cout<<BLUE<<"Constructor called\n"<<RESET;
	std::ifstream csv("data.csv");
	if (!csv.is_open())
		throw std::runtime_error("Error: can't open csv file\n");
	std::string line, date, rate;
	std::getline(csv, line);
	while (std::getline(csv, line)){
		date = line.substr(0, 10);
		rate = line.substr(11, static_cast<int>(line.size()) - 10);
		_map.insert(tPair(date, rate));
	}
	csv.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &og){
	std::cout<<BLUE<<"Copy constructor called\n"<<RESET;
	_map = og.getMap();
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &og){
	std::cout<<BLUE<<"Copy assignmetn operator called\n"<<RESET;
	_map = og.getMap();
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout<<PURPLE<<"Destructor called\n"<<RESET;
}

//GETTERS

tMap	BitcoinExchange::getMap() const{
	return _map;
}

//MEMBER FUNCTION
void	BitcoinExchange::get_rates(std::string const &name){
	std::ifstream	file(name.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: can't open input file\n");
	std::string line, date;
	float rate, final_rate;
	std::getline(file, line);
	if (line.empty())
		std::cerr<<"Error: input file is empty\n";
	else if (line != "date | value")
		std::cerr<<"Error: input file should start with 'date | value' followed by a newline\n";
	while (std::getline(file, line)){
		if (this->incorrect_format(line) == 0){
			date = line.substr(0, 10);
			rate = std::atof(line.substr(13, static_cast<int>(line.size()) - 10).c_str());
			tMap::iterator it = _map.find(date);
			if (it == _map.end())
				it = _map.upper_bound(date);
			final_rate = rate * std::atof(it->second.c_str());
			std::cout<<date<<" => "<<rate<<" = "<<final_rate<<"\n";
		}
	}
	file.close();
}

//PRIVATE HELPERS FTS
int	BitcoinExchange::cont_digits(std::string const &str, int const max)const{
	for (int i = 0; i < max; i++){
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

int	BitcoinExchange::valid_date(int const year, int const month, int const day)const{
	if ((month > 12 || month < 1 || day < 1 || day > 31 || year < 1) || 	//(1)-> months outside [1-12], days outside[1-31], negative years
		(day == 31 && (month == 4 || month == 6 || month == 9 || month == 10)) ||   //(2)-> day 31 and months that don't have 31st
		(month == 2 && day > 29) || (month == 2 && year % 4 != 0 && day == 29))		//(3)->february and days +29 or day 29th on none-leap-years
		return 0;
	if (year < 2009 || (year == 2009 && month == 1 && day < 3)){ //(4)->date too early to be valid
		std::cerr<<("Bitcoin was launched on 2009-01-03. ");
		return 0;
	}
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	now->tm_mon++;
	if (year > now->tm_year || (year == now->tm_year && (month > now->tm_mon || (month == now->tm_mon && day > now->tm_mday)))){ //(5)->date in the future ... 
		std::cerr<<"Do you have a time machine? ";
		return 0;
	}
	return 1;
}

bool	valid_char(char c, std::string haystack){
	return (std::find(haystack.begin(), haystack.end(), c) == haystack.end());
}

bool	check_rate(std::string &str){
	std::string::iterator begin = str.begin();
	while (begin != str.end() && *begin == ' ')
		begin++;
	if (*begin == '+' || *begin == '-')
		begin++;
	std::string haystack = "0123456789 .";
	if (find_if(begin, str.end(), std::bind2nd(std::ptr_fun(valid_char), haystack)) != str.end()
		|| std::count(begin, str.end(), '.') > 1
 		|| !std::isdigit(*begin))
	{
		std::cout<<"Error: incorrect rate format\n";
		return false;
	}
	while (*begin != ' ' && begin != str.end())
		begin++;
	for (; begin != str.end(); begin++)
	{
		if (*begin != ' ')
		{
			std::cout<<"Error: incorrect rate format\n";
			return false;
		}
	}
	return true;
}

int	BitcoinExchange::incorrect_format(std::string str)const{
	int i = 0;
	while (str[i] == ' ')
			i++;
	str = &str[i];
	if (str.size() < 14){
		std::cerr<<"Error: incomplete information\n";
		return 1;
	}
	if (!this->cont_digits(str, 4) || str[4] != '-' || !this->cont_digits(&str[5], 2) || str[7] != '-' || !this->cont_digits(&str[8], 2))
	{
		std::cerr<<"Error: incorrect Year-Month-Day format ("<<str.substr(0, 10)<<")\n";
		return 1;
	}
	if (str.substr(10, 3) != " | "){
		std::cerr<<"Error: incorrect format, dates and rates must be separated by ' | '\n";
		return 1;
	}
	if (this->valid_date(std::atoi(str.substr(0, 4).c_str()), std::atoi(str.substr(5, 2).c_str()), std::atoi(str.substr(8, 2).c_str())) == 0){
		std::cerr<<"This date is not valid ("<<str.substr(0, 10)<<")\n";
		return 1;
	}
	std::string num_string = str.substr(13, static_cast<int>(str.size()) - 10);
	if (!check_rate(num_string))
		return 1;
	std::cout<<"num string "<<num_string<<"\n";
	float rate = std::atof(num_string.c_str());
	if (rate < 0 || rate > 1000){
		std::cerr<<"Error: incorrect rate range\n";
		return 1;
	}
	return 0;
}	
