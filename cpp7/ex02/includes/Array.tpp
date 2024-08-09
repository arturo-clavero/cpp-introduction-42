/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:23:15 by artclave          #+#    #+#             */
/*   Updated: 2024/08/09 22:10:13 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(){
	std::cout<<"Default constructor called for class 'Array'\n";
	len = 0;
	array = new T[len];
}

template<typename T>
Array<T>::Array(unsigned int const n){
	std::cout<<"Constructor called for class 'Array' with size "<<n<<"\n";
	len = n;
	array = new T[len];
}

template<typename T>
Array<T>::Array(const Array &original){
	std::cout<<"Copy constructor called for class 'Array'\n";
	len = original.size();
	array = new T[len];
	for (int i = 0; i < len; i++)
		array[i] = original.array[i];
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &original){
	std::cout<<"Copy assignment operator called for class 'Array'\n";
	if (this != &original) {
		delete[] array;
		len = original.size();
		array = new T[len];
		for (int i = 0; i < len; i++)
			array[i] = original.array[i];
	}
	return *this;
}

template<typename T>
T&		Array<T>::operator[](int index) const{
    if (index >= len)
        throw std::out_of_range("Error: array out of bounds...");
    return array[index];
}

template<typename T>
int	Array<T>::size()const{
	return len;
}

template<typename T>
Array<T>::~Array(){
	std::cout<<"Destructor for class 'Array' called\n";
	delete[] array;
}