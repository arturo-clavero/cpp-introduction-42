/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:13:15 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 19:13:16 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public	:
	//MEMBER FTS
		void	makeSound()const;
	//ORTHODOX FORMAT
		WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat	&operator=(const WrongCat &original);
		virtual ~WrongCat();
};

#endif