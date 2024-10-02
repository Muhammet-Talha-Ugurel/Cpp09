#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

void trim( std::string &str ) {
  str.erase( str.find_last_not_of( " \t" ) + 1 );
  str.erase( 0, str.find_first_not_of( " \t" ) );
}

std::pair<time_t, double> parseLine( const std::string &line, char delimiter, bool max1000 ) {
  std::istringstream lineStream( line );
  std::string        dateStr, valueStr;

  if ( !std::getline( lineStream, dateStr, delimiter ) )
    throw std::invalid_argument( "Invalid line format " + line );

  trim( dateStr );

  if ( !std::getline( lineStream, valueStr ) )
    throw std::invalid_argument( "Invalid line format " + line );

  trim( valueStr );

  if ( dateStr.empty() || valueStr.empty() )
    throw std::invalid_argument( dateStr.empty() ? "Date is empty" : "Value is empty" );

  std::istringstream valueStream( valueStr );
  double             value;
  if ( !( valueStream >> value ) || !valueStream.eof() )
    throw std::invalid_argument( "Error: Bad input => " + line );

  if ( value < 0 || ( max1000 && value > 1000 ) )
    throw std::invalid_argument( value < 0 ? "Value is negative" : "Value is too high" );

  std::tm            tm = {};
  std::istringstream dateStream( dateStr );
  if ( !( dateStream >> std::get_time( &tm, "%Y-%m-%d" ) ) || dateStream.fail() )
    throw std::invalid_argument( "Error: Invalid date format" );

  tm.tm_mon -= 1;
  tm.tm_hour  = 0;
  tm.tm_min   = 0;
  tm.tm_sec   = 0;

  time_t time = mktime( &tm );
  if ( time == -1 )
    throw std::invalid_argument( "Error: mktime failed" );

  return std::make_pair( time, value );
}

std::map<time_t, double> parseCsv( const std::string &filename ) {
  std::ifstream file( filename );
  if ( !file.is_open() )
    throw std::invalid_argument( "Error: Could not open file " + filename );

  std::map<time_t, double> data;
  std::string              line;
  std::getline( file, line );

  while ( std::getline( file, line ) ) {
    try {
      data.insert( parseLine( line, ',', false ) );
    } catch ( const std::exception &e ) {
      std::cerr << "Warning: " << e.what() << std::endl;
    }
  }

  return data;
}
