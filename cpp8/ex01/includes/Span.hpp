/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:33:52 by arturo            #+#    #+#             */
/*   Updated: 2024/08/11 00:48:16 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span{
	private:
		unsigned int 		_N;
		std::vector<int> 	_array;
	public:
	//ORTHODOX:
		Span();
		Span(unsigned int N);
		Span(Span const &original);
		Span	&operator=(Span const &original);
		~Span();
	//MEMBER FT:
		int		longestSpan() const;
		int		shortestSpan() const;
		void	addNumber(int const num);
		void	addManyNums(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	//GETTERS:
		void				getSize(std::string const & name = "Span") const;
		std::vector<int>	getArray()const;
	//ITERATORS
		std::vector<int>::iterator	begin();
		std::vector<int>::iterator	end();
};

std::ostream	&operator<<(std::ostream & out, Span const & span);


#endif