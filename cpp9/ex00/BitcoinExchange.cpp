/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:45 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 11:14:09 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
int	BitcoinExchange::cont_digits(std::string str, int max){
	for (int i = 0; i < max; i++){
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

int	BitcoinExchange::valid_date(int year, int month, int day){
	if (month > 12 || month < 1 || day < 1 || day > 31 || year < 1)
		return 0;
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 10))
		return 0;
	if (month == 2 && day > 29)
		return 0;
	if (month == 2 && year % 4 != 0 && day == 29)
		return 0;
	if (year < 2009 || (year == 2009 && month == 1 && day < 3)){
		std::cerr<<("Bitcoin was launched on 2009-01-03. ");
		return 0;
	}
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	now->tm_year += 1900;
	now->tm_mon++;
	if (year > now->tm_year || (year == now->tm_year && (month > now->tm_mon || (month == now->tm_mon && day > now->tm_mday)))){
		std::cerr<<"Do you have a time machine? ";
		return 0;
	}
	return 1;
}

int	BitcoinExchange::incorrect_format(std::string &str){
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
	float rate = std::atof(str.substr(13, static_cast<int>(str.size()) - 10).c_str());
	if (rate < 0){
		std::cerr<<"Error: rates must be positive\n";
		return 1;
	}
	if (rate > 1000){
		std::cerr<<"Error: rates can't be larger than 1000\n";
		return 1;
	}
	return 0;
}	

//ORTHODOX:
BitcoinExchange::BitcoinExchange(){
	//std::cout<<"Default constructor called\n";
	std::ifstream csv("data.csv");
	if (!csv.is_open())
		throw std::runtime_error("Error: can't open csv file\n");
	std::string line, date, rate;
	std::getline(csv, line);
	while (std::getline(csv, line)){
		date = line.substr(0, 10);
		rate = line.substr(11, static_cast<int>(line.size()) - 10);
		map.insert(tPair(date, rate));
	}
	csv.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &og){
	//std::cout<<"Copy constructor called\n";
	map = og.map;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &og){
	//std::cout<<"Copy assignment operator called\n";
	map = og.map;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
	//std::cout<<"Destructor called\n";
}

//MEMBER FUNCTION
void	BitcoinExchange::get_rates(std::string name){
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
			tMap::iterator it = map.find(date);
			if (it == map.end())
				it = map.upper_bound(date);
			final_rate = rate * std::atof(it->second.c_str());
			std::cout<<date<<" => "<<rate<<" = "<<final_rate<<"\n";
		}
	}
	file.close();
}