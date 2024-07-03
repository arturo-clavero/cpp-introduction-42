/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturo <arturo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:02 by arturo            #+#    #+#             */
/*   Updated: 2024/07/03 14:52:27 by arturo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	subjectTest()
{
	std::cout<<"//////////////////////////////\nSubject test:\n\n";
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

void	baseConstructionDestruction()
{
	std::cout<<"\n////////////////////////////////\nTESTING CONSTRUCTION AND DESTRUCTION OF BASE CLASS\n";
	std::cout<<"\n\t 1.Initiating animal class (no type):\n";
	Animal animal;
	std::cout<<"\n\t 2.Call member function make sound:\n";
	animal.makeSound();
	std::cout<<"\n\t 3.Automatic destruction (object out of scope):\n";
}

void	baseConstructionDestructionHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING CONSTRUCTION AND DESTRUCTION OF BASE CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1.Alloc animal class (type random):\n";
	Animal *animal = new Animal("random");
	std::cout<<"\n\t 2.Call member function make sound:\n";
	animal->makeSound();
	std::cout<<"\n\t 3.Explicit destruction:\n";
	delete animal;
}
void	baseCopyConstructor()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY CONSTRUCTOR OF BASE CLASS\n";
	std::cout<<"\n\t 1. Initiating animalOne object (type 'gorilla'):\n";
	Animal animalOne("gorilla");
	std::cout<<"\n\t 2. Initiating animalTwo object with previous animalOne object:\n";
	Animal animalTwo(animalOne);
	std::cout<<"\n\t 3. Getting type for animalONe:\n";
	std::cout<<animalOne.getType()<<"\n";
	std::cout<<"\n\t 4. Getting type for animalTwo (since this object was copied it should be the same):\n";
	std::cout<<animalTwo.getType()<<"\n";
	std::cout<<"\n\t 5. Automatic destruction of both objects:\n";
}
void	baseCopyConstructorHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY CONSTRUCTOR OF BASE CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1. Alloc animalOne object (type 'gorilla'):\n";
	Animal *animalOne = new Animal("gorilla");
	std::cout<<"\n\t 2. Alloc animalTwo object with previous animalOne object:\n";
	Animal *animalTwo = new Animal(*animalOne);
	std::cout<<"\n\t 3. Getting type for animalONe:\n";
	std::cout<<animalOne->getType()<<"\n";
	std::cout<<"\n\t 4. Getting type for animalTwo (since this object was copied it should be the same):\n";
	std::cout<<animalTwo->getType()<<"\n";
	std::cout<<"\n\t 5. Explicit destruction of animalOne:\n";
	delete animalOne;
	std::cout<<"\n\t 6. Explicit destruction of animalTwo:\n";
	delete animalTwo;
}

void	baseCopyAssignmentOperator()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY ASSIGNMENT OPERATOR OF BASE CLASS\n";
	std::cout<<"\n\t 1. Initiating animalOne object (type 'gorilla'):\n";
	Animal *animalOne = new Animal("gorilla");
	std::cout<<"\n\t 2. Initiating animalTwo object (type 'snake'):\n";
	Animal *animalTwo = new Animal("snake");
	std::cout<<"\n\t 3. Getting type for animalONe:\n";
	std::cout<<animalOne->getType()<<"\n";
	std::cout<<"\n\t 4. Getting type for animalTwo:\n";
	std::cout<<animalTwo->getType()<<"\n";
	std::cout<<"\n\t 5. Copying animalOne object to animalTwo\n";
	*animalTwo = *animalOne;
	std::cout<<"\n\t 6. Getting type for animalONe:\n";
	std::cout<<animalOne->getType()<<"\n";
	std::cout<<"\n\t 7. Getting type for animalTwo:\n";
	std::cout<<animalTwo->getType()<<"\n";
	std::cout<<"\n\t 8. Explicit destruction of animalOne:\n";
	delete animalOne;
	std::cout<<"\n\t 8. Explicit destruction of animalTwo:\n";
	delete animalTwo;
}
void	baseCopyAssignmentOperatorHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY ASSIGNMENT OPERATOR OF BASE CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1. Allocating animalOne object (type 'gorilla'):\n";
	Animal animalOne("gorilla");
	std::cout<<"\n\t 2. Allocating animalTwo object (type 'snake'):\n";
	Animal animalTwo("snake");
	std::cout<<"\n\t 3. Getting type for animalONe:\n";
	std::cout<<animalOne.getType()<<"\n";
	std::cout<<"\n\t 4. Getting type for animalTwo:\n";
	std::cout<<animalTwo.getType()<<"\n";
	std::cout<<"\n\t 5. Copying animalOne object to animalTwo\n";
	animalTwo = animalOne;
	std::cout<<"\n\t 6. Getting type for animalONe:\n";
	std::cout<<animalOne.getType()<<"\n";
	std::cout<<"\n\t 7. Getting type for animalTwo:\n";
	std::cout<<animalTwo.getType()<<"\n";
	std::cout<<"\n\t 8. Automatic destruction of both objects:\n";

}

void	derivedConstructionDestruction()
{
	std::cout<<"\n////////////////////////////////\nTESTING CONSTRUCTOR AND DESTRUCTOR OF DERIVED CLASS \n";
	std::cout<<"\n\t 1. Initialize Dog object\n";
	Dog	dog;
	std::cout<<"\n\t 2. Initialize Cat object\n";
	Cat cat;
	std::cout<<"\n\t 3. Dog make sound member function called\n";
	dog.makeSound();
	std::cout<<"\n\t 4. Cat make sound member function called\n";
	cat.makeSound();
	std::cout<<"\n\t 5. Automatic destruction of objects\n";
}
void	derivedConstructionDestructionHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING CONSTRUCTOR AND DESTRUCTOR OF DERIVED CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1. Alloc Dog object\n";
	Dog	*dog = new Dog();
	std::cout<<"\n\t 2. Alloc Cat object\n";
	Cat *cat = new Cat();
	std::cout<<"\n\t 3. Dog type\n";
	std::cout<<dog->getType()<<"\n";
	std::cout<<"\n\t 4. Cat type\n";
	std::cout<<cat->getType()<<"\n";
	std::cout<<"\n\t 5. Explicit destruction of dog\n";
	delete dog;
	std::cout<<"\n\t 5. Explicit destruction of cat\n";
	delete cat;
}

void	derivedCopyConstructor()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY CONSTRUCTOR OF DERIVED CLASS\n";
	std::cout<<"\n\t 1. Initialize dog object\n";
	Dog	dog;
	std::cout<<"\n\t 2. Initialize otherDog object with previous dog object\n";
	Dog otherDog(dog);
	std::cout<<"\n\t 3. Automatic destruction of objects\n";
}

void	derivedCopyConstructorHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY CONSTRUCTOR OF DERIVED CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1. Alloc cat object\n";
	Cat	*cat = new Cat();
	std::cout<<"\n\t 2. Alloc otherCat object with previous cat object\n";
	Cat *otherCat = new Cat(*cat);
	std::cout<<"\n\t 3. Explicit destruction of cat\n";
	delete cat;
	std::cout<<"\n\t 4. Explicit destruction of otherCat\n";
	delete otherCat;
}

void	derivedCopyAssignmentOperator()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY ASSIGNMENT OPERATOR OF DERIVED CLASS\n";
	std::cout<<"\n\t 1. Initialize dog object\n";
	Dog	dog;
	std::cout<<"\n\t 2. Initialize otherDog object\n";
	Dog otherDog;
	std::cout<<"\n\t 3. Copy dog to otherDog\n";
	otherDog = dog;
	std::cout<<"\n\t 3. Automatic destruction of objects\n";
}

void	derivedCopyAssignmentOperatorHeap()
{
	std::cout<<"\n////////////////////////////////\nTESTING COPY ASSIGNMENT OPERATOR OF DERIVED CLASS WITH HEAP MEM\n";
	std::cout<<"\n\t 1. Alloc cat object\n";
	Cat	*cat = new Cat();
	std::cout<<"\n\t 2. Alloc otherCat object\n";
	Cat *otherCat = new Cat();
	std::cout<<"\n\t 3. Copy cat to otherCat\n";
	*otherCat = *cat;
	std::cout<<"\n\t 3. Explicit destruction of cat\n";
	delete cat;
	std::cout<<"\n\t 4. Explicit destruction of otherCat\n";
	delete otherCat;
}

void	checkBaseClass()
{
	baseConstructionDestruction();
	baseConstructionDestructionHeap();
	baseCopyConstructor();
	baseCopyConstructorHeap();
	baseCopyAssignmentOperator();
	baseCopyAssignmentOperatorHeap();
}

void	checkDerivedClass()
{
	derivedConstructionDestruction();
	derivedConstructionDestructionHeap();
	derivedCopyConstructor();
	derivedCopyConstructorHeap();
	derivedCopyAssignmentOperator();
	derivedCopyAssignmentOperatorHeap();
}

void	checkVirtualFts()
{
	std::cout<<"Our base and derived classes all have a member function 'makeSound'\n";
	std::cout<<"Each class shows different behavior, let's see it\n\n";
	std::cout<<"\n\t 1. Creating an object 'base' from base class Animal:\n";
	Animal	base("snake");
	std::cout<<"\n\t 1. Creating an object 'derivedCat' from derived class Cat:\n";
	Animal *derivedCat = new Cat();
	std::cout<<"\n\t 1. Creating an object 'derivedDog' from derived class Dog:\n";
	Animal *derivedDog = new Dog();
	std::cout<<"\n\t 2. Lets call makeSound of base, derivedCat, and derivedDog:\n";
	base.makeSound();
	derivedCat->makeSound();
	derivedDog->makeSound();
	std::cout<<"\n\t We can see that all the sounds are different. This is because the base class's makeSound is virtual\n";
	std::cout<<"Let's repeat the same process with a base class WrongAnimal and a derived class WrongCat.\n These are identical to the Animal and Cat classes except that the base class's makeSound function is NOT virtual\n\n";
	std::cout<<"\n\t 1. Creating an object 'wrongBase' from base class WrongAnimal:\n";
	WrongAnimal	wrongBase("snake");
	std::cout<<"\n\t 1. Creating an object 'wrongDerivedCat' from derived class WrongCat:\n";
	WrongAnimal *wrongDerivedCat = new WrongCat();
	std::cout<<"\n\t 2. Lets call makeSound of wrongBase, wrongDerivedCat:\n";
	wrongBase.makeSound();
	wrongDerivedCat->makeSound();
	std::cout<<"\n Look at that, we have the same output, the wrongDerivedCat is calling its base class function instead of its own\nWhen a base class function is virtual, it will allow derived class's implementations of the same function to be called otherwise we get this wrong behavior like here\n";
	std::cout<<"\n Note that this only happens when creating instances of non abstract base classes pointing to a derived class. Virtual fts are not needed for an instance of a derived class to call its own member function.\n\n Now all derived objects will be explicitely destroyed...\n\n";
	delete derivedCat;
	delete derivedDog;
	delete wrongDerivedCat;
	std::cout<<"\n Now all base objects will be autoamtically destroyed...\n\n";
}
	
int main()
{
	checkBaseClass();
	checkDerivedClass();
	checkVirtualFts();
	subjectTest();
}