#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe {

    private:

    public:
        /* CONSTRUCTORS */
        PmergeMe();
        PmergeMe(const PmergeMe &other);

        /* DESTRUCTORS */
        ~PmergeMe();

        /* OPERATORS */
        PmergeMe& operator=(const PmergeMe &other);
        
};

#endif