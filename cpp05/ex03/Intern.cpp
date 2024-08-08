#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    struct FormPair {
        std::string name;
        FormCreator creator;
    };

    FormPair formPairs[3] = {
        { "shrubbery creation", &Intern::createShrubberyCreationForm },
        { "robotomy request", &Intern::createRobotomyRequestForm },
        { "presidential pardon", &Intern::createPresidentialPardonForm }
    };

    for (int i = 0; i < 3; ++i) {
        if (formPairs[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formPairs[i].creator)(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return NULL; 
}

AForm* Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}
