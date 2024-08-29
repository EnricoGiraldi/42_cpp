#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void processLine(BitcoinExchange &exchange, const std::string &line) {
    std::istringstream ss(line);
    std::string date, valueStr;
    if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
        date = date.substr(0, date.find_last_not_of(" \t") + 1);
        valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));
        float value = std::atof(valueStr.c_str());

        if (!exchange.isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
        } else if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
        } else if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
        } else {
            float rate = exchange.getRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange("data.csv");
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        processLine(exchange, line);
    }

    inputFile.close();
    return 0;
}
