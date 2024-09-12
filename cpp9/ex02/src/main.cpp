/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:46:57 by artclave          #+#    #+#             */
/*   Updated: 2024/09/04 14:58:03 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av){
	struct timeval start, end;
	long elapsed_time_vector, elapsed_time_deque, seconds, microseconds;
	(void)elapsed_time_deque;
	(void)elapsed_time_vector;
	if (ac < 2)
		PmergeMe::error("not enough args\n");
	std::vector<int> original = PmergeMe::parsing(av);
	std::vector<int> vec = PmergeMe::parsing<myVector>(av);
	std::deque<int> deque = PmergeMe::parsing<myDeque>(av);

 	//time vector :
    gettimeofday(&start, NULL);
	PmergeMe::ford_algo(vec);
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    elapsed_time_vector = seconds * 1000000 + microseconds;

	//time deque :
    gettimeofday(&start, NULL);
	PmergeMe::ford_algo(deque);
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    elapsed_time_deque = seconds * 1000000 + microseconds;

	std::cout<<"Before: ";
	PmergeMe::print_container(original);
	std::cout<<"After:  ";
	PmergeMe::print_container(vec);
	//PmergeMe::print_container(deque);
	std::cout<<"Time to process a range of "<<vec.size()<<" elements with std::vector<int> : "<<elapsed_time_vector<<" us\n";
	std::cout<<"Time to process a range of "<<deque.size()<<" elements with std::vector<int> : "<<elapsed_time_deque<<" us\n";
}

