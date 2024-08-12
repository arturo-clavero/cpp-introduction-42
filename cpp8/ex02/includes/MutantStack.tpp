/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 04:04:47 by artclave          #+#    #+#             */
/*   Updated: 2024/08/12 20:57:11 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//ORTHODOX
template <typename T>
MutantStack<T>::MutantStack(){
	std::cout<<BLUE<<"\t(MutantStack default constructor called)\n"<<RESET;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & other) : _stack(other.getStack()){
	std::cout<<BLUE<<"\t(MutantStack copy constructor called)\n"<<RESET;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	std::cout<<PURPLE<<"\t(MutantStack destructor called)\n"<<RESET;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const & other){
	std::cout<<BLUE<<"\t(MutantStack copy assignment operator called)\n"<<RESET;
	_stack = other.getStack();
}

//getters
template <typename T>
std::deque<T>	MutantStack<T>::getStack()const{
	return _stack;
}

//element access
template <typename T>
T		const &MutantStack<T>::top() const{
	return _stack.back();
}

//capacity:
template <typename T>
bool	MutantStack<T>::empty() const{
	return	_stack.empty();
}

template <typename T>
int		MutantStack<T>::size() const{
	return	_stack.size();
}

//modifiers:
template <typename T>
void	MutantStack<T>::push(T const element){
	_stack.push_back(element);
}

template <typename T>
void	MutantStack<T>::pop(){
	_stack.pop_back();
}

//spicy:
template <typename T>
typename std::deque<T>::const_iterator	MutantStack<T>::begin() const{
 	return _stack.begin();
}

template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::begin() {
 	return _stack.begin();
}

template <typename T>
typename std::deque<T>::const_iterator 	MutantStack<T>::end() const{
	return _stack.end();
}

template <typename T>
typename std::deque<T>::iterator 	MutantStack<T>::end() {
	return _stack.end();
}

template <typename T>
MutantStack<T>::operator std::stack<T, std::deque<T> >() {
	std::stack<T, std::deque<T> > newStack (_stack);
	std::cout<<BLUE<<"\t(conversion operator is called)\n"<<RESET;
	return newStack;
}

template <typename T>
MutantStack<T>::operator const std::stack<T, std::deque<T> >() const {
	std::stack<T, std::deque<T> > newStack (_stack);
	std::cout<<BLUE<<"\t(conversion operator is called)\n"<<RESET;
	return newStack;
}

template <typename T>
std::ostream	&operator<<(std::ostream & out, MutantStack<T> const & mut){
	typename std::deque<T>::const_iterator it = mut.begin();
	out<<"Stack :\n";
	for (; it != mut.end(); it++)
		out<<*it<<"\n";
	out<<"\n";
	return out;
}