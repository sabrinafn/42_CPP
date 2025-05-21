#include "ShrubberyCreationForm.hpp"

// constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), target("empty") {}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
    *this = other;
} 

// copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        this->target = other.target;
    }
    return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// constructor takes parameters
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {} 

void    ShrubberyCreationForm::action() const {
    std::string filename = this->target + "_shrubbery";
    std::ofstream output(filename.c_str());
    
    if (output.is_open()) {
        drawTrees(output);
        output.close();
        std::cout << "File " << filename << " created and written to successfully." << std::endl;
    }
    else {
        std::cerr << "Error opening file " << filename << " for writing." << std::endl;
    }
}

void    ShrubberyCreationForm::drawTrees(std::ofstream &output) const{

    output << "      /\\      \n"
           << "     /\\/\\     \n"
           << "    /\\/\\/\\    \n"
           << "   /\\/\\/\\/\\   \n"
           << "  /\\/\\/\\/\\/\\  \n"
           << " /\\/\\/\\/\\/\\/\\ \n"
           << "/\\/\\/\\/\\/\\/\\/\\\n"
           << "      ||      \n"
           << "      ||      \n"
           << "      ||";
}