/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:10:20 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:30:32 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {
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