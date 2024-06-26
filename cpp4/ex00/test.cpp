/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:25:46 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 23:01:33 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Animal
{
	protected :
		std::string	type;
	public	:
		virtual void	makeSound()	const{
			std::cout<<"GGGGGRRRRR\n";
		}
		std::string	getType() const
		{
			return type;
		}
	//ORTHODOX FORMAT
		Animal() {
			std::cout<<"Animal default constructor called\n";
			type = "";
		}
		Animal(std::string type) {
			std::cout<<"Animal constructor with params called\n";
			this->type = type;
		}
		Animal(Animal const &original) {
			std::cout<<"Animal copy constructor called\n";
			type = original.type;
		}
		Animal	&operator=(Animal const &original) {
			std::cout<<"Animal copy assignment operator called\n";
			type = original.type;
			return *this;
		}
		virtual ~Animal() {
			std::cout<<"Animal (~"<<type<< "~) destructor called\n";
		}
};

class	Dog : public Animal {
	public	:
	//MEMBER FTS
		void	makeSound()	const{
			std::cout<<"Bark bark, wook woof, guau guau\n";
		}
	//ORTHODOX FORMAT
		Dog() {
			std::cout<<"Dog default constructor called\n";
			type = "Dog";
		}
		Dog(Dog const &original) {
			std::cout<<"Dog copy constructor called\n";
			type = original.type;
		}
		Dog	&operator=(Dog const &original) {
			std::cout<<"Dog copy assignment operator called\n";
			type = original.type;
			return *this;
		}
		virtual ~Dog() {
			std::cout<<"Dog destructor called\n";
		}

};

class	Cat : public Animal {
	public	:
	//MEMBER FTS
		void	makeSound()const{
			std::cout<<"mew miaaaaaeeeewwwwwwwwwwwwww\n";
		}
	//ORTHODOX FORMAT
		Cat() {
			std::cout<<"Cat default constructor called\n";
			type = "Cat";
		}
		Cat(Cat const &original) {
			std::cout<<"Cat copy constructor called\n";
			type = original.type;
		}
		Cat	&operator=(Cat const &original) {
			std::cout<<"Cat copy assignment operator called\n";
			type = original.type;
			return *this;
		}
		virtual ~Cat() {
			std::cout<<"Cat destructor called\n";
		}
};


class	WrongAnimal
{
	protected :
		std::string	type;
	public	:
		void	makeSound()	const{
			std::cout<<"I am defenitely not a cat and I clearly dont understand polymorphysm, can't even spell it\n";
		}
		std::string	getType() const
		{
			return type;
		}
	//ORTHODOX FORMAT
		WrongAnimal() {
			std::cout<<"WrongAnimal default constructor called\n";
			type = "";
		}
		WrongAnimal(std::string type) {
			std::cout<<"WrongAnimal constructor with params called\n";
			this->type = type;
		}
		WrongAnimal(WrongAnimal const &original) {
			std::cout<<"WrongAnimal copy constructor called\n";
			type = original.type;
		}
		WrongAnimal	&operator=(WrongAnimal const &original) {
			std::cout<<"WrongAnimal copy assignment operator called\n";
			type = original.type;
			return *this;
		}
		virtual ~WrongAnimal() {
			std::cout<<"WrongAnimal (~"<<type<< "~) destructor called\n";
		}
};

class	WrongCat : public WrongAnimal {
	public	:
	//MEMBER FTS
		void	makeSound()const{
			std::cout<<"mew miaaaaaeeeewwwwwwwwwwwwww\n";
		}
	//ORTHODOX FORMAT
		WrongCat() {
			std::cout<<"WrongCat default constructor called\n";
			type = "WrongCat";
		}
		WrongCat(WrongCat const &original) {
			std::cout<<"WrongCat copy constructor called\n";
			type = original.type;
		}
		WrongCat	&operator=(WrongCat const &original) {
			std::cout<<"WrongCat copy assignment operator called\n";
			type = original.type;
			return *this;
		}
		virtual ~WrongCat() {
			std::cout<<"WrongCat destructor called\n";
		}
};

int main()
{
const Animal* meta = new Animal("Animal hehe");
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wrongAnimal = new WrongAnimal("error animal");
const WrongAnimal* wrongCat = new WrongCat();

std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << wrongAnimal->getType() << " " << std::endl;
std::cout << wrongCat->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!*/
j->makeSound();
meta->makeSound();
wrongAnimal->makeSound();
wrongCat->makeSound();
delete meta;
delete j;
delete i;
delete wrongAnimal;
delete wrongCat;
}
