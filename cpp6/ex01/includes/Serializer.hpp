/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:53:07 by arturo            #+#    #+#             */
/*   Updated: 2024/08/08 02:52:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct	Data{
	std::string	name;
	int	age;
};

class Serializer{
	private :
		Serializer();
		Serializer(const Serializer &original);
		Serializer	&operator=(const Serializer &original);
		~Serializer();
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif