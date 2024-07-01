/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:10:20 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:50:08 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	private:
		Brain *localBrain;
	public	:
	//MEMBER FTS
		void	makeSound()const;
	//ORTHODOX FORMAT
		Cat();
		Cat(Cat const &original);
		Cat	&operator=(Cat const &original);
		virtual ~Cat();
};

# endif