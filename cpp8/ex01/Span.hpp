/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:33:52 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 20:16:12 by arturo           ###   ########.fr       */
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
		Span(const Span &original);
		Span	&operator=(const Span &original);
		~Span();
	//MEMBER FT:
	void	addNumber(int num);
	int	longestSpan();
	int	shortestSpan();
	void	addArrayOfNums(int *numArray, int totalNums);
	//TEST FT:
	void	getSize(std::string name = "Span");
	void	print(std::string name = "Span");
	
};


#endif