#include "Ford.hpp"

#include <deque>
#include <iostream>

Ford::Ford() {
}

Ford::~Ford() {
}

Ford::Ford( Ford const &src ) {
  *this = src;
}

Ford &Ford::operator=( Ford const &src ) {
  ( void ) src;
  return *this;
}

void merge( std::deque<int> &arr, int left, int mid, int right ) {
  int             n1 = mid - left + 1;
  int             n2 = right - mid;

  std::deque<int> L;
  std::deque<int> R;

  for ( int i = 0; i < n1; ++i )
    L.push_back( arr[left + i] );
  for ( int j = 0; j < n2; ++j )
    R.push_back( arr[mid + 1 + j] );

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

void fordJohnsonSort( std::deque<int> &arr, int left, int right ) {
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

void print( std::deque<int> &arr ) {
  std::cout << "After deque: ";
  for ( unsigned int i = 0; i < arr.size(); i++ ) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

double Ford::sort(int *array, unsigned int size) {
    std::cout << "Using deque" << std::endl;

    clock_t start = clock();
    
    std::deque<int> dq;
    for (unsigned int i = 0; i < size; ++i) {
        dq.push_back(array[i]);
    }

    fordJohnsonSort(dq, 0, size - 1);

    clock_t end = clock();
    print(dq);
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
