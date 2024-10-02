#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <time.h>

class BitcoinExchange {
  private:
    std::map<time_t, double> _data;

  public:
    BitcoinExchange();
    BitcoinExchange( const BitcoinExchange & );
    BitcoinExchange &operator=( const BitcoinExchange & );
    ~BitcoinExchange();

    std::map<time_t, double> getData() const;

	double getExchangedAmount( std::pair<time_t, double> input ) const;
};

#endif       // BITCOIN_EXCHANGE_HPP
