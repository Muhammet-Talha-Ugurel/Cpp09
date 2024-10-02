#include "Johnson.hpp"

#include <iostream>
#include <vector>

Johnson::Johnson() {
}

Johnson::~Johnson() {
}

Johnson::Johnson( Johnson const &src ) {
  *this = src;
}

Johnson &Johnson::operator=( Johnson const &src ) {
  ( void ) src;
  return *this;
}

void merge( std::vector<int> &arr, int left, int mid, int right ) {
  int              n1 = mid - left + 1;
  int              n2 = right - mid;

  std::vector<int> L( n1 );
  std::vector<int> R( n2 );

  for ( int i = 0; i < n1; ++i )
    L[i] = arr[left + i];
  for ( int j = 0; j < n2; ++j )
    R[j] = arr[mid + 1 + j];

  int i = 0;
  int j = 0;
  int k = left;

  while ( i < n1 && j < n2 ) {
    if ( L[i] <= R[j] ) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while ( i < n1 ) {
    arr[k++] = L[i++];
  }

  while ( j < n2 ) {
    arr[k++] = R[j++];
  }
}

void fordJohnsonSort( std::vector<int> &arr, int left, int right ) {
  if ( left >= right )
    return;

  if ( right - left == 1 ) {
    if ( arr[left] > arr[right] ) {
      std::swap( arr[left], arr[right] );
    }
    return;
  }

  int mid = left + ( right - left ) / 2;
  fordJohnsonSort( arr, left, mid );
  fordJohnsonSort( arr, mid + 1, right );
  merge( arr, left, mid, right );
}

void print( std::vector<int> &arr ) {
  std::cout << "After vector: ";
  for ( size_t i = 0; i < arr.size(); i++ ) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

double Johnson::sort( int *array, unsigned int size ) {
  std::cout << "Using vector" << std::endl;

  clock_t          start = clock();

  std::vector<int> numbers( size );

  for ( unsigned int i = 0; i < size; i++ ) {
    numbers[i] = array[i];
  }

  fordJohnsonSort( numbers, 0, size - 1 );

  clock_t end = clock();
  print( numbers );
  return static_cast<double>( end - start ) / CLOCKS_PER_SEC;
}
