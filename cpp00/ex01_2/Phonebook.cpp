#include "Phonebook.hpp"

Phonebook::Phonebook() : contactCount(0) {}

Phonebook::~Phonebook() {}

bool Phonebook::addContact(const Contact& contact) {
    if (contactCount < MAX_CONTACTS) {
        contacts[contactCount++] = contact;
        return true;
    }
    return false;
}

void Phonebook::displayContacts() const {
    std::cout << "Contacts:" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "Contact #" << (i + 1) << std::endl;
        std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
        std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
        std::cout << std::endl;
    }
}
