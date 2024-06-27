/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:49:20 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 15:04:22 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	PhoneBook::print_all(int n) {
	if (n < 0)
	{
		std::cout<<"No contacts\n\n";
		return (false);
	}
	contact[0].format("Index");
	contact[0].format("First Name");
	contact[0].format("Last Name");
	contact[0].format("Nickname");
	std::cout<<"\n";
	for (int i = 0; i <= n; i++)
		contact[i].print_basic(i);
	return (true);
}

void	PhoneBook::print_index(int n) {
	contact[n].print_full();
}
void	PhoneBook::delete_old_contact(void) {
	for (int i = 0; i < 7; i++)
		contact[i] = contact[i + 1];
}