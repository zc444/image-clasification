//========================================================================
// HRSBinarySearch.cc
//========================================================================
// Handwritten recognition system that uses binary search.

#include <cstddef>
#include <iostream>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include "HRSBinarySearch.h"

// #define K 1000
int binarySearch( const Vector<Image>& vec, int l, int r, int imgIntensity );
//Default constructor
HRSBinarySearch::HRSBinarySearch( unsigned int K ) : m_K( K )
{
}

void HRSBinarySearch::train( const Vector<Image>& vec )
{
  m_vec = vec;
  m_vec.sort();
}

Image HRSBinarySearch::classify( const Image& img )
{
  int imgIntensity = img.get_intensity();
  // binary search
  int index = binarySearch( m_vec, 0, m_vec.size() - 1, imgIntensity );

  // linear search [start,end]
  int start   = index - m_K / 2 >= 0 ? index - m_K / 2 : 0;
  int vecSize = (int)m_vec.size();
  int end     = index + m_K / 2 < vecSize ? index + m_K / 2 : vecSize - 1;

  //    find_closest
  //    init min value and number to return
  int   min        = this->m_vec.at( start ) - img;
  int   tmp        = min;
  Image target_img = this->m_vec.at( start );

  //    iterate through vectorImage, update min and number
  for ( int i = start; i <= end; i++ ) {
    tmp = this->m_vec.at( i ) - img;
    if ( tmp < min ) {
      min        = tmp;
      target_img = this->m_vec.at( i );
    }
  }
  return target_img;
}

// helper function
int binarySearch( const Vector<Image>& vec, int l, int r, int imgIntensity )
{
  if ( r >= l ) {
    int mid           = l + ( r - l ) / 2;
    int currIntensity = vec.at( mid ).get_intensity();
    // If the element is present at the middle
    // itself
    if ( currIntensity == imgIntensity )
      return mid;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if ( currIntensity > imgIntensity )
      return binarySearch( vec, l, mid - 1, imgIntensity );

    // Else the element can only be present
    // in right subarray
    return binarySearch( vec, mid + 1, r, imgIntensity );
  }

  // We reach here when element is not
  // present in array
  return -1;
}
