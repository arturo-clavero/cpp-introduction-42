/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:40:15 by artclave          #+#    #+#             */
/*   Updated: 2024/07/23 00:09:32 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	parsing(char *str){
	int	total_op = 0;
	int	total_num = 0;
	std::string	op = "+-*/";
	for (int i = 0; str[i];){
		if (std::isdigit(str[i])){
			total_num++;
			while (str[i] && std::isdigit(str[i]))
				i++;
			if (str[i] != ' ' && str[i]){
				std::cout<<"Invalid expresion: operands and operators must be separated by space\n";
				exit (2);
			}
		}
		else if (op.find(str[i]) != std::string::npos){
			total_op++;
			i++;
			if (str[i] != ' ' && str[i]){
				std::cout<<"Invali expresion: operands and operators must be separated by space\n";
				exit (2);
			}
		}
		else if (str[i] == ' '){
			while (str[i] && str[i] == ' ')
				i++;
		}
		else if (str[i]){
			std::cerr<<"Invalid expression: only digits and operands + - * / allowed\n";
			exit (2);
		}
	}
	if (total_op > total_num - 1){
		std::cerr<<"XXInvalid expression: too many operators\n";
		exit (2);
	}
}

int	main(int ac, char **av){
	if (ac != 2){
		std::cerr<<"Invalid arguments\n";
		return 2;
	}
	parsing(av[1]);
	rpn(av[1]);
}