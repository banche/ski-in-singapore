#include "mountain.hpp"

#include <iostream>
#include <fstream>

namespace SkiChallenge {

Mountain::Neighbors Mountain::downhillNeighbors(unsigned int index) const noexcept
{
  Mountain::Neighbors neighbors;
  neighbors.reserve(4);
  
  const auto rowIdx = index / m_rows;
  const auto colIdx = index - rowIdx * m_rows;
  
  const auto areaElevation = m_map[index];
  
  // north
  if(rowIdx > 0) {
    if(m_map[index-m_cols] < areaElevation)
      neighbors.push_back(index-m_cols);
  }
  // south
  if(rowIdx < (m_rows-1)) {
    if(m_map[index+m_cols] < areaElevation)
      neighbors.push_back(index+m_cols);
  }
  // west 
  if(colIdx > 0 ) {
    if(m_map[index - 1] < areaElevation)
      neighbors.push_back(index-1);
  }
  // east
  if(colIdx < (m_cols - 1)) {
    if(m_map[index + 1] < areaElevation)
      neighbors.push_back(index+1);
  }
  return neighbors;
}


bool Mountain::load(const std::string& filename)
{
  std::ifstream file(filename);
  if (not file.is_open()) {
    std::cerr << "Unable to open " << filename << std::endl;
    return false;
  }
  // read nb rows and nb cols
  file >> m_rows >> m_cols;
  // resize to avoid realloc
  m_map.resize(m_rows*m_cols);
  // read the file
  for(auto& e : m_map) { file >> e ; }
  return true;
}

  
  
  
  
  
  
  
  
  
};
