#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Charlie");

        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
