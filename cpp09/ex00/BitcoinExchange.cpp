#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float rate;

        if (std::getline(ss, date, ',') && ss >> rate) {
            _exchangeRates[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::getRate(const std::string& date) const {
    if (_exchangeRates.find(date) != _exchangeRates.end()) {
        return _exchangeRates.at(date);
    }
    std::string closestDate = findClosestDate(date);
    if (!closestDate.empty()) {
        return _exchangeRates.at(closestDate);
    }
    return 0.0f;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it != _exchangeRates.begin() && (it == _exchangeRates.end() || it->first != date)) {
        --it;
    }
    return it->first;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) return false;
    return true;
}

