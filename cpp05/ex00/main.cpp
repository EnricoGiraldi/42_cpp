#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.incrementGrade();  
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151);  
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("David", 2);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
        std::cout << b4 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Eve", 149);
        std::cout << b5 << std::endl;
        b5.decrementGrade();
        std::cout << b5 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
