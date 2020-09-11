//========================================================================
// HRSTableSearch.cc
//========================================================================
// Definitions for HRSTableSearch

#include "HRSTableSearch.h"
#include "Vector.h"
#include "Table.h"
#include "Image.h"

#define Training_size 10

HRSTableSearch::HRSTableSearch( unsigned int K ) : m_K( K )
{}

void HRSTableSearch::train( const Vector<Image>& vec )
{
  // calculate min and max img intensity
  int min = vec.at( 0 ).get_intensity();
  int minidx = 0;
  int max = vec.at( 0 ).get_intensity();
  int maxidx = 0;
  for ( size_t i = 0; i < vec.size(); i++ ) {
    int tmp = vec.at( i ).get_intensity();
    if ( tmp > max ) {
      max = tmp;
      maxidx = i;
    }
    if ( tmp < min ) {
      min = tmp;
      minidx = i;
    }
  }

  // the number of training image: m_K
  unsigned int nbin = vec.size() / m_K > 0 ? vec.size() / m_K : 1;
  Table<Image> tmptable( nbin, vec.at(minidx), vec.at(maxidx) );  // min,max are image, not image intensity, is it ok?
  m_table = tmptable;
  
  //iterate and add
  for ( size_t i = 0; i < vec.size(); i++ ) {
    m_table.add( vec.at( i ) );
  }
}

Image HRSTableSearch::classify( const Image& img )
{
  return m_table.find_closest( img );
}
