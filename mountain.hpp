#ifndef _MOUNTAIN_HPP_
#define _MOUNTAIN_HPP_

#include <vector>
#include <string>

namespace SkiChallenge {

class Mountain {
    
public :
    
    typedef std::vector<unsigned int> Neighbors;
    
    Mountain()= default;
    ~Mountain() = default;


    bool load(const std::string& filename);

    Neighbors downhillNeighbors(unsigned int index) const noexcept;
    
    inline unsigned int rows() const noexcept { return m_rows;}
    inline unsigned int cols() const noexcept { return m_cols;}
    
    inline unsigned int size() const noexcept { return m_map.size();}

    inline uint16_t operator[](unsigned int index) const { return m_map[index];}
private :
    unsigned int m_rows;
    unsigned int m_cols;

    std::vector<uint16_t> m_map;

};


} // end SkiChallenge

#endif

