//========================================================================
// HRSTreeSearch.cc
//========================================================================
// Definitions for HRSTreeSearch

#include "HRSTreeSearch.h"
#include "Vector.h"
#include "Tree.h"
#include "Image.h"

HRSTreeSearch::HRSTreeSearch( unsigned int K )
{
  m_tree.setK(K);
}

void HRSTreeSearch::train( const Vector<Image>& vec )
{
  //iterate vec
  for ( size_t i = 0; i < vec.size(); i++ ) {
    m_tree.add( vec.at( i ) );
  }
}

Image HRSTreeSearch::classify( const Image& img ){
    return m_tree.find_closest(img);// return type Image&?
}