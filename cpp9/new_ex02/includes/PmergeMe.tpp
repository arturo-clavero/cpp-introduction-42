/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:39:52 by artclave          #+#    #+#             */
/*   Updated: 2024/08/18 20:06:40 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Container>
Container make_pairs(typename Container::value_type const &input){
	int n = static_cast<int>(input.size() / 2.0 + 0.5);
    Container pairs(n, typename Container::value_type(2));
	n = 0;
	int i = 0;
    for (typename Container::value_type::const_iterator it = input.begin(); it != input.end(); it++)
	{
		pairs[n][i] = *it;
 		n += i;
 		i ^= 1;
	}
	if (i == 1)
		pairs[n][i] = -1;
    return pairs;
}

template <typename Container>
Container	compare_and_divide_pairs(Container const &pairs){
	Container result(2, typename Container::value_type(pairs.size()));
	for (int x = 0; x < static_cast<int>(pairs.size()); x++)
	{
		if (pairs[x][1] < 0)
			result[SMALL][x] = pairs[x][0];
		else if (pairs[x][0] < pairs[x][1])
		{
			result[SMALL][x] = pairs[x][0];
			result[LARGE][x] = pairs[x][1];
		}
		else {
			result[SMALL][x] = pairs[x][1];
			result[LARGE][x] = pairs[x][0];
		}
	}
	return result;
}

template <typename Container>
void	print_array(Container const &input){
	for (int x = 0; x < static_cast<int>(input.size()); x++)
	{
		for (int y = 0 ; y < static_cast<int>(input[x].size()) ; y++)
			std::cout<<input[x][y]<<" ";
		std::cout<<"\n";
	}
}

template <typename T>
void	print_single(T const &input){
	for (int y = 0 ; y < static_cast<int>(input.size()) ; y++)
			std::cout<<input[y]<<" ";
		std::cout<<"\n";
}