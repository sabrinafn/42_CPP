#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

// template is for this: when a container is created, I need to
// add the type of variable it will be
//      std::vector<int>
//      std::deque<char>
//      std::stack<string>

template<typename T>
class MutantStack : public std::stack<T> {

    public: 
        /* CONSTRUCTORS */
        MutantStack(void) {} // constructor
        MutantStack(const MutantStack& other) { *this = other; } // copy constructor

        /* DESTRUCTOR */
        ~MutantStack(void) {} // destructor

        /* OPERATORS */
        // copy assignment operator
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T>::operator=(other); // using base class assignment operator
            return *this;
        }

        // declaring iterator 
        // std::stack<T>::container_type == std::deque<T>
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        // this is almost the same as this:
        //typedef typename std::deque<T>::iterator iterator;


        // c = object holding elements inside of std::stack
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

    // compiler needs typename to identify that iterator is a type
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