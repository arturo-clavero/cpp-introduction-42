/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:46:38 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 00:24:40 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm{
	private:
		std::string			_target;
		int	const			_required_grade_sign;
		int	const			_required_grade_execute;
	public:
	//orthodox
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & og);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const & og);
		~RobotomyRequestForm();
	//getters
		std::string getTarget() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;
	//other
		void	form_action() const;
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const & form);

#endif