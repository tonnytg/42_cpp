#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rateData(other._rateData) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _rateData = other._rateData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::load(const std::string& file) {
    std::ifstream db(file.c_str());
    if (!db) {
        std::cerr << "Error: could not open file: " << file << std::endl;
        return;
    }

    // Skip the first line (header)
    std::string header;
    std::getline(db, header);

    std::string line;
    while (std::getline(db, line)) {
        std::stringstream ss(line);
        std::string date;
        float rate;
        if (!std::getline(ss, date, ',') || !(ss >> rate)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        _rateData[date] = rate;
    }
    db.close();
}

float BitcoinExchange::getRate(const std::string& date) {
    std::stringstream ss(date);
    int year, month, day;
    char dash;
    
    if (!(ss >> year >> dash >> month >> dash >> day) || 
        dash != '-' || 
        year < 1 || year > 9999 || 
        month < 1 || month > 12 || 
        day < 1 || day > 31) {
        throw std::invalid_argument("Error: invalid date.");
    }
    
    std::map<std::string, float>::iterator it = _rateData.lower_bound(date);
    if (it == _rateData.end() || it->first != date) {
        if (it == _rateData.begin()) {
            throw std::invalid_argument("Error: can't find the price for this date.");
        }
        --it; // get the previous (lower) date
    }
    return it->second;
}


