/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:46:03 by arturo            #+#    #+#             */
/*   Updated: 2024/08/12 20:55:22 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

#define PURPLE "\033[38;2;0;0;205m" // Medium Blue
#define BLUE "\033[38;2;135;206;250m" // Lighter Blue
#define RESET "\033[0m"

template <typename T>
class MutantStack{
	private:
		std::deque<T>	_stack;
	public:
	//MEMBER TYPES:
		typedef typename std::deque<T>::value_type value_type;
		typedef typename std::deque<T>::size_type size_type;
		typedef typename std::deque<T>::reference reference;
		typedef typename std::deque<T>::const_reference const_reference;
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

	//MEMBER FTS:
		MutantStack();
		MutantStack(MutantStack<T> const & og);
		~MutantStack();
		MutantStack	&operator=(MutantStack<T> const & og);
		//element access:
			T		const &top() const;
		//capacity:
			bool	empty() const;
			int		size() const;
		//modifiers:
			void	push(T const element);
			void	pop();
		//spicy:
		    iterator begin();
			iterator end();
			const_iterator begin() const;
			const_iterator end() const;
		//getters
			std::deque<T>	getStack()const;
		//conversion operator
			operator std::stack<T, std::deque<T> >();
			operator const std::stack<T, std::deque<T> >() const;
};

template <typename T>
std::ostream	&operator<<(std::ostream & out, MutantStack<T> const & mut);

#include "MutantStack.tpp"

#endif