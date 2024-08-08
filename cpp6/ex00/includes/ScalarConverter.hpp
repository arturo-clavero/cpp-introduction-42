/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:28:13 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 15:27:49 by artclave         ###   ########.fr       */
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
		static void convert(std::string const input);
};

#endif