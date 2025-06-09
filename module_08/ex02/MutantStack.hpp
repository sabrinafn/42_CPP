#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

// template is for this: when a container is created, I need to
// add the type of variable it will be
// like std::vector<int>
//      std::deque<char>
//      std::stack<string>

template<typename T>
class MutantStack : public std::stack<T> {

    public: 
        /* CONSTRUCTORS */
        MutantStack(void) {} // constructor
        MutantStack(const MutantStack& other) {
            *this = other;
        } // copy constructor

        /* DESTRUCTOR */
        ~MutantStack(void) {} // destructor

        /* OPERATORS */
        // copy assignment operator
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T>::operator=(other); // using base class assignment operator
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        // c = container interno de std::stack
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

// insertion operator
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T> &other) {

    MutantStack<int>::iterator it = other.begin(); // able to access begin()
    MutantStack<int>::iterator ite = other.end(); // and end()

    os << "Mutant Stack: { ";
    while (it != ite)
    {
        os << *it;
        if (it != ite - 1)
            os << ", ";
        it++;
    }
    os << " }";
    return os;
}

#endif