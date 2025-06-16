#include "MutantStack.hpp"
#include <list>

// insertion operator for std::list example
std::ostream& operator<<(std::ostream& os, std::list<std::string> &other) {

    std::list<std::string>::iterator it = other.begin();
    std::list<std::string>::iterator ite = other.end();

    os << "iterators list: { ";
    while (it != ite)
    {
        os << *it;
        it++;
        if (it != ite)
            os << ", ";
    }
    os << " }";
    return os;
}

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

        std::cout << "\nprinting and removing value at the top: ";
        std::cout << mstack.top() << std::endl;
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
        
        // copying mutantstack back into base class stack, then it loses its ability to iterate
        std::stack<int> s(mstack);

        //std::stack::iterator s_it = s.begin();
        //std::stack::iterator s_ite = s.end();
        //std::cout << "\niterator s.begin(): " << *s_it << std::endl;
        //s_ite--;
        //std::cout << "iterator s.end(): " << *s_ite << std::endl; // points to one before last
        //s_ite++;
        
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

        std::cout << "\nprinting and removing value at the top: ";
        std::cout << str.top() << std::endl;
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
    }
            std::cout << "=============================================================" << std::endl;
    {
        std::list<std::string> str;
        std::cout << str << '\n' << std::endl;
        std::cout << "adding watermelon to the stack" << std::endl;
        str.push_back("watermelon");
        std::cout << "adding hello world to the stack\n" << std::endl;
        str.push_back("hello world");

        std::cout << str << std::endl;

        std::cout << "\nprinting and removing value at the top: ";
        std::cout << str.back() << std::endl;
        str.pop_back();

        std::cout << "printing stack size: ";
        std::cout << str.size() << std::endl;

        std::cout << "\nadding apple to the stack" << std::endl;
        str.push_back("apple");
        std::cout << "adding banana to the stack" << std::endl;
        str.push_back("banana");
        std::cout << "adding grape to the stack" << std::endl;
        str.push_back("grape");
        std::cout << "adding orange to the stack\n" << std::endl;
        str.push_back("orange");

        std::cout << str << std::endl;
        std::list<std::string>::iterator it = str.begin();
        std::list<std::string>::iterator ite = str.end(); // points to one before last

        std::cout << "\niterator stack.begin(): " << *it << std::endl;
        ite--;
        std::cout << "iterator stack.end(): " << *ite << std::endl;
        ite++;

        it++;
        std::cout << "after incrementing iterator stack.begin(): " << *it << std::endl;
        it--;
        std::cout << "after decrementing iterator stack.begin(): " << *it << std::endl;

        std::cout << '\n' << str << std::endl;
    }
    return 0;
}