#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <sstream> 
#include <algorithm>

#define ODD -1

typedef std::vector<int> vector;
typedef std::deque<int> deque;

template <typename Container>
struct Type;

template<>
struct Type<std::vector<int> > {
    typedef std::vector<std::pair<int, int> > pair;
    typedef std::vector<std::vector<int> > array;
};

template<>
struct Type<std::deque<int> > {
	typedef std::deque<std::pair<int, int> > pair;
	typedef std::deque<std::vector<int> > array;
};

class	PmergeMe{
	private:
		PmergeMe();
		PmergeMe(PmergeMe const &og);
		PmergeMe &operator=(PmergeMe const &og);
		~PmergeMe();

	public:
		static void	error(std::string msg);

		template <typename Container>
		static bool	already_exists(int num, Container container);

		static bool 	hasWeirdChars(char c, const std::string &haystack);

		template <typename Container>
		static Container parsing(char **av);
		
		template <typename Container>
		static void	binary_search(Container &sorted, int const element, int &low, int &high);

		template <typename Container>
		static void	setup_binary_search(typename Type<Container>::array const &group, Container &sorted);

		template <typename Container>
		static void	reverse(Container &input);

		static int	get_total_sub_groups(int elements);

		template <typename Container>
		static void divide_in_adjacent_sequences_of_pow2(Container const &input, typename Type<Container>::array &unsorted_groups);

		template <typename Container>
		static void	insert(Container &container, int index, int element);

		template <typename Container>
		static void	insert_first_unsorted(Container &large, Container const &small);

		template <typename Container>
		static void	match_indexes(typename Type<Container>::pair const &pairs, Container const &sorted, Container &unsorted);

		template <typename Container>
		static void	determine_large_elements(typename Type<Container>::pair &pairs, Container &large);

		template <typename Container>
		static void	pair_elements(Container const &input, typename Type<Container>::pair &result);

		template <typename Container>
		static void	ford_algo(Container &input);

		template <typename Container>
		static void	print_array(Container const &input);

		template <typename Container>
		static void	print_pairs(Container const &input);

		template <typename Container>
		static void	print_container(Container const & input);
};

#include "PmergeMe.tpp"
#endif