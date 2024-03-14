#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

private:
    Contact contacts[8];
    static int contactCount;

};

#endif 