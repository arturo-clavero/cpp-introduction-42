/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:19:33 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:20:06 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string	ftReplace(std::string haystack, std::string oldNeedle, std::string newNeedle)
{
    size_t found = haystack.find(oldNeedle);
    while (found != std::string::npos)
    {
        haystack.erase(found, oldNeedle.size());
        haystack.insert(found, newNeedle);
        found = haystack.find(oldNeedle, found + newNeedle.size());
    }
    return haystack;
}

void	sed(std::string fileName, std::string oldNeedle, std::string newNeedle)
{
	char			c;
	std::string		haystack;
	std::ifstream	input(fileName);
	std::ofstream	output(fileName + ".replace");

	while (input.get(c))
		haystack += c;
	haystack += "\0";
	std::cout<<haystack;
	output << ftReplace(haystack, oldNeedle, newNeedle);
	input.close();
	output.close();
}