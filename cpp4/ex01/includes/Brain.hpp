/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:41:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 18:42:33 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain{
	private :
		std::string	ideas[100];
	public :
	//ORTHODOX FORMAT
		Brain();
		Brain(Brain const &original);
		Brain	&operator=(Brain const &original);
		~Brain();
};

#endif