/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:12:21 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 11:54:23 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class	Bureaucrat{
	private:
		std::string	const	name{"Default"};
		int					grade{150};
	public:
		class	GradeTooHighException : public std::exception{
			const char *what() const throw() override{
				return "Grade too high\n";
			}
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw() override{
				return "Grade too low\n";
			}
		};
		Bureaucrat(){
			std::cout<<"Bureaucrat default constructor called\n";
		};
		Bureaucrat(const std::string name_param, int grade) : name(name_param)
		{
			std::cout<<"Constructor with paremeters called for Bureaucrat"<<name<<"\n";
			if (grade < 1)
				throw GradeTooHighException();
			if (grade > 150)
				throw GradeTooLowException();
			this->grade = grade;
		}
		Bureaucrat(Bureaucrat const &original) : name(original.name){
			std::cout<<"Bureaucrat copy constructor called\n";
			grade = original.grade;
		}
		Bureaucrat	&operator=(Bureaucrat const &original) {
			std::cout<<"Bureaucrat copy assignment operator called\n";
			grade = original.grade;
			return *this;
		}
		~Bureaucrat(){
			std::cout<<"Destructor called for bureaucrat "<<name<<std::endl;
		}
		std::string	getName(){
			return name;
		}
		int	getGrade(){
			return grade;
		}
		void	increaseGrade(int amount){
			std::cout<<"Increasing grade by "<<amount<<std::endl;
			if (grade - amount < 1)
				throw GradeTooHighException();
			grade -= amount;
		}
		void	decreaseGrade(int amount){
			std::cout<<"Decreasing grade by "<<amount<<std::endl;
			if (grade + amount > 150)
				throw GradeTooLowException();
			grade += amount;
		}
};

std::ostream	&operator<<(std::ostream &cout_param, Bureaucrat &bur){
	std::cout<<bur.getName()<<", bureaucrat grade "<<bur.getGrade()<<std::endl;
	return (cout_param);
};

class	AForm{
	private:
		std::string	const	name;
		bool				isSigned;
		int	const			signGrade{1};
		int	const			execGrade{1};
	public:
		class	GradeTooHighException : public std::exception{
			const char *what() const throw() override{
				return "Grade too high\n";
			}
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw() override{
				return "Grade too low\n";
			}
		};
		AForm(){
			std::cout<<"AForm default constructor called\n";
			isSigned = false;
		};
		AForm(const std::string name_param, int signGrade_param, int execGrade_param) : name(name_param), signGrade(signGrade_param), execGrade(execGrade_param)
		{
			std::cout<<"Constructor with paremeters called for aform ('"<<name<<"')\n";
			if (execGrade < 1)
				throw GradeTooHighException();
			if (execGrade > 150)
				throw GradeTooLowException();
			isSigned = false;
		}
		AForm(AForm const &original) : name(original.name), signGrade(signGrade), execGrade(execGrade){
			std::cout<<"AForm copy constructor called\n";
			isSigned = original.isSigned;
		}
		AForm	&operator=(AForm const &original) {
			std::cout<<"AForm copy assignment operator called\n";
			return *this;
		}
		~AForm(){
			std::cout<<"Destructor called for aform "<<name<<std::endl;
		}
		std::string	getName(){
			return name;
		}
		int	getSignGrade(){
			return signGrade;
		}
		int	getExecGrade(){
			return execGrade;
		}
		int	getIsSigned() {
			return isSigned;
		}
		void	beSigned(Bureaucrat &bur) {
			if (bur.getGrade() > signGrade)
				throw GradeTooLowException();
			isSigned = true;	
		}
		void	signForm(Bureaucrat &bur) {
			if (isSigned)
				std::cout<<bur.getName()<<" signed "<<name<<std::endl;
			else if (bur.getGrade() > signGrade)
				std::cout<<bur.getName()<<" couldn't sign "<<name<<" because their grade is too low\n";
			else
				std::cout<<bur.getName()<<" couldn't sign "<<name<<" because they are incompetent\n";
		}
		virtual void perform_task(Bureaucrat const & executor) = 0;
		bool	execute(Bureaucrat const & executor) const{
			if (execGrade == 137)
			{
				std::cout<<"Success!\n\n";
				return (true);

			}
			return (false);
		}
};

std::ostream	&operator<<(std::ostream &cout_param, AForm &form){
	std::cout<<form.getName()<<", signed: "<<form.getIsSigned()<< ", required grade for signing: "<<form.getSignGrade()<<"required grade for executing: "<<form.getExecGrade()<<std::endl;
	return (cout_param);
};

/*• ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.*/
class	ShrubberyCreationForm : public AForm{
	private:
		const int	signGrade{145};
		const int	execGrade{137};
		std::string	target;
	
	public:
		ShrubberyCreationForm() : AForm("Shrubbery creation form", signGrade, execGrade){
			std::cout<<"ShrubberyCreationForm default constructor called\n";
		}
		ShrubberyCreationForm(std::string target_param) : AForm("Shrubbery creation form " + target_param, signGrade, execGrade) {
			std::cout<<"ShrubberyCreationForm constructor with params called\n";
			target = target_param;
		}
		ShrubberyCreationForm(ShrubberyCreationForm &original){
			std::cout<<"ShrubberyCreationForm copy constructor called\n";
			target = original.target;
		}
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm &original){
			std::cout<<"ShrubberyCreationForm copy assignment operator called\n";
			target = original.target;
			return *this;
		}
		~ShrubberyCreationForm(){
			std::cout<<"Destructor called\n";
		}
		void	perform_task(Bureaucrat const & executor){
			if (execute(executor))
				std::cout<<"yes\n";
			else
				std::cout<<"no\n";
		}

};

int main(void)
{
	Bureaucrat	bur("name", 1);
	std::cout<<"mid .... \n";
	AForm	*test = new ShrubberyCreationForm();

	std::cout<<"heeeyyy\n";
	test->perform_task(bur);
}