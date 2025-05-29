#include "Base.hpp"

int main() {

    std::cout << "=== Generating 10 Bases randomically ===\n" << std::endl;
    Base* random = NULL;
    for (int i = 0; i < 10; i++) {
        std::cout << "= " << i + 1 << " ========================" << std::endl;
        random = generate();

        std::cout << "Type of object pointed:    ";
        identify(random);
        std::cout << "Type of object referenced: ";
        identify(*random);

        std::cout << "=============================" << std::endl;
        delete random;
    }
    return 0;
}
