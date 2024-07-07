/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:40:39 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 02:15:42 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	testingPointers(){
	std::cout<<"TESTING POINTERS\n\n";
	std::cout<<"creating type A...\n";
	Base *base1 = new A;
	std::cout<<"Identifying type...-> ";
	base1->identify(base1);
	std::cout<<"creating type B...\n";
	Base *base2 = new B;
	std::cout<<"Identifying type...-> ";
	base2->identify(base2);
	std::cout<<"creating type C...\n";
	Base *base3 = new C;
	std::cout<<"Identifying type...-> ";
	base3->identify(base3);
	delete base1;
	delete base2;
	delete base3;
}

void	testingRef(){
	std::cout<<"TESTING REF\n\n";
	Base	base;
	std::cout<<"creating type A...\n";
	A	a;
	std::cout<<"Identifying type...-> ";
	base.identify(a);
	std::cout<<"creating type B...\n";
	B	b;
	std::cout<<"Identifying type...-> ";
	base.identify(b);
	std::cout<<"creating type C...\n";
	C	c;
	std::cout<<"Identifying type...-> ";
	base.identify(c);
	
}

void	testingRandInit(){
	std::cout<<"Testing random init:\n\n";
	Base base;
	Base *randomPtr = base.generate();
	std::cout<<"Identifying pointer\n";
	base.identify(randomPtr);
	std::cout<<"Identifying reference\n";
	//base.identify(*randomPtr);
}

int	main(void){
	testingRandInit();
	testingPointers();
	testingRef();
}