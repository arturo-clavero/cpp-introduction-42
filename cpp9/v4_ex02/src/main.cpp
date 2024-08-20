/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/20 08:38:41 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(void){
	std::cout<<"create 1d vector\n";
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	print1D<vector>(vec);
	std::vector<int> vec1;
	vec1.push_back(-1);
	vec1.push_back(-2);
	vec1.push_back(-3);
	vec1.push_back(-4);
	print1D<vector>(vec1);
	std::cout<<"\ncreate 2d vector\n";
	std::vector<std::vector<int> > vec2;
	vec2.push_back(vec);
	vec2.push_back(vec1);
	vec2.push_back(vec);
	vec2.push_back(vec1);
	std::vector<std::vector<std::vector<int> > > vec3 = make_pairs<vector>(vec2);
	print3D<vector>(vec3);
	std::vector<std::vector<int > > large(vec3[0].size()), small(vec3[0].size());
	compare_and_divide_pairs<vector>(vec3, large, small);
	std::cout<<"LARGE:\n";
	print2D<vector>(large);
	std::cout<<"SMALL:\n";
	print2D<vector>(small);
}

