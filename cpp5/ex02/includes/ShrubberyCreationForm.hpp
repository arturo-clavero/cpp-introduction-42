/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:46:40 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 00:25:21 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
	private:
		std::string			_target;
		int	const			_required_grade_sign;
		int	const			_required_grade_execute;
	public:
	//orthodox
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & og);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const & og);
		~ShrubberyCreationForm();
	//getters
		std::string getTarget() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;
	//other
		void	form_action() const;
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const & form);

#endif