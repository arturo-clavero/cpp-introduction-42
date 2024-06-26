/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:41:55 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 18:44:33 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>

class	Fixed
{
	public:
	//Member functions
		float	toFloat(void) const{
			return (float)(num) / (1 << fractional_bits);
		}
		int	toInt(void) const{
			return (num >> fractional_bits);
		}
		int	getRawBits(void)const{	
			return (num);
		}
		void setRawBits(int const raw){
			num = raw;
		}
		static Fixed	&min(Fixed &a, Fixed &b) { //Making these static so we dont need the instance of a class to call them! so we can say Fixed::min(a, b), instead of a.min(a, b)
			if (a < b)
				return (a);
			return (b);
		}
		static Fixed const	&min(Fixed const &a, Fixed const &b) {
			if (a < b)
				return (a);
			return (b);
		}
		static Fixed	&max(Fixed &a, Fixed &b) {
			if (a > b)
				return (a);
			return (b);
		}
		static Fixed const	&max(Fixed const &a, Fixed const &b) {
			if (a > b)
				return (a);
			return (b);
		}
	//Constructors
		Fixed(){
			num = 0;
			std::cout<<"Default constructor called\n";
		}
		Fixed(int const num){
			std::cout<<"Int constructor called\n";
			this->num = num << fractional_bits;
		}
		Fixed(float const num){
			std::cout<<"Float constructor called\n";
			this->num = (int)(num * (1 << fractional_bits));
		}
		Fixed(Fixed const &original){
			std::cout<<"Copy constructor called\n";
			num = original.getRawBits();
		}
	//Destructor
		~Fixed(){
			std::cout<<"Destructor called\n";
		}
	//Copy assignment operator
		Fixed	&operator=(Fixed const &original){
			std::cout<<"Copy assignment operator called\n";
			num = original.getRawBits();
			return *this;
		}
	//Comparison operators
		bool	operator>(Fixed const &compare) const{		
			if (toFloat() > compare.toFloat())
				return	true;
			return	false;
		}
		bool	operator<(Fixed const &compare) const{
			if (toFloat() < compare.toFloat())
				return	true;
			return	false;
		}
		bool	operator==(Fixed const &compare) const{
			if ((toFloat() == compare.toFloat()))
				return	true;
			return	false;
		}
		bool	operator>=(Fixed const &compare) const{
			if (*this == compare || *this > compare)
				return	true;
			return	false;
		}
		bool	operator<=(Fixed const &compare) const{
			if (*this == compare || *this < compare)
				return	true;
			return	false;
		}
		bool	operator!=(Fixed const &compare) const{
			if (*this == compare)
				return false;
			return	true;
		}
	//Increment decrement operator
		Fixed	&operator++() { //returning obj by reference so that << ++a can work aka we can chain operations if we return the obj
        	num += 1;// << fractional_bits;
			return *this;
		}
		Fixed	operator++(int) {
			Fixed	temp = *this;
        	num += 1;// << fractional_bits;
			return temp;
		}
		Fixed	&operator--() {
        	num -= 1;// << fractional_bits;
			return *this;
		}
		Fixed	operator--(int) {
			Fixed	temp = *this;
        	num -= 1;// << fractional_bits;
			return temp;
		}
	//Arithmetic operators
		Fixed 	operator+(Fixed const &arg) {
			Fixed	result(toFloat() + arg.toFloat());
			return	(result); //have to return by VALUE because otherwise the obj is out of local scope....
		}
		Fixed	operator-(Fixed const &arg) {
			Fixed	result(toFloat() - arg.toFloat());
			return	(result);
		}
		Fixed	operator*(Fixed const &arg) {
			Fixed	result(toFloat() * arg.toFloat());
			return	(result);
		}
		Fixed	operator/(Fixed const &arg) {
			Fixed	result(toFloat() / arg.toFloat());
			return	(result);
		}
	private:
		int					num{};
		static const int	fractional_bits{8};
};

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original){
	cout_param<<original.toFloat();
	return cout_param;		
}


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
	Fixed c{};
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