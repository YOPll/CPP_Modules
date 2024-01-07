#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* animal = new Animal();
    const Animal* kitty = new Dog();

    const Animal* dog = new Cat();

    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << kitty->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    kitty->makeSound();
    dog->makeSound();
    animal->makeSound();
    wrongCat->makeSound();

    delete animal;
    delete dog;
    delete kitty;
    delete wrongCat;

    return (0);
}