/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:52:53 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 18:59:13 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout<<"Serializer default constructor called\n";
}

Serializer::Serializer(const Serializer &original){
	(void)original;
	std::cout<<"Serializer copy constructor called\n";
}

Serializer	&Serializer::operator=(const Serializer &original){
	(void)original;
	std::cout<<"Serializer copy assignment operator called\n";
	return *this;
}

Serializer::~Serializer(){
	std::cout<<"Serializer destructor called\n";
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *result = reinterpret_cast<Data *>(raw);
	return result;
}