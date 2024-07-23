/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:12:27 by arturo            #+#    #+#             */
/*   Updated: 2024/07/23 18:04:13 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected :
		std::string	type;
	public	:
		void	makeSound()	const;
		std::string	getType() const;
	//ORTHODOX FORMAT
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal	&operator=(const WrongAnimal &original);
		virtual ~WrongAnimal();
};

#endif