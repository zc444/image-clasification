//========================================================================
// HRSLinearSearch.cc
//========================================================================
// Handwritten recognition system that uses linear search.

#include <iostream>
#include <cstddef>
#include "Image.h"
#include "Vector.h"
#include "HRSLinearSearch.h"

HRSLinearSearch::HRSLinearSearch()
{
}

void HRSLinearSearch::train( const Vector<Image>& vec )
{
  m_vec = vec;
}

Image HRSLinearSearch::classify( const Image& img )
{
  return m_vec.find_closest( img );
}
