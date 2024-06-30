/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:17:51 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 19:13:01 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1;

	zombie1 = newZombie("Heinz");
	zombie1->announce();
	delete zombie1;
	randomChump("Ratz");
}