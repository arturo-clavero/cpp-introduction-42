/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:09:14 by artclave          #+#    #+#             */
/*   Updated: 2024/08/19 03:36:25 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//ORTHODOX
template <typename T>
PmergeMe<T>::PmergeMe(){};

template <typename T>
PmergeMe<T>::~PmergeMe(){};

template <typename T>
PmergeMe<T>::PmergeMe(char **av) {
	std::string allowed = "0123456789 +";
	int	num;
	std::string str;
	for (int i = 1; av[i]; i++) {
		str = av[i];
   		if (std::find_if(str.begin(), str.end(), std::bind2nd(std::ptr_fun(hasWeirdChars), allowed)) != str.end())
		{
			error("Invalid expression: only digits, '+' and spaces allowed\n");
		}
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] == '+' && ((!av[i][j] || !std::isdigit(av[i][j+1])) || (av[i][j - 1] && std::isdigit(av[i][j - 1]))))
				error("Invalid expression: '+' have to be followed by digits and preceded by null or space\n");
		}	
		for (int j = 0; av[i][j]; j++)
		{
			while (str[j] && str[j] == ' ')
				j++;
			std::stringstream ss(&str[j]);
    		ss >> num;
			if (num < 0)
				error("Numbers must be positiven");
			_container.push_back(num);
			if (str[j] == '+')
				j ++;
			j += abs(num) / 10;
		}
	}
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const & other){
	_container = other.getContainer();
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe const & other){
	_container = other.getContainer();
	return *this;
}



//MEMBER FTS
template <typename T>
void PmergeMe<T>::ford_algo(T& input) {
    T max, min;
    split(input, max, min);
    if (max.size() > 1) {
        ford_algo(max);
    }
    binary_sort(max, min);
    input = max;
}

template <typename T>
void	PmergeMe<T>::ford_algo(){
	ford_algo(_container);
}

template <typename T>


//HELPER FTS
template<>
void	PmergeMe<std::list<int> >::recursive_sort(std::list<int> & max, int &low, int &high, int x){
	std::list<int>::iterator it = max.begin();
	int	m = (low + high) / 2;
	int	max_m;
	for (int i = 0; i < m; i++)
		it++;
	max_m = *it;
	if (x < max_m)
		high = m - 1;
	else if (x > max_m)
		low = m + 1;
	else {
		it = max.begin();
		for (int i = 0; i < m; i++)
			it++;
		max.insert(it, x);
		low = 0;
		high = max.size() - 1;
		return ;
	}
	if (low > high)
	{
		it = max.begin();
		for (int i = 0; i < low; i++)
			it++;
		max.insert(it, x);
		low = 0;
		high = max.size() - 1;
		return ;
	}
	recursive_sort(max, low, high, x);
}

template <typename T>
void	PmergeMe<T>::binary_sort(T & max, T & min){
	int	low, high;
	low = 0;
	high = static_cast<int>(max.size()) - 1;
	for (typename T::iterator it = min.begin(); it != min.end(); it++)
		recursive_sort(max, low, high, *it);
}

template <typename T>
void	PmergeMe<T>::split(T input, T & max, T & min){
	for (typename T::iterator it = input.begin(); it != input.end();)
	{
		typename T::iterator next = ++it;
		it--;
		if (next == input.end())
			min.push_back(*it);
		else if (*it >= *next) {
			max.push_back(*it);
			min.push_back(*next);
		}
		else {
			min.push_back(*it);
			max.push_back(*next);
		}
		it++;
		if (it == input.end())
			break;
		it++;
	}
}

template <typename T>
void	PmergeMe<T>::error(std::string msg) {
	std::cerr<<msg;
	exit (2);
}

template <typename T>
bool	PmergeMe<T>::hasWeirdChars(char c, const std::string &haystack) {
    if (haystack.find(c) == std::string::npos)
		return true;
	return (false);
}

//GETTERS
template <typename T>
T	&PmergeMe<T>::getContainer(){
	return _container;
}

template <typename T>
int	PmergeMe<T>::getSize() const{
	return static_cast<int>(_container.size());
}

//PRINT

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os<<vec[i];
        if (i < vec.size() - 1) {
            os<<" ";
        }
    }
    os<<"\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst) {
    std::list<int>::const_iterator it = lst.begin();
    while (it != lst.end()) {
        os<<*it<<" ";
        ++it;
    }
	os<<"\n";
    return os;
}