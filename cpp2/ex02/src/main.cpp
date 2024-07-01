/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:24:43 by arturo            #+#    #+#             */
/*   Updated: 2024/07/01 16:46:10 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	comparison_test(Fixed &a, Fixed &b)
{
	std::cout<<"\n///////////////////////////////////\nTESTING COMPARISON OPERATORS:\n\n";
	std::cout<<a<<" > "<<b<<"?";
	if (a > b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<a<<" < "<<b<<"?";
	if (a < b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<a<<" >= "<<b<<"?";
	if (a >= b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<a<<" <= "<<b<<"?";
	if (a <= b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<a<<" == "<<b<<"?";
	if (a == b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<a<<" != "<<b<<"?";
	if (a != b)
		std::cout<<"\tYes"<<std::endl;
	else
		std::cout<<"\tNo"<<std::endl;
	std::cout<<std::endl;
}

void	arithmetic_test(Fixed &a, Fixed &b)
{
	std::cout<<"\n///////////////////////////////////\nTESTING ARITHMETIC OPERATORS:\n\n";
	Fixed c;
	std::cout<<"c = "<<c<<"\n";
	std::cout<<"c = a+b -> "<<a<<"+"<<b<<" ->\n";
	c = a + b;
	std::cout<<"c = "<<c<<"\n";
	c = 0;
	std::cout<<"\n(c = "<<c<<")\n";
	std::cout<<"c = a-b -> "<<a<<"-"<<b<<" ->\n";	
	c = a - b;
	std::cout<<"c = "<<c<<"\n";
	c = 0;
	std::cout<<"\n(c = "<<c<<")\n";
	std::cout<<"c = a*b -> "<<a<<"*"<<b<<" ->\n";
	c = a * b;
	std::cout<<"c = "<<c<<"\n";
	c = 0;
	std::cout<<"\n(c = "<<c<<")\n";
	std::cout<<"c = a/b -> "<<a<<"/"<<b<<" ->\n";
	c = a / b;
	std::cout<<"c = "<<c<<"\n\n";
}

void	increment_decrement_test(Fixed &a)
{
	std::cout<<"\n///////////////////////////////////\nTESTING INCREMENENT/DECREMENT OPERATORS:\n\n";
	std::cout<<"a = "<<a<<"\n";
	std::cout<<"a++\n";
	a++;
	std::cout<<"a = "<<a<<"\n";
	std::cout<<"++a\n";
	++a;
	std::cout<<"a = "<<a<<"\n";
	std::cout<<"a--\n";
	a--;
	std::cout<<"a = "<<a<<"\n";
	std::cout<<"--a\n";
	--a;
	std::cout<<"a = "<<a<<"\n";
}

void	min_max_test(Fixed &a, Fixed &b)
{
	std::cout<<"\n///////////////////////////////////\nTESTING MIN MAX:\n\n";
	std::cout<<"a="<<a;
	std::cout<<", b="<<b<<"\n";
	std::cout<<"min: "<<Fixed::min(a, b)<<"\n";
	std::cout<<"max: "<<Fixed::max(a, b)<<"\n";
}	

void	min_max_const_test(Fixed const &a, Fixed const &b)
{
	std::cout<<"\n///////////////////////////////////\nTESTING CONST MIN MAX:\n\n";
	std::cout<<"a="<<a;
	std::cout<<", b="<<b<<"\n";
	std::cout<<"min: "<<Fixed::min(a, b)<<"\n";
	std::cout<<"max: "<<Fixed::max(a, b)<<"\n";
	return ;
}

void	subject_test(void)
{
	std::cout<<"\n///////////////////////////////////\nTESTING SUBJECT MAIN:\n\n";
	Fixed	a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}


int	main( void ) {
Fixed	a(3.19f);
Fixed	b(3.2f);

comparison_test(a, b);
a = 5;
b = 2;
arithmetic_test(a, b);
a = -0.678F;
increment_decrement_test(a);
min_max_test(a, b);
min_max_const_test(a, b);
subject_test();
std::cout<<"\n\nTESTING ENDED!\nGood job! \nNow everything will be DESTRUCTED!\nhehehehehe\n \\ / \n o 0\n ~~\n";
return 0;
}