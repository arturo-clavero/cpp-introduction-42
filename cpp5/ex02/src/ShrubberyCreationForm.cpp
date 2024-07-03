/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:35 by arturo            #+#    #+#             */
/*   Updated: 2024/07/04 03:15:28 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), name("Shrubbery Creation"), target("default"), signGrade(145), execGrade(137){
	std::cout<<"Default constructor called for Shrubbery\n";
	isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), name("Shrubbery Creation"), target("default"), signGrade(145), execGrade(137) {
	std::cout<<"Constructor called for Shrubbery with target "<<target<<"\n";
	isSigned = false;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm("Shrubbery Creation", 145, 37), name("Shrubbery Creation"), target("default"), signGrade(145), execGrade(37){
	std::cout<<"Copy constructor called for Shrubbery\n";
	isSigned = original.isSigned;
	target = original.target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original){
	std::cout<<"Copy assignment operator called for Shrubbery\n";
	isSigned = original.isSigned;
	target = original.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout<<"Destructor called for Shrubbery with target "<<target<<"\n";
}

void	ShrubberyCreationForm::performTask() const{
	std::string outputFileName = target + "_shrubbery";
	std::ofstream	output(outputFileName.c_str());
	output<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⡀⠀⠀⠂\n⠀⢀⢀⠠⢄⠀⠀⠘⠀⠠⠼⡀⠠⠤⣀⣀⣾⣷⡾⣿⣷⣀⢳⣿⣿⣿⣦⣆⡠⢀⣀⡸⠄⢀⠘⠤⢄⠀⠤⢄⢀⠀⠀⠀⠡⠜\n⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⢠⠀⠀⢠⣿⣏⠱⢾⡙⢏⠟⡥⢩⠛⣼⠷⢫⡹⡿⢟⢿⣛⡿⣿⣷⣦⣠⣤⡄⠀⠀⡄⠀⠀⡄⢠\n⠀⠀⠰⠀⢰⠒⠁⠈⠒⣶⣬⣶⣟⠻⡹⢾⣿⠻⠍⠆⠈⠄⡀⢩⢆⠙⡀⠇⣉⢾⡾⣵⣾⣿⣯⢿⣟⣿⣿⣶⠐⠁⠐⠒⠁⠈⠀\n⠀⠀⢀⠀⢀⠀⢂⣰⣟⠏⡿⣿⣟⣳⣕⣻⣦⢋⡔⠀⠁⠠⠐⠈⡌⠀⢠⠐⣊⠲⣱⢻⡾⣽⣻⢿⣾⢟⣿⣿⣿⣤⣄⡀⠆⠸⠀⠀\n⠀⠀⠈⠀⢰⣤⣶⣿⣯⣞⣽⣿⣛⢶⡺⣧⢆⣡⡀⠄⡁⠐⠤⢁⠢⢡⠄⣒⠦⢳⡡⣏⡖⢧⢫⢏⡜⣯⣿⣻⣽⢻⣿⣧⣄⣀⠀⠀⠀\n⠀⠠⢰⣶⠾⡟⡧⣿⢿⡿⣿⣽⣛⣶⣽⣯⣛⠤⣐⠈⡄⢩⠐⢂⡱⣠⢛⡴⢩⠳⣝⣭⢻⣭⡷⣎⣽⣽⣻⣷⢾⣩⣖⣿⡿⠋⠀⠀⠀\n⠀⠀⢀⣻⢮⡱⢻⣿⢯⣿⡙⡷⢻⡙⣾⣳⡿⣏⡙⣎⡐⡡⡜⢆⢧⡱⢎⠾⣥⢻⡼⣾⠻⡅⡛⡗⣿⢾⣻⣿⣟⣶⣿⣻⣷⡶⠀⠀⠀\n⠀⠨⢙⣿⣯⣷⡿⢇⠲⡅⠹⢈⠡⢏⡔⢫⣟⣾⣝⣦⣳⡱⣭⣞⢦⣝⢮⣻⡜⣧⣟⡹⠅⢀⠡⢙⠴⡻⢭⢓⡎⠗⣮⠿⣿⣦⡀⠀⠀\n⠀⢠⢭⡹⠬⣙⢳⡉⠂⢀⠐⠠⠑⡄⢬⢲⣹⣿⣿⣿⣷⣿⣷⣿⣷⣿⣿⣷⣹⣶⢏⡒⠀⠂⢀⠁⢊⠘⣇⠎⠘⡠⠃⡞⡥⠾⣧⡄⠀\n⢀⡸⡑⠆⠡⠐⢨⠚⠄⣀⠂⡅⢣⠼⣭⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⠀⢂⠀⠎⢠⠑⡈⠀⢂⠠⠑⠠⠜⡓⣎⣳⡦\n⡨⢒⠠⠀⡐⠈⡀⡘⠰⣠⢓⣬⢳⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⡐⠆⡨⠘⡀⠆⢀⠐⠀⡂⢌⡡⢆⣹⠴⣻⠀\n⠁⣇⠒⡁⠄⡠⢡⢈⣅⠲⣭⢾⣿⣿⣿⣿⣿⣿⣿⣿⡯⠿⢿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣽⣡⡗⣱⡜⡰⢂⠠⡑⡌⢀⡳⢍⣦⢻⣏⠁\n⠀⠗⣏⢄⢣⡔⣢⠝⣆⠷⣮⣷⣿⣿⣿⣿⣿⡿⠟⢿⣿⣶⣼⣿⡿⣧⣿⣿⠾⠛⢛⣿⣿⣿⣿⣿⣼⠱⣊⠶⡱⣍⢦⠹⣜⡸⢿⣅⠀\n⠀⢀⠙⠘⡯⣶⣿⣞⣿⣿⣾⣿⣿⣿⣿⣿⠛⣟⣆⠀⠙⣿⣿⣿⣿⣿⣿⠃⡆⠀⠀⣿⣿⣿⣿⣿⣷⣯⢧⣓⡳⡜⡶⣫⢼⣹⡧⠛⠁\n⠀⠀⠁⠀⠐⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠿⣿⣿⣆⠀⢸⣿⣿⣿⣿⡿⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣧⣿⣵⣫⡵⠯⠾⠽⠃⠀⠀\n⠀⠈⠈⠀⠸⠤⡀⠻⠿⠛⢙⠟⠟⠁⠧⠔⠀⠠⠍⠛⢿⣿⣿⣿⣿⣿⣇⣴⣾⣿⠟⢋⠉⠻⢿⣿⣿⣿⣿⡿⠿⡀⠠⠤⡀⢀⠀⠀⠀\n⠀⢀⠠⠀⢠⠀⠀⠘⠀⠀⠘⠀⠀⠀⡄⢀⠀⠄⠠⠁⠂⠹⣿⣿⣿⣿⣿⣿⠛⠀⠀⠜⠀⠀⠈⠀⠈⢈⠀⢠⠀⠁⠠⠀⠀⠘⠀⠀⠀\n⠀⠈⠀⠒⠂⠈⠒⢲⠀⠐⠲⠁⠐⠒⠁⠀⠒⠀⠈⠒⠎⠈⣿⣿⣿⣿⡟⠁⠐⠒⠀⢱⠒⠀⠰⠒⠊⠀⠒⠊⠈⠒⠂⠀⠖⢲⠀⠀⠀\n⠀⠐⠀⢀⡰⠀⢀⣀⠀⢀⣀⠄⢀⣀⠆⠐⢀⠀⠐⣀⡀⠀⣿⣿⣿⣿⣻⠀⠆⣀⠀⢀⣀⠀⢀⣀⡀⠀⠀⡐⠀⢀⡀⠀⣀⣀⠀⠀⠀\n⠀⢀⢀⠤⢄⠀⠄⠘⠀⠀⠌⡀⠀⠠⡀⢀⠠⠀⢀⠤⠀⠀⣿⣿⣿⣿⣿⠀⡀⠀⠀⡸⠀⠀⠈⠤⠀⢀⠀⢄⢀⠂⠄⠀⠁⠜⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠄⢠⠀⠀⢠⠂⠀⠀⠃⠀⠀⠀⠀⠀⡄⠀⣿⣿⣿⣿⣿⡀⠃⠀⠀⢠⠀⠀⢠⠀⠄⠀⠀⠀⠀⡄⠀⠀⡄⢠⠀⠀T\n⠀⢐⠰⠁⢐⠒⠀⠀⠂⠀⠈⠂⠀⠈⡆⠰⠀⠒⠐⠁⢐⢒⣿⣿⣿⣿⣿⡇⡎⠀⠂⡊⠀⠀⠂⠀⠑⠐⠁⢰⠐⠁⠐⠂⠀⠈⠀⠀R\n⠀⠀⢀⠀⢀⢀⠀⠸⠀⠀⠸⠀⠀⠀⡀⠀⠀⡀⢀⠂⠆⣸⣿⣿⣿⣿⣿⡇⡀⠀⡀⠸⠀⠀⢈⠀⠁⢀⠀⢀⢀⠃⢀⠀⠅⠸⠀⠀E\n⠀⠈⠀⠀⠘⠀⠀⢀⠀⠀⢠⠂⠀⠀⠃⠈⠀⠀⠐⠀⠀⣾⣿⣿⣿⣿⣿⣿⣀⠀⠀⢡⠀⠀⢀⠀⡀⠈⠀⠈⠀⡀⠀⠀⡀⢠⠀⠀E\n⠀⠠⢀⠒⢢⠀⠐⠊⠀⠐⠊⠄⠐⠒⡄⣀⣂⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣒⡀⠈⠒⠀⠀⠐⢢⠀⠑⠂⠀⠑⠈⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠐⠀⠀⠀⠁⠈⢀⠈⠉⡉⠍⠉⡏⠉⠉⠉⠉⠉⢉⠉⠀⢰⠁⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠐⠀⠀⠀\n";
	output.close();
}
