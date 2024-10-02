#include "BitcoinExchange.hpp"
#include "parseUtil.h"

#include <fstream>
#include <iostream>
#include <string>

std::string dateOut( time_t date ) {
  std::tm *tm = std::localtime( &date );
  char     buffer[80];
  strftime( buffer, sizeof( buffer ), "%Y-%m-%d", tm );
  return buffer;
}

void calculations( BitcoinExchange trading, const std::string &filename ) {
  std::ifstream file( filename );
  if ( !file.is_open() )
    throw std::invalid_argument( "Error: Cannot open file: " + filename );

  std::string line;
  std::getline( file, line );       // skip header

  while ( std::getline( file, line ) ) {
    try {
      std::pair<time_t, double> input           = parseLine( line, '|', true );
      double                    exchangedAmount = trading.getExchangedAmount( input );
      if ( exchangedAmount == -1 )
        std::cout << "No data for " << dateOut( input.first ) << std::endl;
      else
        std::cout << dateOut( input.first ) << " => " << input.second << " = "
                  << input.second * exchangedAmount << std::endl;
    } catch ( std::exception &e ) {
      std::cerr << "\033[31mError:\033[m " << e.what() << std::endl;
    }
  }
}

int main( int argc, char **argv ) {
  if ( argc != 2 ) {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  try {
    BitcoinExchange trading = BitcoinExchange();

    calculations( trading, argv[1] );
  } catch ( std::exception &e ) {
    std::cerr << "\033[31mError: \033[m" << e.what() << std::endl;
    return 1;
  }
}
