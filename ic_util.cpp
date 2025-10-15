#include <iostream>
#include "ic.h"

int main() {
    IC ic = IC("020722060573");

    std::cout << "Formatted: " << ic.getFormattedNumber() << std::endl;
    std::cout << "Raw: " << ic.getRawNumber() << std::endl;
    
    return 0;
};