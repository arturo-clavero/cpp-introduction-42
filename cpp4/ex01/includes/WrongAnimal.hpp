/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:12:27 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:31:29 by arturo           ###   ########.fr       */
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
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &original);
		WrongAnimal	&operator=(WrongAnimal const &original);
		virtual ~WrongAnimal();
};

#endif