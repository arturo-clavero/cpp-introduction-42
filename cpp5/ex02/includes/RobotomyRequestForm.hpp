/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:19:50 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 03:07:21 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class  RobotomyRequestForm : public AForm{
	
	private:
		std::string	const	name;
		std::string			target;
		bool				isSigned;
		int	const			signGrade;
		int	const			execGrade;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &original);
		~RobotomyRequestForm();
		void	performTask() const;
};

#endif