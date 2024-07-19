/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:42:53 by artclave          #+#    #+#             */
/*   Updated: 2024/07/20 05:34:12 by artclave         ###   ########.fr       */
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
					stack.push(a / b);
					break;
			}
			//std::cout<<"just pushed "<<a<<" "<<str[i]<<" "<<b<<" which is "<<stack.top()<<"\n";
		}
		//std::cout<<"\n";
	}
	std::cout<<stack.top()<<"\n";
}