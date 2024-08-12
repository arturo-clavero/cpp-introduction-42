/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:20:47 by arturo            #+#    #+#             */
/*   Updated: 2024/08/12 23:01:24 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>   // for rand()
#include <ctime> //for time()

void	invalidPush(){
	Span	span(3);
	try {
	for (int i = 0; i < 4; i++){
		span.addNumber(i);
		std::cout<<"Added num "<<i<<"\n";
	}}catch(std::exception &e){
		std::cerr<<"Error: "<<e.what();
	}
}

void	testConstructor(){
	std::cout<<"\nTESTING CONSTRUCTOR\n";
	Span span1(5);
	span1.printSize("Span");
}

void	testCopyConstructor(){
	std::cout<<"\nTESTING COPY CONSTRUCTOR\n";
	int	max = 3;
	Span span1(max);
	for(int i = 0; i < max; i++)
		span1.addNumber(i);
	span1.printSize("Span 1");
	std::cout<<span1;
	Span span2(span1);
	span2.printSize("Span 2");
	std::cout<<span1;
}

void	testCopyOp(){
	std::cout<<"\nTESTING COPY OPERATOR\n";
	int	max = 3;
	Span span1(max);
	for(int i = 0; i < max; i++)
		span1.addNumber(i);
	span1.printSize("Span 1");
	std::cout<<span1;
	Span span2(1);
	span2.addNumber(5);
	span2.printSize("Span 2");
	std::cout<<span2;
	span2 = span1;
	span2.printSize("Span 2");
	std::cout<<span2;
	Span span3(5);
	for (int i = 0; i < 5; i++){
		span3.addNumber(i + 10);
	}
	span3.printSize("span 3");
	std::cout<<span3;
	span3 = span2;
	span3.printSize("span 3");
	std::cout<<span3;
}

void	invalidMaxDist(){
	std::cout<<"\nTESTING INVALID MAX SPAN\n";
	if (true){
	Span span(3);
	try {
		span.longestSpan();
	}catch(std::exception &e){
		std::cout<<e.what();
	}}
	Span span2(3);
	span2.addNumber(5);
	try {
		span2.longestSpan();
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}

void	invalidMinDist(){
	std::cout<<"\nTESTING INVALID MAX SPAN\n";
	if (true){
	Span span(3);
	try {
		span.shortestSpan();
	}catch(std::exception &e){
		std::cout<<e.what();
	}}
	Span span2(3);
	span2.addNumber(5);
	try {
		span2.shortestSpan();
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}

void	subjectTest(){
	Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;	
}

void	testThousands(int thousand){
	int	N = thousand * 1000;
	Span	span(N);
	std::srand(std::time(0));
	for (int i = 0; i < N; i++){
		span.addNumber(std::rand());
	}
	std::cout<<span;
	std::cout<<"Shortest span: "<<span.shortestSpan()<<std::endl;
	std::cout<<"Longest span: "<<span.longestSpan()<<std::endl;
}

void	manyNumsInOneGo(){
	Span span(8);
	span.addNumber(0);
	std::cout<<span;
	std::vector<int> array;
	try
	{
		array.push_back(1);
		array.push_back(3);
		array.push_back(5);
		array.push_back(7);
		span.addManyNums(array.begin(), array.end());
		span.addManyNums(array.begin(), array.end());
	}
	catch(std::exception &e){
		std::cout<<e.what();
	}
	std::cout<<span;
}

int	main(void){
	// testConstructor();
	// testCopyConstructor();
	// testCopyOp();
	// invalidPush();
	// invalidMaxDist();
	// invalidMinDist();
	 subjectTest();
	// testThousands(10);
	// testThousands(50);
	// testThousands(100);
	// manyNumsInOneGo();
}