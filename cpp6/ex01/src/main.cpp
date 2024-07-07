/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:10:07 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 01:23:30 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data original;

	original.age = 90;
	original.name = "Stuart";
	uintptr_t convert = Serializer::serialize(&original);
	Data *result = Serializer::deserialize(convert);
	std::cout<<"Name of original: "<<original.name<<"\n";
	std::cout<<"Name of result: "<<result->name<<"\n";
	std::cout<<"Age of original: "<<original.age<<"\n";
	std::cout<<"Age of result: "<<result->age<<"\n";
}