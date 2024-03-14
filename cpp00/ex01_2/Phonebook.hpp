#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int contactCount;

public:
    Phonebook();
    ~Phonebook();

    bool addContact(const Contact& contact);
    void displayContacts() const;
};

#endif // PHONEBOOK_HPP
