/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:23 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 11:23:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <sstream>

/*
Class	PmergeMe(){
	public: 
}*/

template <typename T>
void	ford_algo(T & input){
	T max, min;
	split(input, &max, &min);
	if (max.size() > 1)
		ford_algo(max);
	binary_sort(max, min);
	input = max;
}

template <typename T>
void	recursive_sort(T & max, int &low, int &high, int x){
	//std::cout<<"\n\n x is : "<<x<<"\n";
	int	m = (low + high) / 2;
//	std::cout<<" m is : "<<m<<"\n";
//	std::cout<<"low and hig=h before are "<<low<<" "<<high<<"\n";
	if (x < max[m])
		high = m - 1;
	else if (x > max[m])
		low = m + 1;
	else {
	//	std::cout<<"insert at "<<m<<"\n";
		max.insert(max.begin() + m, x);
		return ;
	}
	//std::cout<<"low and high after are "<<low<<" "<<high<<"\n";
	if (low > high)
	{
		//std::cout<<"rrrr insert at "<<low<<"\n";
		max.insert(max.begin() + low, x);
		return ;
	}
	recursive_sort(max, low, high, x);

}

template <typename T>
void	binary_sort(T & max, T & min){
	int	low, high;
	low = 0;
	high = static_cast<int>(max.size()) - 1;
	for (int i = 0; i < static_cast<int>(min.size()); i++)
		recursive_sort(max, low, high, min[i]);
}

template <typename T>
void split(T input, T & max, T & min){
	for (int j = 0; j < static_cast<int>(input.size()); j+=2)
	{
		if (j + 2 > static_cast<int>(input.size()))
			min.push_back(input[j]);
		else if (input[j] >= input[j + 1]) {
			max.push_back(input[j]);
			min.push_back(input[j + 1]);
		}
		else {
			min.push_back(input[j]);
			max.push_back(input[j + 1]);
		}
	}
}

void	error(std::string msg) {
	std::cerr<<msg;
	exit (2);
}
bool isValidChar(char c, const std::string &haystack) {
    return haystack.find(c) != std::string::npos;
}

std::vector<int>	init(char **av) {
	std::vector<int> vec;
	std::string allowed = "0123456789 +";
	int	num;
	std::string str;
	for (int i = 1; av[i]; i++) {
		str = av[i];
   		if (std::find_if(str.begin(), str.end(), std::bind2nd(std::ptr_fun(isValidChar), allowed)) == str.end())
		{
			error("Invalid expression: only digits, '+' and spaces allowed\n");
		}
		std::string::const_iterator it = std::find_if(str.begin(), str.end(), std::bind2nd(std::ptr_fun(isValidChar), "+"));
		if (it != str.end() && ((it != str.begin() && *(it - 1) != ' ') || (!std::isdigit(*(it + 1)))))
		{
			error("Invalid expression\n");
		}
		for (int j = 0; str[j]; j++)
		{
			while (str[j] && str[j] == ' ')
				j++;
			std::stringstream ss(&str[j]);
    		ss >> num;
			if (num < 0)
				error("Only positiive numebers!!!\n");
			vec.push_back(num);
			if (str[j] == '+')
				j ++;
			j += abs(num) / 10;
			num = -1;
		}
	}
	return vec;
}

std::ostream	&operator<<(std::ostream & out, std::vector<int> vec){
	for (int i=0; i < static_cast<int>(vec.size()); i++)
		out<<vec[i]<<" ";
	out<<"\n";
	return out;
}


#endif