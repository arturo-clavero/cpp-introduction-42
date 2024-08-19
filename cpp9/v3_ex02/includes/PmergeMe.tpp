/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:39:52 by artclave          #+#    #+#             */
/*   Updated: 2024/08/20 05:30:43 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// std::vector<std::vector<std::vector<int> > > make_pairs(std::vector<std::vector<int> >  const &input){
// 	int n = static_cast<int>(input.size() / 2.0 + 0.5);
//     std::vector<std::vector<std::vector<int> > >  pairs(n);
// 	n = 0;
// 	int i = 0;
//     for (int j = 0; j < static_cast<int>(input[0].size()); j++)// = input.begin(); it != input.end(); it++)
// 	{
// 		for (int z = 0; z < static_cast<int>(input.size()); z++)
// 			pairs[n][i][z] = input[z][j];
//  		n += i;
// 		if (i == 1)
// 			pairs[n].resize(2);
//  		i ^= 1;
// 	}
// 	if (i == 1)
// 		pairs[n][i][0] = -1;
//     return pairs;
// }

template <typename Container>
typename ContainerTraits<Container>::array3D make_pairs(typename ContainerTraits<Container>::array2D const &input) {
    size_t num_rows = input.size();
    size_t num_cols = input[0].size();
    size_t num_pairs = (num_cols + 1) / 2; // Calculate number of pairs

    // Initialize the 3D vector with the appropriate sizes
    std::vector<std::vector<std::vector<int> > > pairs(num_pairs);

    for (size_t i = 0; i < num_pairs; ++i) {
        pairs[i].resize(2); // Each pair will contain two columns if available

        if (2 * i < num_cols) {
            pairs[i][0].resize(num_rows); // Resize to hold all rows
            for (size_t row = 0; row < num_rows; ++row) {
                pairs[i][0][row] = input[row][2 * i];
            }
        }

        if (2 * i + 1 < num_cols) {
            pairs[i][1].resize(num_rows); // Resize to hold all rows
            for (size_t row = 0; row < num_rows; ++row) {
                pairs[i][1][row] = input[row][2 * i + 1];
            }
        } else {
            pairs[i].resize(1); // If there's an odd number of columns, handle the last pair
        }
    }

    return pairs;}

template <typename Container>
void	print_2d_array(Container const &input){
	for (int x = 0; x < static_cast<int>(input.size()); x++)
	{
		std::cout<<"\t";
		for (int y = 0 ; y < static_cast<int>(input[x].size()) ; y++)
		{
			if (input[x][y] < 10 && input[x][y] >= 0)
				std::cout<<" ";
			std::cout<<input[x][y]<<" ";
		}
		std::cout<<"\n";
	}
}

void	print_3d_array(std::vector<std::vector<std::vector<int > > > const &input){
	for (int x = 0; x < static_cast<int>(input.size()); x++)
	{
		std::cout<<"\n input["<<x<<"]\n";
		print_2d_array(input[x]);
	}
}

template <typename T>
void	print_single(T const &input){
	for (int y = 0 ; y < static_cast<int>(input.size()) ; y++)
	{
		if (input[y] < 10 && input[y] > 0)
			std::cout<<" ";
		std::cout<<input[y]<<" ";
	}
	std::cout<<"\n";
}