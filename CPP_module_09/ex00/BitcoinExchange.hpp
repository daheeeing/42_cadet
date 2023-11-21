#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
    private :
        std::map<std::string, float> data;

    public :
        BitcoinExchange();
	    BitcoinExchange(const BitcoinExchange& ref);
	    BitcoinExchange& operator=(const BitcoinExchange& ref);
	    ~BitcoinExchange();

        void readCSV();
        void checkInputValid(char *inputFile);
        void bitcoin(char *inputFile);
        bool checkDate_csv(const std::string& date);
        bool checkRate_csv(const std::string& rate);
};

#endif