#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {

    Base* random = generate();

    identify(random);
    identify(random);

    delete random;
    return 0;
}
