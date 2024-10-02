#ifndef JOHNSON_HPP
#define JOHNSON_HPP

#pragma once

#include "IMergeSorter.hpp"

class Johnson : public IMergeSorter {
  public:
    Johnson();
    ~Johnson();
	Johnson( Johnson const &src );
	Johnson &operator=( Johnson const &src );

	double sort(int *array, unsigned int size);
};

#endif
