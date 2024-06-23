/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:17:51 by arturo            #+#    #+#             */
/*   Updated: 2024/06/01 18:44:10 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		void announce( void )
		{
			std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
		}
		Zombie(std::string str)
		{
			name = str;
		}
		~Zombie(void)
		{
			std::cout<<"Destroying zombie "<<name<<"\n";
		}
};

Zombie* new_zombie( std::string name )
{
	Zombie	*local_zombie = new Zombie(name);
	if (!local_zombie)
		return (nullptr);
	return (local_zombie);
}

void	randomChump( std::string name )
{
	Zombie	local_zombie(name);
	local_zombie.announce();
}

int	main(void)
{
	Zombie	*zombie1;

	zombie1 = new_zombie("Heinz");
	zombie1->announce();
	delete zombie1;
	randomChump("Ratz");
}