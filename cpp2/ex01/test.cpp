/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:51:38 by arturo            #+#    #+#             */
/*   Updated: 2024/06/25 18:42:41 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed
{
	public:
		float	toFloat(void) const{
			//std::cout<<"toFLoat member function called\n";
			return (float)(num) / (1 << fractional_bits);
		}
		int	toInt(void) const{
			//std::cout<<"toInt member function called\n";
			return (num >> fractional_bits);
		}
		int	getRawBits(void)const{	
			//std::cout<<"getRawBits member function called\n";
			return (num);
		}
		void setRawBits(int const raw){
			num = raw;
			std::cout<<"setRawBits member function called\n";
		}
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
			//std::cout<<"orginal num "<<num<<"\n";
			this->num = (int)(num * (1 << fractional_bits));
			//std::cout<<"shifting bits is "<<this->num<<"\n";
			//std::cout<<"reverse is : "<<  (float)(this->num) / (1 << fractional_bits)<<"\n";
		}
		Fixed(Fixed const &original){
			std::cout<<"Copy constructor called\n";
			num = original.getRawBits();
		}
		Fixed	&operator=(Fixed const &original){
			std::cout<<"Copy assignment operator called\n";
			num = original.getRawBits();
			return *this;
		}
		~Fixed(){
			std::cout<<"Destructor called\n";
		}
	
	private:
		int					num{};
		static const int	fractional_bits{8};
};

std::ostream	&operator<<(std::ostream &cout_param, Fixed const &original){
	cout_param<<original.toFloat();
	return cout_param;		
}

int	main( void ) {
Fixed 		a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );
std::cout<<"\n\n";
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}