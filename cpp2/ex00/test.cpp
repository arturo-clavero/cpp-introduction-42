/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:19:24 by arturo            #+#    #+#             */
/*   Updated: 2024/06/24 23:49:32 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed
{
	public:
		int	getRawBits(void)const
		{	
			std::cout<<"getRawBits member function called\n";
			return (num);
		}
		void setRawBits(int const raw)
		{
			num = raw;
			std::cout<<"setRawBits member function called\n";
		}
		Fixed()
		{
			num = 0;
			std::cout<<"Default constructor called\n";
		}
		Fixed(Fixed &original)
		{
			std::cout<<"Copy constructor called\n";
			num = original.getRawBits();
		}
		Fixed	&operator=(Fixed &original)
		{
			std::cout<<"Copy assignment operator called\n";
			num = original.getRawBits();
			return *this;
		}
		~Fixed()
		{
			std::cout<<"Destructor called\n";
		}
	
	private:
		int					num{};
		static const int	fractional_bits{8};
};

int	main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
std::cout<<"\nHEEY\n\n";
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}