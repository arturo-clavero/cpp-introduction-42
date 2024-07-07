/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:28:13 by arturo            #+#    #+#             */
/*   Updated: 2024/07/07 23:54:11 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cstdlib>   

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &original);
		ScalarConverter	&operator=(ScalarConverter &original);
		~ScalarConverter();

	public:
		static void convert(std::string input);
};

#endif