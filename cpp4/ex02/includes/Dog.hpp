/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:11:24 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:46:41 by arturo           ###   ########.fr       */
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
		Dog(Dog const &original);
		Dog	&operator=(Dog const &original);
		virtual ~Dog();
};

#endif