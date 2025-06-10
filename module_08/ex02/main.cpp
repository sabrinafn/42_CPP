#include "MutantStack.hpp"

int main()
{
    {
        MutantStack<int> mstack;
        std::cout << mstack << '\n' << std::endl;
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
        ite--;
        std::cout << "iterator stack.end(): " << *ite << std::endl; // points to one before last
        ite++;

        it++;
        std::cout << "after incrementing iterator stack.begin(): " << *it << std::endl;
        it--;
        std::cout << "after decrementing iterator stack.begin(): " << *it << std::endl;

        std::cout << '\n' << mstack << std::endl;
        
        std::stack<int> s(mstack);

        //std::cout << s << std::endl;
        //MutantStack<int>::iterator it = s.begin();
        //MutantStack<int>::iterator ite = s.end();
//
        //std::cout << "\niterator stack.begin(): " << *it << std::endl;
        //ite--;
        //std::cout << "iterator stack.end(): " << *ite << std::endl; // points to one before last
        //ite++;
        
    }
        std::cout << "=============================================================" << std::endl;
    {
        MutantStack<std::string> str;
        std::cout << str << '\n' << std::endl;
        std::cout << "adding watermelon to the stack" << std::endl;
        str.push("watermelon");
        std::cout << "adding hello world to the stack\n" << std::endl;
        str.push("hello world");

        std::cout << str << std::endl;

        std::cout << "\nprinting value at the top: ";
        std::cout << str.top() << std::endl;

        std::cout << "removing value at the top: hello world" << std::endl;
        str.pop();

        std::cout << "printing stack size: ";
        std::cout << str.size() << std::endl;

        std::cout << "\nadding apple to the stack" << std::endl;
        str.push("apple");
        std::cout << "adding banana to the stack" << std::endl;
        str.push("banana");
        std::cout << "adding grape to the stack" << std::endl;
        str.push("grape");
        std::cout << "adding orange to the stack\n" << std::endl;
        str.push("orange");

        std::cout << str << std::endl;
        MutantStack<std::string>::iterator it = str.begin();
        MutantStack<std::string>::iterator ite = str.end(); // points to one before last

        std::cout << "\niterator stack.begin(): " << *it << std::endl;
        ite--;
        std::cout << "iterator stack.end(): " << *ite << std::endl;
        ite++;

        it++;
        std::cout << "after incrementing iterator stack.begin(): " << *it << std::endl;
        it--;
        std::cout << "after decrementing iterator stack.begin(): " << *it << std::endl;

        std::cout << '\n' << str << std::endl;
        std::stack<std::string> s(str);

    }
    return 0;
}