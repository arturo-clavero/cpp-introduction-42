/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 02:19:25 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 02:41:46 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

class	Form;

class	Intern{
	private:
	public:
	//orthodox
		Intern();
		Intern(Intern const & og);
		Intern	&operator=(Intern const & og);
		~Intern();
	//other
		AForm	*makeShrub(std::string const target) const;
		AForm	*makeRobot(std::string const target) const;
		AForm	*makePresi(std::string const target) const;
		AForm	*makeForm(std::string const name, std::string const target) const;
};

#endif