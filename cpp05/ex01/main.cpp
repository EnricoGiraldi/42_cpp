#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Form f1("Form1", 1, 1);
        Form f2("Form2", 150, 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1); // Should succeed
        b2.signForm(f2); // Should succeed
        b2.signForm(f1); // Should fail
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f3("Form3", 151, 1); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f4("Form4", 1, 0); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
