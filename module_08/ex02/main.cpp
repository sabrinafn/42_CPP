#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << "adding 5 to the stack" << std::endl;
    mstack.push(5);
    std::cout << "adding 17 to the stack\n" << std::endl;
    mstack.push(17);
    std::cout << "printing value at the top: ";
    std::cout << mstack.top() << std::endl;
    std::cout << "removing value at the top" << std::endl;
    mstack.pop();
    std::cout << "printing stack size: ";
    std::cout << mstack.size() << std::endl;

    std::cout << "\nadding 3 to the stack" << std::endl;
    mstack.push(3);
    std::cout << "adding 5 to the stack" << std::endl;
    mstack.push(5);
    std::cout << "adding 737 to the stack" << std::endl;
    mstack.push(737);
    //[...]
    std::cout << "adding 0 to the stack" << std::endl;
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "\nprinting whole stack: ";
    std::cout << "{ ";
    while (it != ite)
    {
        std::cout << *it << "  ";
        ++it;
    }
    std::cout << "}";
    std::stack<int> s(mstack);
    return 0;
}