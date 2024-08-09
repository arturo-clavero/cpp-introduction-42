/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:16:23 by arturo            #+#    #+#             */
/*   Updated: 2024/08/09 03:45:46 by artclave         ###   ########.fr       */
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
void	Span::addNumber(int const num){
	if (array.size() < N)
		array.push_back(num);
	else
		throw std::out_of_range("Could not add element, array is already full\n");
}

int	Span::shortestSpan() const{
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

int	Span::longestSpan() const{
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

void	Span::addArrayOfNums(int const *numArray, int const totalNums){
    std::copy(numArray, numArray + totalNums, std::back_inserter(array));
}

//TEST FT
void	Span::getSize(std::string const &name) const{
	std::cout<<"Capacity.() of "<<name<<" is "<<array.capacity()<<"\n";
}

std::vector<int>	Span::getArray()const{
	return array;
}

std::ostream	&operator<<(std::ostream & out, Span const & span){
	out<<"Elements of span:\n";
	std::vector<int> array = span.getArray();
	if (array.empty())
		throw std::out_of_range("Empty array\n");
	for (size_t i = 0; i < array.size(); i++)
		out<<array[i]<<" ";
	out<<"\n";
	return out;
}