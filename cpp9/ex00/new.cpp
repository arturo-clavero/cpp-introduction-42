/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:22:22 by artclave          #+#    #+#             */
/*   Updated: 2024/07/22 08:52:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

typedef std::map<std::string, std::string> tMap;
typedef	std::pair<std::string, std::string> tPair;

void	print_map(tMap map){
	for (tMap::iterator it = map.begin(); it != map.end(); it++){
		std::cout<<"'"<<it->first<<"' '"<<it->second<<"'\n";
	}
}

tMap	init_map(){
	tMap map;
	std::ifstream csv("data.csv");
	if (!csv.is_open()){
		std::cerr<<"Error: can't open csv file\n";
		exit (2);
	}
	std::string line, date, rate;
	std::getline(csv, line);
	while (std::getline(csv, line)){
		date = line.substr(0, 10);
		rate = line.substr(11, static_cast<int>(line.size()) - 10);
		map.insert(tPair(date, rate));
	}
	csv.close();
	return map;
}

int	cont_digits(std::string str, int max){
	for (int i = 0; i < max; i++){
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

int	incorrect_format(std::string &str){
	int i;
	if (str.size() < 14){
		std::cerr<<"Error: incomplete information\n";
		return 1;
	}
	if (!cont_digits(str, 4) || str[4] != '-' || !cont_digits(&str[5], 2) || str[7] != '-' || !cont_digits(&str[8], 2))
	{
		std::cerr<<"Error: incorrect Year-Month-Day format ("<<str.substr(0, 10)<<")\n";
		return 1;
	}
	if (str.substr(10, 3) != " | "){
		std::cerr<<"Error: incorrect format, dates and rates must be separated by ' | '\n";
		return 1;
	}
	float rate = std::stof(str.substr(13, static_cast<int>(str.size()) - 10));
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

void	get_rates(std::string name, tMap map){
	std::ifstream	file(name);
	if (!file.is_open()){
		std::cerr<<"Error: can't open "<<name<<" file\n";
		exit (2);
	}
	std::string line, date;
	float rate, final_rate;
	std::getline(file, line);
	if (line.empty()){
		std::cerr<<"Error: input file is empty\n";
	}
	else if (line != "date | value"){
		std::cerr<<"Error: input file should start with 'date | value' followed by a newline\n";
	}
	while (std::getline(file, line)){
		if (incorrect_format(line))
			continue;
		date = line.substr(0, 10);
		rate = std::stof(line.substr(13, static_cast<int>(line.size()) - 10));
		tMap::iterator it = map.find(date);
		if (it == map.end())
			it = map.upper_bound(date);
		final_rate = rate * std::stof(it->second);
		std::cout<<date<<" => "<<rate<<" = "<<final_rate<<"\n";
	}
	file.close();

}

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Error: invalid arguments\n";
		exit (2);
	}
	tMap map = init_map();
	get_rates(av[1], map);
}
	