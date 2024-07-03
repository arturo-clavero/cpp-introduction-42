/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:27:53 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 06:57:52 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstring>
#include <cstdlib>   // For strtod


ScalarConverter::ScalarConverter() {
	std::cout<<"Default constructor for scalar converter class called\n";
}
	
ScalarConverter::ScalarConverter(ScalarConverter &original) {
	std::cout<<"Copy constructor for scalar converter class called\n";
	(void)original;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter &original) {
	std::cout<<"Copy assignment operator for scalar converter class called\n";
	(void)original;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout<<"Destructor called for scalar converter class\n";
}

void	ScalarConverter::convert(std::string input) {
	const char* inputCString = input.c_str();
    char* endPtr;
    double d = strtod(inputCString, &endPtr);
	std::cout<<"Double: "<<d<<"\n";
	float f = static_cast<float>(d);
	std::cout<<"Float: "<<f<<"\n";
	int i  = static_cast<int>(d);
	std::cout<<"Int: "<<i<<"\n";
	char c = static_cast<char>(i);
	std::cout<<"Char: "<<c<<"\n";
}