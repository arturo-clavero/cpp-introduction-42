/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:16:23 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 20:15:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(){
	std::cout<<"Default constructor called for class Span\n";
}

Span::Span(unsigned int N){
	std::cout<<"Constructor called for class Span with max N of "<<N<<"\n";
	this->N = N;
	array.reserve(N);
}

Span::Span(const Span &original){
	std::cout<<"Copy constructor called for class Span\n";
	array.reserve(original.N);
	array = original.array;
	N = original.N;
}

Span	&Span::operator=(const Span &original){
	std::cout<<"Copy assignment operator called for class Span\n";
	array = original.array;
	N = original.N;
	return *this;
}

Span::~Span(){
	std::cout<<"Destructor called for class Span\n";
}

//MEMBER FT:
void	Span::addNumber(int num){
	if (array.size() < N)
		array.push_back(num);
	else
		throw std::out_of_range("Could not add element, array is already full\n");
}

int	Span::shortestSpan(){
	if (array.empty())
		throw std::out_of_range("Array is empty\n");
	if (array.size() == 1)
		throw std::out_of_range("Array only has 1 element\n");
	int min = std::numeric_limits<int>::max();
	int	value;
	for (int i = 0; i + 1 < static_cast<int>(array.size()); i++){
		value = abs(array[i] - array[i + 1]);
		if (value < min)
			min = value;
	}
	return min;
}

int	Span::longestSpan(){
	if (array.empty())
		throw std::out_of_range("Array is empty\n");
	if (array.size() == 1)
		throw std::out_of_range("Array only has 1 element\n");
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < static_cast<int>(array.size()); i++){
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	return abs(min - max);
}

void	Span::addArrayOfNums(int *numArray, int totalNums){
    std::copy(numArray, numArray + totalNums, std::back_inserter(array));
}

//TEST FT
void	Span::getSize(std::string name){
	std::cout<<"Capacity.() of "<<name<<" is "<<array.capacity()<<"\n";
}

void	Span::print(std::string name){
	std::cout<<"Elements of "<<name<<"\n";
	if (array.empty())
		throw std::out_of_range("Empty array\n");
	for (size_t i = 0; i < array.size(); i++)
		std::cout<<array[i]<<" ";
	std::cout<<"\n";
}