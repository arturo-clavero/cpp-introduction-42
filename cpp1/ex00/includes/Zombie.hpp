/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:53 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:13:10 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		Zombie();
		Zombie(std::string str);
		~Zombie(void);
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif