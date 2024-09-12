/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:42:53 by artclave          #+#    #+#             */
/*   Updated: 2024/09/12 16:34:33 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "RPN.hpp"
#include <string>
#include <sstream>
#include <algorithm>

bool	valid_char(char c, std::string haystack){
	if (std::find(haystack.begin(), haystack.end(), c) == haystack.end())
	{
	std::cerr<<"Error: invalid char-> '"<<c<<"'\n";
		return true;
	}
	return false;
}

bool	check_sign(std::string str){
	std::string haystack = "+-";
	std::string::iterator next, prev;
	for (std::string::iterator it = str.begin(); it != str.end(); it++){
		if (std::find(haystack.begin(), haystack.end(), *it) != haystack.end())
		{
			prev = it - 1;
			next = it + 1;
			if ((*prev != ' ') || (*next != ' ' && next != str.end()))
				return false;
		}
	}
	return true;
}

RPN::RPN(std::string const &str) : _input(str){
	std::string allowed = "0123456789 +*-/";
	std::string operand = "+*-/";
    if ((std::find_if(_input.begin(), _input.end(), std::bind2nd(std::ptr_fun(valid_char), allowed)) != _input.end())
		|| !check_sign(str))
		error("Invalid expression: only digits, operands(separated by space) and spaces allowed\n");
}

RPN::RPN(RPN const & other) : _input(other.getInput()){};

RPN::~RPN(){};

std::string RPN::getInput() const{
	return _input;
}

int RPN::solve() {
	for (int i = 0; _input[i]; i++){
		if (std::isdigit(_input[i]))
			process_number(&i);
		else if (_input[i] != ' ')
			process_operand(_input[i]);
	}
	if (_stack.size() > 1 || _stack.size() < 1)
		error("Invalid expression: incorrect number of operands\n");
	return (_stack.top());
}

//PRIVATE HELPER FTS
void	RPN::process_number(int *i){
	int num;
	std::stringstream ss(&_input[*i]);
    ss >> num;
	if (ss.fail() || num >= 10)
		error("Incorrect num\n");
	_stack.push(num);
	if (!std::isdigit(_input[*i]))
		*i += 1;
	*i += abs(num) / 10;
}

void	RPN::process_operand(char const operand){
	int a, b;
	if (_stack.size() < 2)
		error("Invalid expression: not enough operands or incorrect order\n");
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	switch (operand){
		case '+':
			_stack.push(a + b);
			break;
		case '-':
			_stack.push(a - b);
			break ;
		case '*':
			_stack.push(a * b);
			break;
		case '/':
			if (b == 0)
				error("Undefined\n");
			else
				_stack.push(a / b);
			break;
	}
}

void	RPN::error(std::string msg) const{
	std::cerr<<RED<<"Error: "<<msg<<RESET;
	exit (2);
}
