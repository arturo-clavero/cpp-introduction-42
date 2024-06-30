/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:20:14 by arturo            #+#    #+#             */
/*   Updated: 2024/06/30 20:26:15 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

void	sed(const std::string &fileName, std::string oldNeedle, std::string newNeedle);
std::string	ftReplace(std::string haystack, std::string oldNeedle, std::string newNeedle);

#endif