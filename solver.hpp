#ifndef _SOLVER_HPP_
#define _SOLVER_HPP_

#include "mountain.hpp"

namespace SkiChallenge {
 
/**
 * Find the longest path and drop for a given mountain
 *
 * @return a pair (longest path, drop value)
 */ 
std::pair<unsigned int,unsigned int> findLongestPath(const Mountain& mountain);
  
}

#endif // end _SOLVER_HPP_
