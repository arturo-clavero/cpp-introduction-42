/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:42:53 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 00:05:47 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "RPN.hpp"

//if you un comment the code you will see in stdout how it works :)

void	rpn(std::string str){
	std::stack<int>	stack;
	int	a, b;
	for (int i = 0; str[i]; i++){
		if (std::isdigit(str[i]))
		{
			stack.push(str[i] - 48);
			//std::cout<<"Just pushed "<<stack.top()<<"\n";
		}
		else if (str[i] != ' '){
			if (stack.size() < 2){
				std::cerr<<"Invalid expression: not enough operands or incorrect order\n";
				exit(2);
			}
			b = stack.top();
			stack.pop();
			//std::cout<<"took "<<a<<"\n";
			a = stack.top();
			//std::cout<<"took "<<b<<"\n";
			stack.pop();
			switch (str[i]){
				case '+':
					stack.push(a + b);
					break;
				case '-':
					stack.push(a - b);
					break ;
				case '*':
					stack.push(a * b);
					break;
				case '/':
					if (b == 0)
						stack.push(0);
					else
						stack.push(a / b);
					break;
			}
			//std::cout<<"just pushed "<<a<<" "<<str[i]<<" "<<b<<" which is "<<stack.top()<<"\n";
		}
		//std::cout<<"\n";
	}
	if (stack.size() > 1){
		std::cerr<<"Invalid expression: too many operands\n";
		exit (2);
	}
	if (stack.size() < 1){
		std::cerr<<"Invalid expression: not enough operands\n";
		exit (2);
	}
	std::cout<<stack.top()<<"\n";
}