/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:11:24 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 18:03:44 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
	public	:
	//MEMBER FTS
		void	makeSound()	const;
	//ORTHODOX FORMAT
		Dog();
		Dog(const Dog &original);
		Dog	&operator=(const Dog &original);
		virtual ~Dog();
};

#endif