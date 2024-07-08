/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:48:47 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 18:56:03 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
template<typename T>

class Array{
	private:
		T *array;
		int	len;
	
	public:
		Array(){
			std::cout<<"Default constructor called for class 'Array'\n";
			len = 0;
			array = new T[len];
		}
		Array(unsigned int n){
			std::cout<<"Constructor called for class 'Array' with size "<<n<<"\n";
			len = n;
			array = new T[len];
		}
		Array(Array &original){
			std::cout<<"Copy constructor called for class 'Array'\n";
			len = original.size();
			array = new T[len];
			for (int i = 0; i < len; i++)
				array[i] = original.array[i];
		}
		Array	&operator=(Array &original){
			std::cout<<"Copy assignment operator called for class 'Array'\n";
			delete[] array;
			len = original.size();
			array = new T[len];
			for (int i = 0; i < len; i++)
				array[i] = original.array[i];
			return *this;
		}
		T&	operator[](int index) {
        	if (index >= len)
            	throw std::out_of_range("Error: array out of bounds...");
        	return array[index];
		}
		int	size(){
			return len;
		}
		~Array(){
			std::cout<<"Destructor for class 'Array' called\n";
			delete[] array;
		}
};

#endif