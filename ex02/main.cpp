#include "Ford.hpp"
#include "Johnson.hpp"
#include "PmergeMe.hpp"

#include <iostream>

int main( int argc, char **argv ) {
  if ( argc != 2 ) {
    std::cerr << "Usage: ./PmergeMe `<numbers string>`" << std::endl;
    return 1;
  }

  PmergeMe p = PmergeMe();

  p.addSorter( new Ford() );
  p.addSorter( new Johnson() );

  p.mergeMe( argv[1] );
  return 0;
}
