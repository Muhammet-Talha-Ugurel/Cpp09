#ifndef FORD_HPP
#define FORD_HPP

#pragma once

#include "IMergeSorter.hpp"

class Ford : public IMergeSorter {
  public:
    Ford();
    ~Ford();
	Ford( Ford const &src );
	Ford &operator=( Ford const &src );

	double sort(int *array, unsigned int size);
};

#endif
