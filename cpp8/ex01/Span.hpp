/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:33:52 by arturo            #+#    #+#             */
/*   Updated: 2024/08/09 03:44:42 by artclave         ###   ########.fr       */
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
		unsigned int N;
		std::vector<int> array;
	public:
	//ORTHODOX:
		Span();
		Span(unsigned int N);
		Span(Span const &original);
		Span	&operator=(Span const &original);
		~Span();
	//MEMBER FT:
		void	addNumber(int const num);
		int		longestSpan() const;
		int		shortestSpan() const;
		void	addArrayOfNums(int const *numArray, int const totalNums);
	//TEST FT:
		void	getSize(std::string const & name = "Span") const;
		std::vector<int>	getArray()const;
};

std::ostream	&operator<<(std::ostream & out, Span const & span);


#endif