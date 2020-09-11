//========================================================================
// Table.h
//========================================================================
// Declarations for generic table.

#ifndef TABLE_H
#define TABLE_H

#include <cstddef>

template < typename T >
class Vector;

template < typename T >
class Table
{
 public:
  Table( unsigned int nbins = 1, T min = T(), T max = T() );

  // Methods
  size_t   size() const;
  void     add( const T& value );
  bool     find( const T& value ) const;
  const T& find_closest( const T& value ) const;
  void     print() const;

 private:
  Vector<Vector<T>> m_vec;
  unsigned int m_nbins;
  T m_min;
  T m_max;
};

// Include inline definitions
#include "Table.inl"

#endif /* TABLE_H */

