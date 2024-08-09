/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:46:03 by arturo            #+#    #+#             */
/*   Updated: 2024/08/09 04:12:48 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >

class	MutantStack : public std::stack<T, Container>{
	private:
		typedef T	value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;
		Container	container;
		
	public:
	typedef typename Container::iterator iterator;
		MutantStack();
		MutantStack(MutantStack const &original);
		MutantStack	&operator=(MutantStack const &original);
		~MutantStack();
	//MEMBER FTS
		int	empty() const;
		size_type	size() const;
		value_type	top() const;
		void	push(value_type const & value);
		void	emplace(value_type const & value);
		void	pop();
		void	swap(MutantStack const &other);
		iterator begin();
		iterator end();
		operator std::stack<T, Container>() const;
};

#include "MutantStack.tpp"

#endif