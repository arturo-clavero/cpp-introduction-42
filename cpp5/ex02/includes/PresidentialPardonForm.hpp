/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:46:35 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 00:24:43 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string			_target;
		int	const			_required_grade_sign;
		int	const			_required_grade_execute;
	public:
	//orthodox
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & og);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const & og);
		~PresidentialPardonForm();
	//getters
		std::string getTarget() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;
	//other
		void	form_action() const;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const & form);

#endif