/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:12:21 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 15:27:50 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class	Bureaucrat{
	private:
		std::string	const	name;
		int					grade;
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

class	Form{
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
		Form(){
			std::cout<<"Form default constructor called\n";
			isSigned = false;
		};
		Form(const std::string name_param, int requiredGrade) : name(name_param), signGrade(signGrade), execGrade(execGrade)
		{
			std::cout<<"Constructor with paremeters called for form "<<name<<"\n";
			if (execGrade < 1)
				throw GradeTooHighException();
			if (execGrade > 150)
				throw GradeTooLowException();
			isSigned = false;
		}
		Form(Form const &original) : name(original.name), signGrade(signGrade), execGrade(execGrade){
			std::cout<<"Form copy constructor called\n";
			isSigned = original.isSigned;
		}
		Form	&operator=(Form const &original) {
			std::cout<<"Form copy assignment operator called\n";
			//call copy constructor
		//	*this(original);
			return *this;
		}
		~Form(){
			std::cout<<"Destructor called for form "<<name<<std::endl;
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
};

std::ostream	&operator<<(std::ostream &cout_param, Form &form){
	std::cout<<form.getName()<<", signed: "<<form.getIsSigned()<< ", required grade for signing: "<<form.getSignGrade()<<"required grade for executing: "<<form.getExecGrade()<<std::endl;
	return (cout_param);
};


int	main(void)
{
	try {
		Bureaucrat bur1("One", 2);
		std::cout<<bur1;
		bur1.decreaseGrade(1);
		bur1.increaseGrade(50);
		std::cout<<bur1;
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}