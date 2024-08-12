/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:16:23 by arturo            #+#    #+#             */
/*   Updated: 2024/08/11 00:46:52 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(){
	std::cout<<"Default constructor called for class Span\n";
}

Span::Span(unsigned int N){
	std::cout<<"Constructor called for class Span with max N of "<<N<<"\n";
	_N = N;
	_array.reserve(_N);
}

Span::Span(const Span &original){
	std::cout<<"Copy constructor called for class Span\n";
	_array.reserve(original._N);
	_array = original._array;
	_N = original._N;
}

Span	&Span::operator=(const Span &original){
	std::cout<<"Copy assignment operator called for class Span\n";
	_array = original._array;
	_N = original._N;
	return *this;
}

Span::~Span(){
	std::cout<<"Destructor called for class Span\n";
}

//MEMBER FT:
void	Span::addNumber(int const num){
	if (_array.size() < _N)
		_array.push_back(num);
	else
		throw std::out_of_range("Could not add element, array is already full\n");
}

int	Span::shortestSpan() const{
	if (_array.empty())
		throw std::out_of_range("Array is empty\n");
	if (_array.size() == 1)
		throw std::out_of_range("Array only has 1 element\n");
	int min = std::numeric_limits<int>::max();
	int	value;
	for (int i = 0; i + 1 < static_cast<int>(_array.size()); i++){
		value = abs(_array[i] - _array[i + 1]);
		if (value < min)
			min = value;
	}
	return min;
}

int	Span::longestSpan() const{
	if (_array.empty())
		throw std::out_of_range("Array is empty\n");
	if (_array.size() == 1)
		throw std::out_of_range("Array only has 1 element\n");
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < static_cast<int>(_array.size()); i++){
		if (_array[i] < min)
			min = _array[i];
		if (_array[i] > max)
			max = _array[i];
	}
	return abs(min - max);
}

std::vector<int>::iterator	Span::begin(){
	return _array.begin();
}
std::vector<int>::iterator	Span::end(){
	return _array.end();
}

void	Span::addManyNums(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    for (; begin != end; begin++)
		this->addNumber(*begin);
}

void	Span::getSize(std::string const &name) const{
	std::cout<<"Capacity.() of "<<name<<" is "<<_array.capacity()<<"\n";
}

std::vector<int>	Span::getArray()const{
	return _array;
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