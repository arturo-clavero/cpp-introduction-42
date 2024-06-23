/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:17:51 by arturo            #+#    #+#             */
/*   Updated: 2024/06/01 19:14:19 by arturo           ###   ########.fr       */
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
		void	set_name(std::string str)
		{
			name = str;
		}
		~Zombie(void)
		{
			std::cout<<"Destroying zombie "<<name<<"\n";
		}
};

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*local_zombies = new Zombie[N];
	if (!local_zombies)
		return (nullptr);
	for (int i = 0; i < N; i++)
		local_zombies[i].set_name(name);
	return (local_zombies);
}

int	main(void)
{
	int	total = 4;
	Zombie	*local_zombies = zombieHorde(total, "rand guy");
	for (int i = 0; i < total; i++)
		local_zombies[i].announce();
	delete[] local_zombies;
}