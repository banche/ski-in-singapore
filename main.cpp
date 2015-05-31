#include "solver.hpp"
#include <iostream>


int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cerr << "please give a file name" << std::endl;
    return 1;
  }
  
  SkiChallenge::Mountain moutain;
  
  if( not moutain.load(argv[1]))
  {
    std::cerr << "Error while loading the file" << std::endl;
    return 1;
  }
  
  auto result = SkiChallenge::findLongestPath(moutain);
  
  std::cout << "Result is pathLength = " << result.first << " ; drop = " << result.second << std::endl;
  
  return 0;
}