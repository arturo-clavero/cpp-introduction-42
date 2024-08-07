/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:32:57 by arturo            #+#    #+#             */
/*   Updated: 2024/07/28 15:26:00 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	
	std::string	haystack = av[1];
	std::cout<<av[1]<<"\n";
	std::string	oldNeedle = av[2];
	std::string newNeedle = av[3];
	std::ofstream	newFile("rest.txt");
	newFile<<haystack;
	newFile.close();
	sed("rest.txt", oldNeedle, newNeedle);
}