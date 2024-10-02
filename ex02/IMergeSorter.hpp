#ifndef IMERGESORTER_HPP
#define IMERGESORTER_HPP

#pragma once

class IMergeSorter {
  public:
    virtual ~IMergeSorter() {};

	virtual double sort(int *array, unsigned int size) = 0;
};

#endif
