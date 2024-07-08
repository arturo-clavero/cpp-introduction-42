/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:23:18 by arturo            #+#    #+#             */
/*   Updated: 2024/07/08 15:38:31 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename FT>

void	iter(T *arrayAddress, int arrayLength, FT function){
	for (int i = 0; i < arrayLength; i++){
		function(arrayAddress[i]);
	}
}

#endif