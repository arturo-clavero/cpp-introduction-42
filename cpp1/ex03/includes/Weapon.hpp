/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:57:33 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 16:04:01 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		const std::string	&getType(void);
		void	setType(std::string str);
		Weapon();
		Weapon(std::string str);
};

#endif 
