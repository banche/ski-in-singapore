#ifndef _MOUNTAIN_HPP_
#define _MOUNTAIN_HPP_

#include <vector>
#include <string>

/**
 * @namespace SkiChallenge
 * @brief class and function related to the ski coding challenge
 */
namespace SkiChallenge {

/**
 * @class Mountain
 * @brief Type to hold the mountain representation
 *
 * It enables you to hold all the hills values from
 * a file and provides functions to access them
 * and look for down hill neighbors
 */
class Mountain {
    
public :
    /** @typedef Neighbors */ 
    typedef std::vector<unsigned int> Neighbors;
    
    /** constructor */
    Mountain()= default;
    /** destructor */
    ~Mountain() = default;

    /** load data from a file
     * @return true is the load is successfuly done
     * @return false if file does not exist or if an error occurs
     */
    bool load(const std::string& filename);
    
    /**
     * Return all down hill neighbors for the point located at index
     *
     * row_index = index / Mountain::rows()
     * col_index = index % Mountain::cols()
     *
     * It will only return all the neighbors with a stricly lower
     * elevation
     *
     */
    Neighbors downhillNeighbors(unsigned int index) const noexcept;
    
    /** return the numbers of rows */
    inline unsigned int rows() const noexcept { return m_rows;}

    /** return the number of cols */
    inline unsigned int cols() const noexcept { return m_cols;}
    
    /** return total mountain size */
    inline unsigned int size() const noexcept { return m_map.size();}

    /** overload const operator[] to provide an easy access to an index */
    inline uint16_t operator[](unsigned int index) const { return m_map[index];}
private :
    unsigned int m_rows; /**< number of rows */
    unsigned int m_cols; /**< number of columns */

    std::vector<uint16_t> m_map; /**< vector to hold all points */

};


} // end SkiChallenge

#endif

