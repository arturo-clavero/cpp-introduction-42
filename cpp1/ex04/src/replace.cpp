/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:26:35 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 02:26:37 by arturo           ###   ########.fr       */
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

void	sed(const std::string &fileName, std::string oldNeedle, std::string newNeedle)
{
	char			c;
	std::string		haystack;
	std::ifstream	input(fileName.c_str());

	if (!input)
	{
		std::cerr<<"Error: Can not open input file '"<<fileName<<"'\n";
		return;
	}
	const std::string	outputFileName = fileName + ".replace";
	std::ofstream	output(outputFileName.c_str());
	if (!output)
	{
		std::cerr<<"Error: Can not open output file '"<<fileName<<"'\n";
		input.close();
		return;
	}
	while (input.get(c))
		haystack += c;
	haystack += "\0";
	if (!haystack.empty())
		output << ftReplace(haystack, oldNeedle, newNeedle);
	else
		std::cerr<<"Error: Input file '"<<fileName<<"' is empty\n";
	input.close();
	output.close();
}