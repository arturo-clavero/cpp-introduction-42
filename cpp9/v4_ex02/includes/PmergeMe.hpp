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
	typedef std::vector<int> _1d;
    typedef std::vector<std::vector<int> > _2d;
	typedef std::vector<std::vector<std::vector<int> > > _3d;
};

template<>
struct Type<std::deque<int> > {
	typedef std::deque<int> _1d;
    typedef std::deque<std::deque<int> > _2d;
	typedef std::deque<std::deque<std::deque<int > > > _3d;
};

template <typename Container>
typename Type<Container>::_3d	make_pairs(typename Type<Container>::_2d &input)
{
	int	associations = static_cast<int>(input.size());
	int total_pairs = static_cast<int>(input[0].size() / 2.0 + 0.5);
	typename Type<Container>::_3d	result(total_pairs);
	for (int pair = 0; pair < total_pairs; pair++)
    {
        result[pair].resize(associations);
        for (int asso = 0; asso < associations; asso++)
            result[pair][asso].resize(2);
    }
	int i;
	for (int asso = 0; asso < associations; asso++)
	{
		i = -1;
		for (int pair = 0; pair < total_pairs ; pair++)
		{
			for (int x = 0; x < 2; x++)
				result[pair][asso][x] = input[asso][++i];
		}
	}
	return result;
}

template <typename Container>
void	insert_row(typename Type<Container>::_2d &src_cont, int src_i, typename Type<Container>::_2d &dst_cont, int dst_i)
{
	for (int row = 0; row < static_cast<int>(src_cont.size()); row++)
		dst_cont[row][dst_i] = src_cont[row][src_i];
}

template <typename Container>
void	compare_and_divide_pairs(typename Type<Container>::_3d &input, typename Type<Container>::_2d &large, typename Type<Container>::_2d &small){
	int	associations = static_cast<int>(input[0].size());
	int total_pairs = static_cast<int>(input.size());
	std::cout<<"total pairs: "<<total_pairs<<"\n";
	std::cout<<"asso: "<<associations<<"\n";;
	for(int asso = 0; asso < associations; asso++)
	{
		large[asso].resize(total_pairs);
		large[asso].resize(total_pairs);
	}
	std::cout<<"checl\n";
	int x = 0;
	for (int pair = 0; pair < total_pairs; pair++)
	{
		std::cout<<"rr\n";
		if (input[pair][0][0] > input[pair][0][1])
		{
			std::cout<<"tt\n";
			insert_row<Container>(input[pair], 0, large, x);
			insert_row<Container>(input[pair], 1, small, x);
		}
		else
		{
			std::cout<<"stt\n";
			insert_row<Container>(input[pair], 0, small, x);
			std::cout<<"stt\n";
			insert_row<Container>(input[pair], 1, large, x);
		}
	}
}

template <typename Container>
void	print1D(typename Type<Container>::_1d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		std::cout<<input[x]<<" ";
	std::cout<<"\n";

}

template <typename Container>
void	print2D(typename Type<Container>::_2d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		print1D<Container>(input[x]);
	std::cout<<"\n";

}

template <typename Container>
void	print3D(typename Type<Container>::_3d &input)
{
	for (int x = 0; x < static_cast<int>(input.size()); x++)
		print2D<Container>(input[x]);
	std::cout<<"\n";

}

#include "PmergeMe.tpp"
#endif