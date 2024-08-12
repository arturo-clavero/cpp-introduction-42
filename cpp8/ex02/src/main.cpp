/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:45:45 by arturo            #+#    #+#             */
/*   Updated: 2024/08/12 22:36:16 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "typeinfo"
void	subject_test(){
	MutantStack<int>mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	print_test(){
	MutantStack<int>mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout<<mstack;
}

void	reverse_init_test(){
	std::stack<int> realStack;
    realStack.push(10);
    realStack.push(20);
    realStack.push(30);
	MutantStack<int> mutantStack(realStack);
	std::cout<<mutantStack<<"\n";
	std::cout<<"real stack size: "<<realStack.size()<<"\n";
	std::cout<<"my stack size: "<<mutantStack.size()<<"\n";
}

void	member_type_test(){
    std::stack<int> realStack;
    realStack.push(10);
    realStack.push(20);
    realStack.push(30);
	//init mutant with real stack:
    MutantStack<int> mutantStack(realStack);

    // Member types for std::stack
    std::cout<<"std::stack member types:\n";
    std::cout<<"value_type: "<<typeid(std::stack<int>::value_type).name()<<"\n";
    std::cout<<"size_type: "<<typeid(std::stack<int>::size_type).name()<<"\n";
    std::cout<<"reference: "<<typeid(std::stack<int>::reference).name()<<"\n";
    std::cout<<"const_reference: "<<typeid(std::stack<int>::const_reference).name()<<"\n";

    // Member types for MutantStack
    std::cout<<"MutantStack member types:\n";
    std::cout<<"value_type: "<<typeid(MutantStack<int>::value_type).name()<<"\n";
    std::cout<<"size_type: "<<typeid(MutantStack<int>::size_type).name()<<"\n";
    std::cout<<"reference: "<<typeid(MutantStack<int>::reference).name()<<"\n";
    std::cout<<"const_reference: "<<typeid(MutantStack<int>::const_reference).name()<<"\n";
}

int main()
{
 	subject_test();
	std::cout<<"\n\n";
 	print_test();
	std::cout<<"\n\n";
 	reverse_init_test();
	std::cout<<"\n\n";
	member_type_test();
}