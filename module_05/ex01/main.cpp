#include "Bureaucrat.hpp"
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    // Valid form
    std::cout << "===== Creating a valid form... =====\n" << std::endl;
    Form* validForm = NULL;
    try {
        validForm = new Form("ValidForm", 50, 30);
        std::cout << *validForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to create validForm: " << e.what() << std::endl;
    }
    delete validForm;
    validForm = NULL;

    // Too high grade to sign
    std::cout << "===== Creating invalid forms... =====\n" << std::endl;
    std::cout << "=== Form with a grade 0 to sign." << std::endl;

    Form* badForm = NULL;
    try {
        badForm = new Form("TooHighToSign", 0, 50);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete badForm;
    badForm = NULL;

    // Too low grade to execute
    std::cout << "=== Form with a grade 200 to execute." << std::endl;
    Form* invalidForm = NULL;
    try {
        invalidForm = new Form("TooLowToExecute", 100, 200);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete invalidForm;
    invalidForm = NULL;


    std::cout << "\n===== Creating valid bureaucrats to sign a valid form... =====\n" << std::endl;

    std::cout << "=== Bureaucrat grade matches Form's requirements.\n" << std::endl;

    Bureaucrat* Alice = NULL;
    Form* form_one = NULL;
    // Signing with high enough grade
    try {
        Alice = new Bureaucrat("Alice", 30);
        std::cout << *Alice << "\n" << std::endl;
        form_one = new Form("THIS_IS_A_FORM", 50, 50);
        std::cout << *form_one << std::endl;
        form_one->beSigned(*Alice);
        std::cout << "Form signed successfully by " << Alice->getName() << std::endl;
        std::cout << *form_one << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete Alice;
    delete form_one;


    std::cout << "\n=== Bureaucrat grade does not match Form's requirements.\n" << std::endl;

    Bureaucrat* Bob = NULL;
    Form* form_two = NULL;
    // Attempt to sign with low grade
    try {
        Bob = new Bureaucrat("Bob", 100);
        std::cout << *Bob << "\n" <<std::endl;
        form_two = new Form("HELLO_I_AM_A_FORM", 90, 100);
        std::cout << *form_two << std::endl;
        form_two->beSigned(*Bob);
        std::cout << "Form signed successfully by " << Bob->getName() << std::endl;
        std::cout << *form_two << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    delete Bob;
    delete form_two;

    return 0;
}
