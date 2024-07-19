/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:46:03 by arturo            #+#    #+#             */
/*   Updated: 2024/07/20 01:25:38 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T>>

class	MutantStack : public std::stack<T, Container>{
	private:
		typedef T	value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;
		Container	container;
		
	public:
	typedef typename Container::iterator iterator;
		MutantStack(){
			std::cout<<"Default constructor called for mutantstack\n";
		}
		MutantStack(MutantStack const &original){
			std::cout<<"Copy constructor called\n";
			container = original.container;
		}
		MutantStack	&operator=(MutantStack const &original){
			std::cout<<"Copy assignment operator called for mutantstack\n";
			container = original.container;
			return *this;
		}
		~MutantStack(){
			std::cout<<"Destructor called for mutantstack\n";
		}
	//MEMBER FTS
		int	empty(){
			return (container.empty());
		}
		size_type	size(){
			return (container.size());
		}
		value_type	top(){
			return (container.back());
		}
		void	push(value_type value){
			container.push_back(value);
		}
		void	emplace(value_type value){
			container.emplace_back(value);
		}
		void	pop(){
			container.pop_back();
		}
		void	swap(MutantStack &other){
			container.swap(other);
		}
		iterator begin(){
			return container.begin();
		}
		iterator end(){
			return container.end();
		}
		operator std::stack<T, Container>() const {
        	return static_cast<std::stack<T, Container>>(*this);
    	}
};

#endif