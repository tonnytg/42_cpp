#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _rateData;	
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& btc);
    BitcoinExchange& operator=(const BitcoinExchange& btc);
    ~BitcoinExchange();

    void load(const std::string& file);
    float getRate(const std::string& date);
};


#endif
