/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:12:21 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 16:50:11 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




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