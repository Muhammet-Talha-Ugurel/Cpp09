#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
  for ( std::vector<IMergeSorter *>::iterator it = this->_sorters.begin();
        it != this->_sorters.end(); it++ ) {
    delete *it;
  }
}

PmergeMe::PmergeMe( PmergeMe const &src ) {
  *this = src;
}

PmergeMe &PmergeMe::operator=( PmergeMe const &src ) {
  ( void ) src;
  return *this;
}

void PmergeMe::addSorter( IMergeSorter *sorter ) {
  this->_sorters.push_back( sorter );
}

void PmergeMe::mergeMe( char *str ) {
  std::vector<int>   numbers;
  std::istringstream iss( str );

  for ( std::string s; iss >> s; ) {
    if ( s.find_first_not_of( "0123456789" ) != std::string::npos ) {
      throw std::invalid_argument( "Invalid argument" );
    }
    numbers.push_back( std::stoi( s ) );
  }

  std::cout << "Before: ";
  for ( size_t i = 0; i < numbers.size(); i++ ) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  for ( std::vector<IMergeSorter *>::iterator it = _sorters.begin(); it != _sorters.end(); it++ ) {
    try {
      int *array = new int[numbers.size()];
      for ( size_t i = 0; i < numbers.size(); i++ ) {
        array[i] = numbers[i];
      }

      double proc = ( *it )->sort( array, numbers.size() );
	  std::cout << "Time taken: " << proc << std::endl;
      delete[] array;
    } catch ( std::exception &e ) {
      std::cerr << e.what() << std::endl;
    }
  }
}
