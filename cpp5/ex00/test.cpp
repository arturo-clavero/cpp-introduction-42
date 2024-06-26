/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:12:21 by arturo            #+#    #+#             */
/*   Updated: 2024/06/27 03:19:16 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

/*A constant name.
• And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
grade).
Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex-
ception:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.*/

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
			std::cout<<"Default constructor called\n";
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
	//<name>, bureaucrat grade <grade>.
	std::cout<<bur.getName()<<", bureaucrat grade "<<bur.getGrade()<<std::endl;
	return (cout_param);
};


int	main(void)
{
	try {
		Bureaucrat bur1("One", 2);
		Bureaucrat bur2("One", 160);
		std::cout<<bur1;
		std::cout<<bur2;
		bur1.decreaseGrade(1);
		bur1.increaseGrade(50);
		bur2.increaseGrade(100);
		std::cout<<bur1;
		std::cout<<bur2;
	}catch(std::exception &e){
		std::cout<<e.what();
	}
}