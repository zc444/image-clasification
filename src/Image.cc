//========================================================================
// Image.cc
//========================================================================
// Implementations for Image.

#include <iostream>
#include "Image.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// print_pixel
//------------------------------------------------------------------------
// A helper function that prints a grayscale pixel using unicode based on
// the integer value.

void print_pixel( int v )
{
  if ( v <= 0 )
    std::cout << "  ";
  else if ( 0 < v && v <= 64 )
    std::cout << "\u2591\u2591";
  else if ( 64 < v && v <= 128 )
    std::cout << "\u2592\u2592";
  else if ( 128 < v && v <= 192 )
    std::cout << "\u2593\u2593";
  else
    std::cout << "\u2588\u2588";
}

//------------------------------------------------------------------------
//void Image::print() const
//------------------------------------------------------------------------
// Print the content of the Image
void Image::print() const
{  //iterator in image?
  for ( size_t i = 0; i < m_nrows; i++ ) {
    for ( size_t j = 0; j < m_ncols; j++ ) {
      print_pixel( m_vec.at( i * m_ncols + j ) );
      std::printf( " " );
    }
    std::printf( "\n" );
  }
}

//------------------------------------------------------------------------
// Image::Image()
//------------------------------------------------------------------------
// Default constructor

Image::Image()
{
  m_ncols = 0;
  m_nrows = 0;
}

//------------------------------------------------------------------------
// Image::Image( const VectorInt& vec, size_t ncols, size_t nrows )
//------------------------------------------------------------------------
// Non-default constructor

Image::Image( const Vector<int>& vec, size_t ncols, size_t nrows )
{
  if ( ncols * nrows != vec.size() ) {
    char const* err_msg = "The size of the vector does not match the number of columns and number of rows";
    throw ece2400::InvalidArgument( err_msg );
  }
  else {
    m_ncols = ncols;
    m_nrows = nrows;
    m_vec   = vec;

    for ( size_t i = 0; i < m_nrows; i++ ) {
      for ( size_t j = 0; j < m_ncols; j++ ) {
        m_intensity = m_intensity + m_vec.at( i * m_ncols + j );
      }
    }
  }
}

//------------------------------------------------------------------------
// size_t Image::get_ncols() const
//------------------------------------------------------------------------
// Return the number of columns of the current Image
size_t Image::get_ncols() const
{
  return m_ncols;
}

//------------------------------------------------------------------------
// size_t Image::get_nrows() const
//------------------------------------------------------------------------
// Return the number of rows of the current Image
size_t Image::get_nrows() const
{
  return m_nrows;
}

//------------------------------------------------------------------------
// int Image::at( size_t x, size_t y ) const
//------------------------------------------------------------------------
// Return the number of rows of the current Image
int Image::at( size_t x, size_t y ) const
{
  if ( x >= m_ncols || y >= m_nrows ) {
    char const* err_msg = "x or y is out-of-bound when calling Image::at()";
    throw ece2400::OutOfRange( err_msg );
  }
  return m_vec.at( y * m_ncols + x );
}

//------------------------------------------------------------------------
// void Image::set_label( char label )
//------------------------------------------------------------------------
// Set the current label of the Image to the given character label
void Image::set_label( char label )
{
  m_label      = label;
  m_flag_label = 1;
}

//------------------------------------------------------------------------
// char Image::get_label() const
//------------------------------------------------------------------------
// Return the current label of the Image. If no set_label has been called, return ?
char Image::get_label() const
{
  if ( m_flag_label == 0 ) {
    return '?';
  }
  return m_label;
}

//------------------------------------------------------------------------
// int Image::get_intensity() const
//------------------------------------------------------------------------
// Return the intensity of the current Image
int Image::get_intensity() const
{
  return m_intensity;
}

//------------------------------------------------------------------------
// int Image::operator-( const Image& rhs ) const
//------------------------------------------------------------------------
// Return the square of the Euclidean distance between two images

int Image::operator-( const Image& rhs ) const
{
  if ( m_ncols != rhs.get_ncols() || m_nrows != rhs.get_nrows() ) {
    char const* err_msg = "The dimension of the two images does not match";
    throw ece2400::InvalidArgument( err_msg );
  }
  int res = 0;
  for ( size_t i = 0; i < m_nrows; i++ ) {
    for ( size_t j = 0; j < m_ncols; j++ ) {
      size_t x = j, y = i;  // x,j,col | y,i,row
      res = res + ( this->at( x, y ) - rhs.at( x, y ) ) * ( this->at( x, y ) - rhs.at( x, y ) );
    }
  }

  return res;
}

//------------------------------------------------------------------------
// bool Image::operator<( const Image& rhs ) const
//------------------------------------------------------------------------
// Compares the intensity of the two images
// Return true if the current image’s intensity is smaller than the right-hand-side image

bool Image::operator<( const Image& rhs ) const
{
  if ( m_intensity < rhs.m_intensity )
    return true;
  return false;
}

//------------------------------------------------------------------------
// bool Image::operator>( const Image& rhs ) const
//------------------------------------------------------------------------
// compares the intensity of the two images
// Return true if current image’s intensity is greater than the right-hand-side image

bool Image::operator>( const Image& rhs ) const
{
  if ( m_intensity > rhs.m_intensity )
    return true;
  return false;
}

//------------------------------------------------------------------------
// bool Image::operator<=( const Image& rhs ) const
//------------------------------------------------------------------------
// compares the intensity of the two images

bool Image::operator<=( const Image& rhs ) const
{
  if ( m_intensity <= rhs.m_intensity )
    return true;
  return false;
}

//------------------------------------------------------------------------
// bool Image::operator>=( const Image& rhs ) const
//------------------------------------------------------------------------
// compares the intensity of the two images

bool Image::operator>=( const Image& rhs ) const
{
  if ( m_intensity >= rhs.m_intensity )
    return true;
  return false;
}

//------------------------------------------------------------------------
// bool Image::operator==( const Image& rhs ) const
//------------------------------------------------------------------------
// compares the value of each pixel

bool Image::operator==( const Image& rhs ) const
{
  bool flag = true;
  if ( m_ncols != rhs.get_ncols() || m_nrows != rhs.get_nrows() ) {
    flag = false;
  }
  else {
    for ( size_t i = 0; i < m_nrows; i++ ) {
      for ( size_t j = 0; j < m_ncols; j++ ) {
        size_t x = j, y = i;  // x,j,col | y,i,row
        if ( this->at( x, y ) != rhs.at( x, y ) ) {
          flag = false;
          break;
        }
      }
    }
  }
  return flag;
}

//------------------------------------------------------------------------
// bool Image::operator!=( const Image& rhs ) const
//------------------------------------------------------------------------
// compares the value of each pixel

bool Image::operator!=( const Image& rhs ) const
{
  if ( *this == rhs )
    return false;  // including when both img are empty
  return true;     // including when dimension does not match
}


std::ostream &operator<<(std::ostream &os, Image const &m) { 
    return os << m.get_label();
}