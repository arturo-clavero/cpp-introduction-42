/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:09:24 by arturo            #+#    #+#             */
/*   Updated: 2024/07/25 16:15:00 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected :
		std::string	type;
	public	:
		virtual void	makeSound()	const;
		std::string	getType() const;
	//ORTHODOX FORMAT
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &original);
		Animal	&operator=(const Animal &original);
		virtual ~Animal();
};

#endif