/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:39:52 by artclave          #+#    #+#             */
/*   Updated: 2024/08/19 06:14:17 by artclave         ###   ########.fr       */
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
		if (pairs[x][1] < 0){
			result[SMALL][x] = pairs[x][0];
			result[LARGE].resize(result[LARGE].size() - 1);
		}
		else if (pairs[x][0] < pairs[x][1]){
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

template <typename T>
void	insert(T &input, int element, int index_insert){
	int	i;
	std::cout<<"inserting element "<<element<<", at index "<<index_insert<<"\n";
	i = static_cast<int>(input.size()) + 1;
	input.resize(input.size() + 1);
	while (--i > index_insert)
		input[i] = input[i - 1];
	input[index_insert] = element;
}

template <typename Container>
Container	divide_heuristically(typename Container::value_type const &input){
	int total = get_total_sub_groups(static_cast<int>(input.size()));
	Container result(total);
	int size = 0;
	typename Container::value_type::const_iterator it = input.begin();
	for (int i = 0; i < total; i++){
		size = std::pow(2, i + 1) - size;
		for (int j = 0; j < size; j++)
		{
			if (it == input.end())
				break;
			result[i].push_back(*it);
			it++;
		}
		if (it == input.end())
			break;
	}
	return result;
}

template <typename T>
void	reverse(T &input){
	T result;
	for (int i = static_cast<int>(input.size()) - 1; i >= 0; i--)
		result.push_back(input[i]);
	input = result;
}

template <typename Container>
void	for_each(Container &array, void(*ft)(typename Container::value_type &))
{
	for (int i = 0; i < static_cast<int>(array.size()); i++)
		ft(array[i]);
}

template <typename T>
void	binary_search(T & sorted, int insert_element, int &high, int &low){
	int	m = (low + high) / 2;
	if (insert_element < sorted[m])
		high = m - 1;
	else if (insert_element > sorted[m])
		low = m + 1;
	else {
		std::cout<<"element "<<insert_element<<", found at "<<m<<"\n";
		insert(sorted, insert_element, m);
		low = 0;
		high = sorted.size() - 1;
		return ;
	}
	if (low > high)
	{
		std::cout<<"low is: "<<low<<", and high is : "<<high<<"\n";
		insert(sorted, insert_element, low);
		low = 0;
		high = sorted.size() - 1;
		return ;
	}
	binary_search(sorted, insert_element, high, low);
}

template <typename Container>
void	reorder_unsorted(Container division, container pairs){
	//need 
	typename Container::value_type new_unsorted;
	//need to insert the smaller pair in new unsorted
	//go through division large, 
	//find element in pair 
	Container subgroups;
	subgroups = divide_heuristically<Container>(unsorted);
	int x = 0;
	for (int i = 0; i < static_cast<int>(subgroups.size()); i++)
	{
		for (int j = static_cast<int>(subgroups[i].size()) - 1; j >= 0; j--)
		{
			unsorted[x] = subgroups[i][j];
			x++;
		}
	}
}

template <typename Container>
void	ford_johnson_algo(typename Container &input){
	static int call;
	call++;
	Container pairs, division, unsorted;
	vector_pairs = make_pairs<Container>(input);
	std::cout<<"\n"<<call<<" PAIRS: \n";
	print_array(vector_pairs);
	division = compare_and_divide_pairs(pairs);
	std::cout<<"\n"<<call<<" LARGE : ";
	print_single(division[LARGE]);
	std::cout<<"\n"<<call<<" SMALL : ";
	print_single(division[SMALL]);
	if (division[LARGE].size() > 1){
		ford_johnson_algo<Container>(division[LARGE]);
		call--;
	}
	std::cout<<"\n"<<call<<" DIVISIONS : \n";
	print_array(division);
	std::cout<<"\n"<<call<<" UNSORTED AFTER re-ORDER: \n";
	reorder_unsorted<Container>(division, vector_pairs);
	move(division, 0, 0);
	std::cout<<"\n"<<call<<" DIVISIONS AFTER 1 MOVE: \n";
	print_array(division);
	print_single(division[SMALL]);
	int low, high;
	for (int i = 0; i < static_cast<int>(division[SMALL].size()); i++){
		high  = static_cast<int>(division[SMALL].size());
		low = 0;
		binary_search(division[LARGE], division[SMALL][i], high, low);
		std::cout<<"MINI SORT-> ";
		print_single(division[LARGE]);
	}
	input = division[LARGE];
}

template <typename Container>
void	print_array(Container const &input){
	for (int x = 0; x < static_cast<int>(input.size()); x++)
	{
		std::cout<<"\t";
		for (int y = 0 ; y < static_cast<int>(input[x].size()) ; y++)
		{
			if (input[x][y] < 10 && input[x][y] > 0)
				std::cout<<" ";
			std::cout<<input[x][y]<<" ";
		}
		std::cout<<"\n";
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