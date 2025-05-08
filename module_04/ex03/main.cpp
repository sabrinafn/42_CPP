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
    std::cout << "====== Creating MateriaSource and learning Materia ======" << std::endl;
    MateriaSource src;
    AMateria* first = new Ice();
    AMateria* second = new Cure();
    src.learnMateria(first);
    src.learnMateria(second);
    delete(first);
    delete(second);

    std::cout << "\n====== Creating Characters ======" << std::endl;
    Character hero("Hero");
    Character villain("Villain");

    std::cout << "\n====== Creating Materia and equipping Hero ======" << std::endl;
    AMateria* ice1 = src.createMateria("Ice");
    AMateria* cure1 = src.createMateria("Cure");

    if (ice1) hero.equip(ice1);
    if (cure1) hero.equip(cure1);

    std::cout << "\n====== Using Materia ======" << std::endl;
    hero.use(0, villain);
    hero.use(1, villain);

    std::cout << "\n====== Unequipping Materia ======" << std::endl;
    hero.unequip(0);  // `ice1` is now unequipped, but not deleted
    hero.unequip(1);  // `cure1` is now unequipped, but not deleted

    std::cout << "\n====== Manually Deleting Unequipped Materia ======" << std::endl;
    // manually delete since unequip does not delete
    delete ice1; 
    delete cure1;

    std::cout << "\n====== Testing Deep Copy ======" << std::endl;
    Character copyHero = hero;
    copyHero.use(0, villain); // Should do nothing as ice1 was unequipped
    copyHero.use(1, villain); // Should do nothing as cure1 was unequipped

    return 0;
}