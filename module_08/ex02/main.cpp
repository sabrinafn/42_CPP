#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << "adding 5 to the stack" << std::endl;
    mstack.push(5);
    std::cout << "adding 17 to the stack\n" << std::endl;
    mstack.push(17);

    std::cout << mstack << std::endl;

    std::cout << "\nprinting value at the top: ";
    std::cout << mstack.top() << std::endl;

    std::cout << "removing value at the top: 17" << std::endl;
    mstack.pop();

    std::cout << "printing stack size: ";
    std::cout << mstack.size() << std::endl;

    std::cout << "\nadding 3 to the stack" << std::endl;
    mstack.push(3);
    std::cout << "adding 5 to the stack" << std::endl;
    mstack.push(5);
    std::cout << "adding 737 to the stack" << std::endl;
    mstack.push(737);
    std::cout << "adding 0 to the stack\n" << std::endl;
    mstack.push(0);

    std::cout << mstack << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "\niterator stack.begin(): " << *it << std::endl;
    std::cout << "iterator stack.end(): " << *ite << std::endl;

    ++it;
    std::cout << "after incrementing iterator stack.begin(): " << *it << std::endl;
    --it;
    std::cout << "after decrementing iterator stack.begin(): " << *it << std::endl;

    std::cout << '\n' << mstack << std::endl;
    std::stack<int> s(mstack);
    return 0;
}