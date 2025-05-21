#include "ShrubberyCreationForm.hpp"

// constructor
ShrubberyCreationForm::ShrubberyCreationForm() : target("empty") {}

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
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : target(target) {} 
    
void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw Aform::GradeTooLowException();
    }
    
    std::string filename = this->target + "_shrubbery";
    std::ofstream output(filename.c_str());
    
    if (output.is_open()) {
        drawTrees(output);
        output.close();
        std::cout << "File " << filename << " created and written to successfully.\n" << std::endl;
    }
    else {
        std::cerr << "error opening file " << filename << "for writing" << std::endl;
    }
}

void    ShrubberyCreationForm::drawTrees(std::ofstream output) {

    output << "                   ,@@@@@@@,/n"
    << "       ,,,.   ,@@@@@@/@@,  .oo8888o./n"
    << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o/n"
    << "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'/n"
    << "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'/n"
    << "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'/n"
    << "   `&%\ ` /%&'    |.|        \ '|8'/n"
    << "       |o|        | |         | |/n"
    << "       |.|        | |         | |/n"
    << "jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_/n"
}