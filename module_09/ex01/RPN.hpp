#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>
#include <exception>
#include <algorithm>

class RPN {

    private:
        /* CONTAINER */
        std::stack<unsigned int>    operands;
        const std::string OPERATORS;

        /* PRIVATE METHODS */
        bool parseExpression(const std::string &expression);

    public:
        /* CONSTRUCTORS */
        RPN(); // basic constructor
        RPN(const std::string &expression);
        RPN(const RPN &other); // copy constructor

        /* DESTRUCTOR */
        ~RPN(); // basic destructor

        /* OPERATORS */
        RPN& operator=(const RPN &other); // assignment operator


        /* PUBLIC METHODS */
        int  process(const std::string &expression);

};

#endif