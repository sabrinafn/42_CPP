#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {

    // Valid AForm
    std::cout << "===== Creating a valid Form... =====\n" << std::endl;
    try {
        AForm validForm("Valid Form", 50, 30);
        std::cout << validForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to create valid Form: " << e.what() << std::endl;
    }

    // Too high grade to sign
    std::cout << "===== Creating invalid Forms... =====\n" << std::endl;
    std::cout << "=== Form with a grade 0 to sign." << std::endl;
    try {
        AForm badForm("TooHighToSign", 0, 50);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Too low grade to execute
    std::cout << "=== Form with a grade 200 to execute." << std::endl;
    try {
        AForm invalidForm("TooLowToExecute", 100, 200);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Creating valid bureaucrats to sign a valid Form... =====\n" << std::endl;

    std::cout << "=== Bureaucrat grade matches Form's requirements.\n" << std::endl;

    Bureaucrat Alice("Alice", 30);
    std::cout << Alice << "\n" << std::endl;

    AForm AForm_one("THIS_IS_A_FORM", 50, 50);
    std::cout << AForm_one << std::endl;

    // Signing with high enough grade
    try {
        AForm_one.beSigned(Alice);
        std::cout << "Form signed successfully by " << Alice.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat grade does not match Form's requirements.\n" << std::endl;

    Bureaucrat Bob("Bob", 100);
    std::cout << Bob << "\n" <<std::endl;

    // Attempt to sign with low grade
    AForm AForm_two("HELLO_I_AM_A_FORM", 90, 100);
    try {
        AForm_two.beSigned(Bob);
        std::cout << "Form signed successfully by " << Bob.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== FINAL FORM STATES ====\n" << std::endl;
    std::cout << AForm_one << std::endl;
    std::cout << AForm_two << std::endl;

    return 0;
}
