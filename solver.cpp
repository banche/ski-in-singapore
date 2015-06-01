#include "solver.hpp"

namespace SkiChallenge {

//fit it inside 64bits
struct BoxState {
  uint32_t pathLength;
  uint32_t drop;
  bool isVisited;
  
  BoxState();
};

BoxState::BoxState()
  : pathLength(0)
  , drop(0)
  , isVisited(0)
{
}

typedef std::vector<BoxState> BoxStates;

void lookNeighbors(const Mountain& mountain, BoxStates& states, unsigned int index)
{
  Mountain::Neighbors neighbors = mountain.downhillNeighbors(index);
  
  for(auto n: neighbors)
  {
    // first time we visit it check the neighbors
    if( not states[n].isVisited)
    {
      lookNeighbors(mountain,states,n);
    }
    auto pathLength = states[n].pathLength + 1;
    uint32_t drop = states[n].drop + mountain[index] - mountain[n];
    
    // keep best only
    if(pathLength > states[index].pathLength)
    {
      states[index].pathLength = pathLength;
      states[index].drop = drop;
    }
    else if ( pathLength == states[index].pathLength)
    {
      states[index].drop = std::max(states[index].drop,drop);
    }
  }
  // mark state as visited
  // no need to redo the computation for this state
  states[index].isVisited = true;
}

std::pair<unsigned int,unsigned int> findLongestPath(const Mountain& mountain)
{
  // init states with 0 and not visited
  BoxStates states(mountain.size());
  uint32_t maxPathLength = 0;
  uint32_t maxDrop = 0;
  
  // for all hills compute pathLength and drop
  // save the best one
  for ( auto i = 0; i < mountain.size() ; ++i)
  {
    if ( not states[i].isVisited )
      lookNeighbors(mountain,states,i);
    
    if(states[i].pathLength > maxPathLength)
    {
      maxPathLength = states[i].pathLength;
      maxDrop = states[i].drop;
    }
    else if ( states[i].pathLength == maxPathLength)
    {
      maxDrop = std::max(states[i].drop,maxDrop);
    }
  }
  
  return std::pair<unsigned int,unsigned int>(maxPathLength+1,maxDrop);
}
  
}
