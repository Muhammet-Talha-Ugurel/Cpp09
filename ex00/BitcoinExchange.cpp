#include "BitcoinExchange.hpp"

#include "parseUtil.h"

BitcoinExchange::BitcoinExchange() {
	_data = parseCsv( "data.csv" );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &copy ) {
  _data = copy._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy)
        _data = copy._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

std::map<time_t, double> BitcoinExchange::getData() const {
  return _data;
}

double BitcoinExchange::getExchangedAmount( std::pair<time_t, double> input ) const {
  std::map<time_t, double>::const_iterator it   = _data.lower_bound( input.first );
  if ( it != _data.end() && it->first == input.first ) {
    return it->second;
  } else if ( it != _data.begin() ) {
    it--;
    return it->second;
  } else {
    return -1;
  }
}
