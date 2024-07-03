/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:28:13 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 06:46:03 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

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