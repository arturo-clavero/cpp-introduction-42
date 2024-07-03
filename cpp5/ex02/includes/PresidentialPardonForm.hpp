/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:20:58 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 02:21:59 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class  PresidentialPardonForm : public AForm{
	
	private:
		std::string	const	name;
		std::string			target;
		bool				isSigned;
		int	const			signGrade;
		int	const			execGrade;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &original);
		~PresidentialPardonForm();
		void	performTask() const;
};

#endif