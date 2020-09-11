//========================================================================
// HRSAlternative.cc
//========================================================================
// Alternative HRS implementation.

#include <cstddef>
#include <iostream>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include "HRSAlternative.h"
#include <thread>
#include <vector>
#include <algorithm>
#include "ece2400-stdlib.h"

#define NUM 4

HRSAlternative::HRSAlternative()
{
}
void HRSAlternative::train( const Vector<Image>& vec )
{
  m_vec = vec;
}

Image HRSAlternative::classify( const Image& img )
{
  Vector<Image> resimgs;
  std::vector<std::thread> workers;
  size_t                   SIZE   = m_vec.size();
  int                      b[NUM] = {0};
  for ( int i = 0; i < NUM - 1; i++ ) {
    workers.push_back( std::thread( [&,i]() {
      m_vec.find_closest_parallel( img, i * ( SIZE / NUM ), ( i + 1 ) * ( SIZE / NUM ), &b[i] );
    } ) );
  }
  m_vec.find_closest_parallel( img, ( NUM - 1 ) * ( SIZE / NUM ), SIZE, &b[NUM - 1] );

  std::for_each( workers.begin(), workers.end(), [&]( std::thread& t ) {
    t.join();
  } );

  for ( int i = 0; i < NUM; i++ ) {
    resimgs.push_back( m_vec.at( b[i] ) );
  }
   return resimgs.find_closest( img );
}
