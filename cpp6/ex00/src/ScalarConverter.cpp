/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:27:53 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 15:28:05 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout<<"Default constructor for scalar converter class called\n";
}
	
ScalarConverter::ScalarConverter(const ScalarConverter &original) {
	std::cout<<"Copy constructor for scalar converter class called\n";
	(void)original;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &original) {
	std::cout<<"Copy assignment operator for scalar converter class called\n";
	(void)original;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout<<"Destructor called for scalar converter class\n";
}


void	printConversion(std::stringstream &ss, std::string dataType){
	std::string	result;
	
	result = ss.str();
	if (result.empty())
		result = "impossible";
	else if (dataType == "char" && !std::isprint(result[0]))
		result = "Non displayable";
	else if (dataType == "float")
		result += "f";
	std::cout<<dataType<<": "<<result<<"\n";
}

template <typename T>

void	explicitConversion(T data, bool exceptionInt)
{
	std::stringstream ss;
	ss<<static_cast<char>(data);
	if (exceptionInt)
		ss.str("impossible");
	printConversion(ss, "char");
	ss.str("");
	ss<<static_cast<int>(data);
	if (exceptionInt)
		ss.str("impossible");
	printConversion(ss, "int");
	ss.str("");
	ss<<std::fixed<<std::setprecision(1)<<static_cast<float>(data);
	printConversion(ss, "float");
	ss.str("");
	ss<<std::fixed<<std::setprecision(1)<<static_cast<double>(data);
	printConversion(ss, "double");
}

bool	isInt(std::string str){
	std::stringstream ss(str);
	int	i;
	ss>>i;
	if (ss.eof() && !ss.fail()){
		explicitConversion(i, false);
		return true;
	}
	return false;
}

bool	isDouble(std::string str){
	std::stringstream ss(str);
	double	d;
	ss>>d;
	if (ss.eof() && !ss.fail()){
		explicitConversion(d, false);
		return true;
	}
	d = std::atof(str.c_str());
	if (d){
		explicitConversion(d, true);
		return true;
	}
	return false;
}

bool	isFloat(std::string str){
	std::stringstream	ss(str);
	float	f;
	std::string	end;
	ss>>f;
	if (!ss.fail())
	{
		ss>>end;
		if (end.length() == 1 && end == "f")
		{
			explicitConversion(f, false);
			return true;
		}
	}
	f = std::atof(str.substr(0, str.length() - 1).c_str());
	if (f)
	{
			explicitConversion(f, true);
			return true;
	}
	return false;	
}

bool	isChar(std::string str){
	if (str.length() == 1 )
	{
		explicitConversion(str[0], false);
		return true;
	}
	return false;
}

void	ScalarConverter::convert(std::string const input) {
	if (isInt(input) || isDouble(input) || isFloat(input) || isChar(input))
		return ;
	std::cout<<"Sorry, conversion is not possible\n Input is neither a char, nor an int, nor a double or a float\n";
}