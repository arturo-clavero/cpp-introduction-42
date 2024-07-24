/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:02 by arturo            #+#    #+#             */
/*   Updated: 2024/07/24 15:58:25 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	//		Our main function will NOT compile with the 3 Animals declared below...
	//		as we can no longer create instances of our base class since we made it abstract
	Animal	willNotCompile;
	Animal	alsoWillNotCompile("random");
	Animal *andAlsoWillNotCompile = new Dog();
	//Please comment out the above declarations and let-s see that we can still call animal constructors
	std::cout<<"\n\tInitialize cat\n";
	Cat oneCat;
	std::cout<<"\n\tInitialize dog\n";
	Dog	oneDog;
	std::cout<<"\n\tAutomatic destruction of both\n";
}
	