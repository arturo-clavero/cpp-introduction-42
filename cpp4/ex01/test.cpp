/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:02:32 by arturo            #+#    #+#             */
/*   Updated: 2024/06/26 23:25:32 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class	Brain{
	private :
		std::string	ideas[100];
	public :
	//ORTHODOX FORMAT
		Brain(){
			std::cout<<"Brain default constructor called\n";
			for (int i = 0; i < 100; i++)
				ideas[i] = "";
		}
		Brain(Brain const &original){
			std::cout<<"Brain copy constructor called\n";
			for (int i = 0; i < 100; i++)
				ideas[i] = original.ideas[i];
		}
		Brain	&operator=(Brain const &original){
			std::cout<<"Brain copy assignment operator called\n";
			for (int i = 0; i < 100; i++)
				ideas[i] = original.ideas[i];
			return *this;
		}
		~Brain() {
			std::cout<<"Brain destructor called\n";
		}
};

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
	private:
		Brain *local_brain;
	public	:
	//MEMBER FTS
		void	makeSound()	const{
			std::cout<<"Bark bark, wook woof, guau guau\n";
		}
	//ORTHODOX FORMAT
		Dog() {
			std::cout<<"Dog default constructor called\n";
			type = "Dog";
			local_brain = new Brain();
		}
		Dog(Dog const &original) {
			std::cout<<"Dog copy constructor called\n";
			type = original.type;
			local_brain = new Brain(*original.local_brain);
		}
		Dog	&operator=(Dog const &original) {
			std::cout<<"Dog copy assignment operator called\n";
			type = original.type;
			delete local_brain;
			local_brain = new Brain(*original.local_brain);
			return *this;
		}
		virtual ~Dog() {
			std::cout<<"Dog destructor called\n";
			delete local_brain;
		}

};

class	Cat : public Animal {
	private:
		Brain *local_brain;
	public	:
	//MEMBER FTS
		void	makeSound()const{
			std::cout<<"mew miaaaaaeeeewwwwwwwwwwwwww\n";
		}
	//ORTHODOX FORMAT
		Cat() {
			std::cout<<"Cat default constructor called\n";
			type = "Cat";
			local_brain = new Brain();
		}
		Cat(Cat const &original) {
			std::cout<<"Cat copy constructor called\n";
			type = original.type;
			local_brain = new Brain(*original.local_brain);
		}
		Cat	&operator=(Cat const &original) {
			std::cout<<"Cat copy assignment operator called\n";
			type = original.type;
			delete local_brain;
			local_brain = new Brain(*original.local_brain);
			return *this;
		}
		virtual ~Cat() {
			std::cout<<"Cat destructor called\n";
			delete local_brain;
		}
};

/*Implement a Brain class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.*/



int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
return (0);
}
	
