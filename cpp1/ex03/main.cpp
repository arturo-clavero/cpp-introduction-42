/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:35:39 by arturo            #+#    #+#             */
/*   Updated: 2024/06/01 20:44:39 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		const std::string	&getType(void)
		{
			return (type);
		}
		void	setType(std::string str)
		{
			type = str;
		}
		Weapon()
        {
            type = "Undefined";
        }
		Weapon(std::string str)
		{
			type = str;
		}
};

class HumanA
{
	public:
		std::string	name;
		Weapon		&weapon;
		HumanA(std::string str_name, Weapon &local_weapon) : name(str_name), weapon(local_weapon)
		{}
		void	attack(void)
		{
			std::cout<<name<<" attacks with their "<<weapon.getType()<<"\n";
		}
};

class HumanB
{
	public:
		std::string	name;
		Weapon		*weapon;
		HumanB(std::string str_name) : name(str_name), weapon(nullptr)
		{}
		void	attack(void)
		{
			std::cout<<name<<" attacks with their "<<weapon->getType()<<"\n";
		}
		void	setWeapon(Weapon &local_weapon)
		{
			weapon = &local_weapon;
		}
};

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}

{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}