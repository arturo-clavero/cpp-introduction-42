/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:28:13 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 18:59:54 by arturo           ###   ########.fr       */
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
		ScalarConverter(const ScalarConverter &original);
		ScalarConverter	&operator=(const ScalarConverter &original);
		~ScalarConverter();

	public:
		static void convert(std::string input);
};

#endif