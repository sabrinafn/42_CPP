#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

    public: 
        /* CONSTRUCTORS */
        MutantStack(void) {}
        MutantStack(const MutantStack& other) { *this = other; }

        /* DESTRUCTOR */
        ~MutantStack(void) {}

        /* OPERATORS */
        // copy assignment
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T>::operator=(other); // using base class
            return *this; }

        /* ITERATOR */  

        // std::stack<T>::container_type == std::deque<T>
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        // c = container inside of std::stack
        iterator begin() {
            return this->c.begin();}
        iterator end() {
            return this->c.end();}

        const_iterator begin() const {
            return this->c.begin();}
        const_iterator end() const {
            return this->c.end();}
};

// insertion operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T> &other) {

    // compiler needs typename to identify that the iterator is a type of var
    typename MutantStack<T>::const_iterator it = other.begin(); // able to access begin()
    typename MutantStack<T>::const_iterator ite = other.end(); // and end()

    os << "Mutant Stack: { ";
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

#endif