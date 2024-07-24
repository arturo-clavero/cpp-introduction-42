/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:41:19 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 19:14:00 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//ORTHODOX FORMAT
Brain::Brain(){
	std::cout<<"Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &original){
	std::cout<<"Brain copy constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = original.ideas[i];
}

Brain	&Brain::operator=(const Brain &original){
	std::cout<<"Brain copy assignment operator called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = original.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout<<"Brain destructor called\n";
}