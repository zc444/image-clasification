//========================================================================
// Table.inl
//========================================================================
// Implementation of Table.

#include "ece2400-stdlib.h"
#include "Vector.h"

template <typename T>
Table<T>::Table( unsigned int nbins, T min, T max )
{
  if ( nbins == 0 || min > max ) {
    char const* err_msg = "creation error";
    throw ece2400::OutOfRange( err_msg );
  }
  m_nbins = nbins;
  m_min   = min;
  m_max   = max;
  Vector<T> vec;
  for ( size_t i = 0; i < m_nbins; i++ )
    m_vec.push_back( vec );
}

template <typename T>
size_t Table<T>::size() const
{
  size_t size = 0;
  for ( size_t i = 0; i < m_vec.size(); i++ )
    size += m_vec[i].size();
  return size;
}

template <typename T>
void Table<T>::add( const T& value )
{
  unsigned int range;
  range = ( m_max - m_min ) / m_nbins;
  if ( range == 0 ){
    m_vec[0].push_back( value );
    return;
  }    
  
  unsigned int bin_num = ( value - m_min ) / range;
  if ( bin_num == m_nbins )// input value is 99 100..
    bin_num--;
  if (value == m_min)// input value is 0
    bin_num = 0;
  m_vec[bin_num].push_back( value );
}

template <typename T>
bool Table<T>::find( const T& value ) const
{
  size_t idx;
  int    range;
  range = ( m_max - m_min ) / m_nbins;
  if ( range == 0 )
    return m_vec[0].find( value );
  if ( value < m_min )
    return m_vec[0].find( value );
  if ( value > m_max )
    return m_vec[m_nbins - 1].find( value );
  idx = ( value - m_min ) / range;
  if ( idx >= m_nbins - 1 )
    return m_vec[m_nbins - 1].find( value );
  return m_vec[idx].find( value );
}

template <typename T>
const T& Table<T>::find_closest( const T& value ) const
{
  if ( m_vec.size() == 0 ) {
    char const* err_msg = "can't find_closest empty vector";
    throw ece2400::OutOfRange( err_msg );
  }
  size_t idx;
  int    range;
  range = ( m_max - m_min ) / m_nbins;
  if ( range == 0 )
    m_vec[0].find_closest( value );
  if ( value < m_min )
    return m_vec[0].find_closest( value );
  if ( value > m_max )
    return m_vec[m_nbins - 1].find_closest( value );
  idx = ( value - m_min ) / range;
  if ( idx >= m_nbins - 1 )
    return m_vec[m_nbins - 1].find_closest( value );
  return m_vec[idx].find_closest( value );
}

template <typename T>
void Table<T>::print() const
{
  for ( size_t i = 0; i < m_vec.size(); i++ ) {
    T* data = new T[m_vec[i].size()];
    // std::cout << "m_vec.size " << m_vec[i].size() << std::endl;
    for ( size_t j = 0; j < m_vec[i].size(); j++ ) {
      data[j] = m_vec[i].at( j );
      // std::cout << j << " : " << m_vec[i].at( j ) << std::endl;
    }
    sort( data, m_vec[i].size() );
    for ( unsigned int k = 0; k < m_vec[i].size(); k++ ) {
      std::cout << data[k] << "," << ' ';
    }
    //std::cout << std::endl;
    //m_vec[i].print();
    delete[] data;
  }
}
