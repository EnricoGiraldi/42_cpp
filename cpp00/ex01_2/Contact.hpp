#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickname;

public:
    Contact();
    Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& nickname);
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    std::string getNickname() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPhoneNumber(const std::string& phoneNumber);
    void setNickname(const std::string& nickname);
};

#endif // CONTACT_HPP
