#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <algorithm>

class RPN {

    private:
        /* CONTAINER */
        std::stack<int>     numbers_stack;

        /* CONST */
        const std::string   OPERATORS;

        /* PRIVATE METHODS */
        void    parseExpression(const std::string &expression);
        int     strToInt(const std::string &str) const;

    public:
        /* CONSTRUCTORS */
        RPN(); // basic constructor
        RPN(const RPN &other); // copy constructor

        /* DESTRUCTOR */
        ~RPN(); // basic destructor

        /* OPERATORS */
        RPN& operator=(const RPN &other); // assignment operator

        /* PUBLIC METHODS */
        int  process(const std::string &expression);
};

#endif