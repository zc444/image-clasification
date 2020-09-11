//========================================================================
// Image.h
//========================================================================
// Declarations for Image.

#ifndef IMAGE_H
#define IMAGE_H

#include "Vector.h"

#include <iostream>
#include <cstddef>

class Image
{
 public:
  // Constructors
  Image();
  Image( const Vector<int>& vec, size_t ncols, size_t nrows );

  // Methods
  size_t get_ncols() const;
  size_t get_nrows() const;
  int    at( size_t x, size_t y ) const;
  void   set_label( char label );
  char   get_label() const;
  int    get_intensity() const;
  void   print() const;

  // Operator overloading
  int  operator- ( const Image& rhs ) const;
  bool operator< ( const Image& rhs ) const;
  bool operator> ( const Image& rhs ) const;
  bool operator<=( const Image& rhs ) const;
  bool operator>=( const Image& rhs ) const;
  bool operator==( const Image& rhs ) const;
  bool operator!=( const Image& rhs ) const;

  friend std::ostream& operator<<( std::ostream& output,
                                   const Image& image );

 private:
  size_t      m_ncols;
  size_t      m_nrows;
  Vector<int> m_vec;
  char        m_label;
  int         m_flag_label = 0;
  int         m_intensity = 0;
};

// Include inline definitions
#include "Image.inl"

#endif  // IMAGE_H

