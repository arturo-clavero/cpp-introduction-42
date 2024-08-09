/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 04:04:47 by artclave          #+#    #+#             */
/*   Updated: 2024/08/09 04:14:47 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

typedef typename Container::iterator iterator;

MutantStack::MutantStack(){
	std::cout<<"Default constructor called for mutantstack\n";
}

MutantStack::MutantStack(MutantStack const &original){
	std::cout<<"Copy constructor called\n";
	container = original.container;
}

MutantStack	&MutantStack::operator=(MutantStack const &original){
	std::cout<<"Copy assignment operator called for mutantstack\n";
	container = original.container;
	return *this;
}

MutantStack::~MutantStack(){
	std::cout<<"Destructor called for mutantstack\n";
}

//MEMBER FTS
int	MutantStack::empty() const{
	return (container.empty());
}

size_type	MutantStack::size() const{
	return (container.size());
}

value_type	MutantStack::top() const{
	return (container.back());
}

void	MutantStack::push(value_type const & value){
	container.push_back(value);
}

void	MutantStack::emplace(value_type const & value){
	container.emplace_back(value);
}

void	MutantStack::pop() {
	container.pop_back();
}

template <class T, class Container >
void	MutantStack<T>::swap(MutantStack<T> const &other){
	container.swap(other);
}

iterator MutantStack::begin() {
	return container.begin();
}

iterator MutantStack::end() {
	return container.end();
}

operator std::stack<T, Container>() const {
    return static_cast<std::stack<T, Container> >(*this);
}