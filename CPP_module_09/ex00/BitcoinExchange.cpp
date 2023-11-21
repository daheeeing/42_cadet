#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	data.insert(ref.data.begin(), ref.data.end());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	if (&ref != this)
		data.insert(ref.data.begin(), ref.data.end());
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::bitcoin(char *inputFile)
{
    try
    {   
        readCSV();
        checkInputValid(inputFile);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return ;
}

void BitcoinExchange::readCSV()
{
    std::ifstream csv("data.csv");
    if(!csv)
        throw std::runtime_error("Error: fail to open file");    
	std::string line;
    std::getline(csv, line);
    if(line == "")
        throw std::runtime_error("Error: empty file");
    if(line == "date,exchange_rate")
        throw std::runtime_error("Error: invalid form of .csv file");
    while (!std::getline(csv, line).eof())
    {
        size_t val = line.find(',');
        float rate;
        std::string date;
        if (checkDate_csv(line.substr(0, val)) == false)
            throw std::runtime_error("Error: invalid date format");
        if (checkRate_csv(line.substr(val+1, line.length())) == false)
            throw std::runtime_error("Error: invalid rate format");
        data.insert(std::pair<std::string, float>(date, rate));
    }
    return ;
}

bool checkDate_csv(const std::string& date)
{
    if (date.length() != 10)
		return (false);
	std::string tmp;
	std::istringstream iss(date);
	int year, month, day, i;

	for (i = 0; std::getline(iss, tmp, '-'); i++)
    {
		if (i == 0)
        {
			std::istringstream(tmp) >> year;
			if (year < 1000 || year > 9999)
				return (false);
		}
		else if (i == 1)
        {
			std::istringstream(tmp) >> month;
			if (month < 1 || month > 12)
				return (false);
		}
		else if (i == 2)
        {
			std::istringstream(tmp) >> day;
			if (day < 1 || day > 31)
				return (false);
      		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				return (false);
     		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        		if (day > 29 && month == 2)
					return (false);
			} else if (day > 28 && month == 2)
				return (false);
		}
	}
	if (i == 4)
		return false;
    return (true);
}

bool checkRate_csv(const std::string& rate)
{
    char *nullp = nullptr;
    float fval = std::strtod(rate.c_str(), &nullp);
	if (fval == 0 && !std::isdigit(rate[0]))
		return (false);
	if (*nullp && std::strcmp(nullp, "f"))
		return (false);
	if (fval < 0)
		return (false);
	return (true);
}

void checkInputValid(char *inputFile)
{

}