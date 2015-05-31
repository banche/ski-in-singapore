#include "solver.hpp"

namespace SkiChallenge {

//fit it inside 64bits
struct BoxState {
  uint16_t pathLength;
  uint16_t drop;
  uint32_t isVisited;
  
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
    if( states[n].isVisited == 0)
    {
      lookNeighbors(mountain,states,n);
    }
    auto pathLength = states[n].pathLength + 1;
    uint16_t drop = states[n].drop + mountain[index] - mountain[n];
    
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
  states[index].isVisited = 1;
}

std::pair<unsigned int,unsigned int> findLongestPath(const Mountain& mountain)
{
  BoxStates states(mountain.size());
  uint16_t maxPathLength = 0;
  uint16_t maxDrop = 0;
  
  for ( auto i = 0; i < mountain.size() ; ++i)
  {
    if ( states[i].isVisited == 0 )
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