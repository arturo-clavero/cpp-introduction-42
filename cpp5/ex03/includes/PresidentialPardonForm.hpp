/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:20:58 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 04:23:12 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Form.hpp"

class  PresidentialPardonForm : public AForm, public Form{
	
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