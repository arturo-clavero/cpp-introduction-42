/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:20:47 by arturo            #+#    #+#             */
/*   Updated: 2024/07/12 20:24:12 by arturo           ###   ########.fr       */
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
	span1.getSize("Span");
}

void	testCopyConstructor(){
	std::cout<<"\nTESTING COPY CONSTRUCTOR\n";
	int	max = 3;
	Span span1(max);
	for(int i = 0; i < max; i++)
		span1.addNumber(i);
	span1.getSize("Span 1");
	span1.print("Span 1");
	Span span2(span1);
	span2.getSize("Span 2");
	span2.print("Span 2");
}

void	testCopyOp(){
	std::cout<<"\nTESTING COPY OPERATOR\n";
	int	max = 3;
	Span span1(max);
	for(int i = 0; i < max; i++)
		span1.addNumber(i);
	span1.getSize("Span 2");
	span1.print("Span 1");
	Span span2(1);
	span2.addNumber(5);
	span2.getSize("Span 2");
	span2.print("Span 2");
	span2 = span1;
	span2.getSize("Span 2");
	span2.print("Span 2");
	Span span3(5);
	for (int i = 0; i < 5; i++){
		span3.addNumber(i + 10);
	}
	span3.getSize("span 3");
	span3.print("span 3");
	span3 = span2;
	span3.getSize("span 3");
	span3.print("span 3");
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
	span.print();
	std::cout<<"Shortest span: "<<span.shortestSpan()<<std::endl;
	std::cout<<"Longest span: "<<span.longestSpan()<<std::endl;
}

void	manyNumsInOneGo(){
	Span span(10);
	span.addNumber(9);
	span.print("span");
	int array[] = {1, 3, 5, 7};
	span.addArrayOfNums(array, 4);
	span.print("span");
	int array2[3] = {11, 33, 55};
	span.addArrayOfNums(array2, 3);
	span.print();
}

int	main(void){
	testConstructor();
	testCopyConstructor();
	testCopyOp();
	invalidPush();
	invalidMaxDist();
	invalidMinDist();
	subjectTest();
	testThousands(10);
	testThousands(50);
	testThousands(100);
	manyNumsInOneGo();
}