#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();

    float getRate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;

private:
    std::map<std::string, float> _exchangeRates;
    

    void loadDatabase(const std::string& dbFile);
    std::string findClosestDate(const std::string& date) const;
};

#endif
