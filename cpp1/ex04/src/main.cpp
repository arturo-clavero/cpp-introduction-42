/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:32:57 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 20:30:00 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(void)
{
	std::string	haystack = "this is abc and abc,\n after abc...\n";
	std::string	oldNeedle = "a";
	std::string newNeedle = "12345678";
	std::ofstream	newFile("rest.txt");
	newFile<<haystack;
	newFile.close();
	sed("rest.txt", oldNeedle, newNeedle);
}