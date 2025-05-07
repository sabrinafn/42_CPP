#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

//int main()
//{
//    IMateriaSource* src = new MateriaSource();
//    src->learnMateria(new Ice());
//    src->learnMateria(new Cure());
//    ICharacter* me = new Character("me");
//    AMateria* tmp;
//    tmp = src->createMateria("Ice");
//    me->equip(tmp);
//    tmp = src->createMateria("Cure");
//    me->equip(tmp);
//    ICharacter* bob = new Character("bob");
//    me->use(0, *bob);
//    me->use(1, *bob);
//    delete bob;
//    delete me;
//    delete src;
//
//    return 0;
//}

int main() {
    std::cout << "--- Creating MateriaSource and learning Materia ---" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice()); // Exceeds capacity

    std::cout << "\n--- Creating Characters ---" << std::endl;
    Character hero("Hero");
    Character villain("Villain");

    std::cout << "\n--- Creating Materia and equipping Hero ---" << std::endl;
    AMateria* ice1 = src.createMateria("Ice");
    AMateria* cure1 = src.createMateria("Cure");
    AMateria* ice2 = src.createMateria("Ice");
    AMateria* cure2 = src.createMateria("Cure");

    hero.equip(ice1);
    hero.equip(cure1);
    hero.equip(ice2);
    hero.equip(cure2);
    hero.equip(new Ice()); // Inventory full

    std::cout << "\n--- Using Materia ---" << std::endl;
    hero.use(0, villain);
    hero.use(1, villain);
    hero.use(2, villain);
    hero.use(3, villain);
    hero.use(4, villain); // Invalid slot

    std::cout << "\n--- Unequipping Materia ---" << std::endl;
    hero.unequip(1);
    hero.use(1, villain); // Should do nothing

    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    Character copyHero = hero;
    copyHero.use(0, villain);
    copyHero.use(1, villain);

    std::cout << "\n--- Destructor Calls ---" << std::endl;
    return 0;
}
