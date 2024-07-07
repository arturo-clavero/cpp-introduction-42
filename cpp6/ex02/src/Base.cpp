/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:34:23 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 01:59:52 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout<<"Base destructor called\n";
}

Base *Base::generate(void)
{
	std::srand(std::time(0));
	int	randomNum = std::rand() % 3;
	std::cout<<"random  num is "<<randomNum<<"\n";
	Base *result;
	if (randomNum == 0)
		result = new A;
	if (randomNum == 1)
		result = new B;
	if (randomNum == 2)
		result = new C;
	return (result);
};

void Base::identify(Base* p){
	Base	*attempt;

	attempt = dynamic_cast<A *>(p);
	if (attempt)
		std::cout<<"Type A\n";
	attempt = dynamic_cast<B *>(p);
	if (attempt)
		std::cout<<"Type B\n";
	attempt = dynamic_cast<C *>(p);
	if (attempt)
		std::cout<<"Type C\n";	
}


void Base::identify(Base& p){
	A	attemptA;
	B	attemptB;
	C	attemptC;

	try {
		attemptA = dynamic_cast<A&>(p);
		std::cout<<"Type A\n";
		return ;
	}catch(...){}
	try {
		attemptB = dynamic_cast<B&>(p);
		std::cout<<"Type B\n";
		return ;
	}catch(...){}
	try {
		attemptC = dynamic_cast<C&>(p);
		std::cout<<"Type C\n";
		return ;
	}catch(...){}
}