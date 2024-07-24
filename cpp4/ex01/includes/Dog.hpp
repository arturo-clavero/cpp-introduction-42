/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:11:24 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 19:12:46 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private:
		Brain *localBrain;
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