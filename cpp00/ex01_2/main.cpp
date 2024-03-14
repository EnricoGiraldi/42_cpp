#include "Phonebook.hpp"

int main() {
    Phonebook phonebook;

    Contact contact1("John", "Doe", "123456789", "johndoe");
    phonebook.addContact(contact1);

    Contact contact2("Jane", "Doe", "987654321", "janedoe");
    phonebook.addContact(contact2);

    phonebook.displayContacts();

    return 0;
}
