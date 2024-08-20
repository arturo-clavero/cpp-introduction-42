/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/08/20 07:12:12 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(void){
	std::cout<<"create 1d vector\n";
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	print1D<vector>(vec);
	std::cout<<"\ncreate 2d vector\n";
	std::vector<std::vector<int> > vec2;
	vec2.push_back(vec);
	vec2.push_back(vec);
	print2D<vector>(vec2);
	std::cout<<"\ncreate 3d vector\n";
	std::vector<std::vector<std::vector<int > > > vec3;
	vec3.push_back(vec2);
	vec3.push_back(vec2);
	print3D<vector>(vec3);

}

