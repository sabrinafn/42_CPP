#include "Harl.hpp"

void    Harl::debug(void) {

    std::cout << "Checked the egg carton; 6 large eggs remaining."
    << " Expiration date is next week, so they should be good."
    << " Retrieved whisk and a clean bowl. Intending to scramble"
    << " two eggs with a splash of milk." << std::endl;
}

void    Harl::info(void) {

    std::cout << "Initiating egg preparation sequence. Step 1: "
    << "cracking two eggs into the bowl. Step 2: adding 2 tablespoons"
    << " of milk. Step 3: whisking until yolks and whites are fully "
    << "combined. Successfully poured egg mixture into the preheated "
    << "pan. Observing slight bubbling around the edges, indicating"
    << "correct temperature." << std::endl;
}

void    Harl::warning(void) {
    
    std::cout << "The carton indicates these eggs are a few days "
    << "past the 'best by' date. While likely still safe, exercise "
    << "caution and check for any unusual odor or appearance before use."
    << std::endl;
}

void    Harl::error(void) {

    std::cout << "While attempting a fancy flipping maneuver, the "
    << "entire pan of scrambled eggs landed upside down on the floor."
    << " Cleanup is extensive, and a new breakfast preparation "
    << "attempt will be necessary." << std::endl;
}

void    Harl::complain(std::string level) {

}