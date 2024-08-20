#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

#define LARGE 0
#define SMALL 1
#define SRC 1
#define DST 0

typedef std::vector<int> vector;
typedef std::deque<int> deque;

template <typename Container>
struct Type;

template<>
struct Type<std::vector<int> > {
    typedef std::vector<std::pair<int, int> > pair;
};

template<>
struct Type<std::deque<int> > {
    typedef std::deque<std::pair<int, int> > pair;
};

template <typename Container>
typename Type<Container>::pair make_null_pair(Container const &input);



template <typename Container>
void	print_vector_pair(Container const &input);

#include "PmergeMe.tpp"
#endif