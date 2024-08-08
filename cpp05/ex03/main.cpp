#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Intern someRandomIntern;

        AForm* form = NULL;  // Sostituito nullptr con NULL

        std::string formNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
        std::string targets[] = { "home", "Pippoativoli", "Cicciobenzina" };

        for (int i = 0; i < 3; ++i) {
            try {
                form = someRandomIntern.makeForm(formNames[i], targets[i]);
                bob.signForm(*form);
                bob.executeForm(*form);
                delete form;  
            } catch (std::exception &e) {
                std::cerr << "Error with form: " << formNames[i] << ", " << e.what() << std::endl;
                delete form;  
            }
        }
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
