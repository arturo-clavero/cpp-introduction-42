/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:21:35 by artclave          #+#    #+#             */
/*   Updated: 2024/07/22 05:51:39 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

std::map<std::string, std::string> parseFileDataToMap(){
	std::ifstream	csv_file("data.csv");
	if (!csv_file.is_open()) {
        std::cerr<<"Error opening csv file"<<"\n";
        exit (2);
    }
    std::string line;
	std::map<std::string, std::string> map;
	std::getline(csv_file, line);
	while (std::getline(csv_file, line)){
		int start, end, i =0;
			while (!std::isdigit(line[i]))
				i++;
			start = i;
			while (std::isdigit(line[i]) || line[i] == '-')
				i++;
			end = i;
			line[end] = 0;
		std::string date = &line[start];
		std::string rate = &line[end + 1];
		map.insert(std::pair<std::string, std::string>(date, rate));
	}
	csv_file.close();
	return map;
}

std::map<std::string, std::string>::iterator ft_find(std::map<std::string, std::string> map, std::string find){
	std::map<std::string, std::string>::iterator it = map.begin();
	while (it != map.end()){
		if (it->second == find)
			return it;
		if (it->second > find)
			return it;
		it++;
	}
	return it;
}
void	get_rate(std::string input, std::map<std::string, std::string> map){
	std::ifstream	input_file(input);
	if (!input_file.is_open()){
		std::cerr<<"Error opening input file"<<"\n";
        exit (2);
	}
	std::string line, date, rate;
	std::map<std::string, std::string>::iterator it;
	float final_rate;
	while (std::getline(input_file, line)){
	//	if (!check_format(line))
	//		continue;
		date = line.substr(0, 10);
		rate = line.substr(13, line.size() - 10);
		it = ft_find(map, date);
		if (it != map.end()){
		float frate = stof(it->second) * stof(rate);
	//	final_rate = std::stof(it->second) * std::stof(rate);// atof(rate) * *it;
		std::cout<<date<<" => "<<rate<<" = "<<frate<<"\n";}
		else
			std::cout<<"Errrrrror\n";
	}
	input_file.close();
}

int main(int ac, char **av) {
	(void)av;
	if (ac != 2){
		std::cerr<<"Invalid arguments"<<"\n";
		exit (2);
	}
	std::map<std::string, std::string> map;
	map = parseFileDataToMap();
	get_rate(av[1], map);
    return 0;
}
