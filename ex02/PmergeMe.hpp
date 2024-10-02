#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "IMergeSorter.hpp"

#include <vector>

class PmergeMe {
  private:
    std::vector<IMergeSorter *> _sorters;

  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe( PmergeMe const &src );
    PmergeMe &operator=( PmergeMe const &src );

    void      addSorter( IMergeSorter *sorter );
    void      mergeMe( char *str );
};

#endif
