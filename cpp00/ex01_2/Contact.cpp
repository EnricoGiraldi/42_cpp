#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& nickname)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), nickname(nickname) {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getNickname() const { return nickname; }

void Contact::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Contact::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setNickname(const std::string& nickname) { this->nickname = nickname; }
