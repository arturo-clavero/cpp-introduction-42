/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:42:53 by artclave          #+#    #+#             */
/*   Updated: 2024/08/13 05:08:25 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "RPN.hpp"
#include <string>
#include <sstream>
#include <algorithm>

RPN::RPN(std::string const &str, int mode) : _input(str), _mode(mode) {
	std::string allowed = "0123456789 +*-/";
	std::string operand = "+*-/";
    if (std::find_if(_input.begin(), _input.end(), std::bind2nd(std::ptr_fun(isValidChar), allowed)) == _input.end())
		error("Invalid expression: only digits, operands and spaces allowed\n");
	std::string::const_iterator it = std::find_if(_input.begin(), _input.end(), std::bind2nd(std::ptr_fun(isValidChar), operand));
	if (mode == 0 && (it != _input.end() && (it == _input.begin() || *(it - 1) != ' '|| (*(it + 1) != ' ' && it + 1 != _input.end()))))
		error("Invalid expression: operands must be preceeded and proceeded by spaces\n\t(last operand doesnt have to be preceeded by a space)\n");
	else if (mode == 1 && (it != _input.end() && (it == _input.begin() || *(it - 1) != ' '|| (*(it + 1) != ' ' && it + 1 != _input.end() && !(std::isdigit(*(it + 1)) && (*it == '+' || *it == '-'))))))
		error("Invalid expression: operands must be preceeded by spaces and proceeded by a space (or a digit for  + and -)\n\t(last operand doesnt have to be preceeded by a space)\n");
}

RPN::RPN(RPN const & other) : _input(other.getInput()), _mode(other.getMode()){};

RPN::~RPN(){};

std::string RPN::getInput() const{
	return _input;
}

int	RPN::getMode() const{
	return _mode;
}

int RPN::solve() {
	for (int i = 0; _input[i]; i++){
		if (std::isdigit(_input[i]) || (_mode == 1 && (_input[i] == '+' || _input[i] == '-') && _input[i + 1] && std::isdigit(_input[i + 1])))
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
	if (ss.fail())
		error("Conversion to digit failed\n");
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
				_stack.push(0);
			else
				_stack.push(a / b);
			break;
	}
}

void	RPN::error(std::string msg) const{
	std::cerr<<RED<<msg<<RESET;
	exit (2);
}

bool RPN::isValidChar(char c, const std::string &haystack) {
    return haystack.find(c) != std::string::npos;
}