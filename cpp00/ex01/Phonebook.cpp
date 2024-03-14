#include "Phonebook.hpp"

Phonebook::contactCount = 0;

void manage_contact()
{
    if (PhoneBook::contactCount == 7)
        PhoneBook::contactCount = 0;
}

