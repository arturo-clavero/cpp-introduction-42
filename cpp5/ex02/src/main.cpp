/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:05:22 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 19:10:51 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	//testAFormValues
	//testTooLowToSign
	//testTooLowToExec
	//testExecShrubb
	//testExecRobot
	//testExecPresi
	 Bureaucrat bur("Mr. Guy", 140);
	 ShrubberyCreationForm form("home");
	 std::cout<<"\n"<<form<<"\n";
	form.beSigned(bur);
	form.signForm(bur);
	//bur.executeForm(form);
	std::cout<<"\n";
}