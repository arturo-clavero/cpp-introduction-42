/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:46:42 by artclave          #+#    #+#             */
/*   Updated: 2024/08/08 02:12:55 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//ORTHODOX

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 		AForm("robotomy", 72, 45),
																	_target(target),
																	_required_grade_sign(72),
																	_required_grade_execute(45)
{
	std::cout<<"Constructor called for "<<*this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & og): 		AForm(og),
																				_target(og.getTarget()),
																				_required_grade_sign(og.getRequiredGradeSign()),
																				_required_grade_execute(og.getRequiredGradeExecute())
{
	std::cout<<"Copy constructor called for "<<*this;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & og) {
	_target = og.getTarget();
	std::cout<<"Copy assignment operator called for "<<*this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout<<"Destructor called for "<<*this;
}

//GETTERS
std::string	RobotomyRequestForm::getTarget() const{
	return _target;
}

int	RobotomyRequestForm::getRequiredGradeSign() const{
	return _required_grade_sign;
}

int	RobotomyRequestForm::getRequiredGradeExecute() const{
	return _required_grade_execute;
}

//OTHER
void	RobotomyRequestForm::form_action() const{
	int	fail, pid, flags;
	std::srand(std::time(0));
	fail = std::rand() % 2;
	if (fail)
	{
		std::cout<<_target<<" failed to be robotomized\n";
		return ;
	}
	pid = fork();
    if (pid == 0) {
		std::cout<<"\nYou can press enter to stop the drilling\n";
		execlp("aplay", "aplay", "drill.wav", NULL);
        exit(1);
    }
	else{
		flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
        while (true) {
            if (waitpid(pid, &flags, WNOHANG) == pid)
				break;
            if (read(STDIN_FILENO, &flags, 1) > 0) {
                kill(pid, SIGKILL);
				std::cout<<"\nCongratulations!!! You are boring.\n\n";
                break;
            }
        }
	}
	std::cout<<_target<<"has been successfully robotomized\n";
}

//PRINT
std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const & form){
	out<<"Robotomy Request Form with target: "<<form.getTarget()<<", required grade for signing ["<<form.getRequiredGradeSign()<<"], and for executing ["<<form.getRequiredGradeExecute()<<"]\n";
	return out;
}