/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:57:51 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 05:12:18 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <stdlib.h>

#define RESET "\033[0m"
#define BLUE "\033[96m"
#define GREEN "\033[32m"
#define RED "\033[31m"

class	RPN{
	private:
		std::string	const _input;
		std::stack<int> _stack;
		int const		_mode;
	//unused orthodox:
		RPN	&operator=(RPN const & other);
	//private ft helpers:
		static bool 	isValidChar(char c, const std::string &haystack);
		void	process_number(int *i);
		void	process_operand(char const operand);
		void	error(std::string msg) const;

	public:
	//usable orthodox:
		RPN(std::string const & str, int mode);
		RPN(RPN const & other);
		~RPN();
	//other :
		int	solve() ;
		std::string	getInput() const;
		int			getMode() const;
};

# endif