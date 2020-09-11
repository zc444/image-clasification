//========================================================================
// HRSBinarySearch.cc
//========================================================================
// Handwritten recognition system that uses binary search.

#include <cstddef>
#include <iostream>
#include <climits>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include "HRSAlterative2.h"

// #define K 1000
int binarySearch( const Vector<Image>& vec, int l, int r, int imgIntensity );
int find_max(int diff[]);
//Default constructor
HRSAlternative2::HRSAlternative2( unsigned int K ) : m_K( K ) {}

void HRSAlternative2::train( const Vector<Image>& vec )
{
  m_vec = vec;
  m_vec.sort();
}

Image HRSAlternative2::classify( const Image& img )
{
  int imgIntensity = img.get_intensity();
  // binary search
  int index = binarySearch( m_vec, 0, m_vec.size() - 1, imgIntensity );

  // linear search [start,end]
  int start   = index - m_K / 2 >= 0 ? index - m_K / 2 : 0;
  int vecSize = (int)m_vec.size();
  int end     = index + m_K / 2 < vecSize ? index + m_K / 2 : vecSize - 1;

  int tmp;
  Image target_img = m_vec.at( start );
  Image closest[5];
  int diff[5]={INT_MAX};
  int max_idx = 0;
  int max = INT_MAX;
  /*for (int i=0;i<5;i++)
    diff[i]=INT_MAX;*/
  for ( int i = start; i <= end; i++ ) {
    tmp = m_vec.at( i ) - img;
    if(tmp<max)
    {
      diff[max_idx]=tmp;
      closest[max_idx]=m_vec.at(i);
      max_idx=find_max(diff);
      max=diff[max_idx];
    }
  }
  
  int count[10]={0};
  for ( int i = 0; i < 5; i++ ) {
    switch ( closest[i].get_label() - 48 ) {
      case 0: count[0]++; break;
      case 1: count[1]++; break;
      case 2: count[2]++; break;
      case 3: count[3]++; break;
      case 4: count[4]++; break;
      case 5: count[5]++; break;
      case 6: count[6]++; break;
      case 7: count[7]++; break;
      case 8: count[8]++; break;
      case 9: count[9]++; break;
    }
  }
  
  int max_label = count[0];
  int idx = 0;
  for ( int i = 0; i < 10 ; i++ ) {
    if( count[i] > max_label ) {
      max_label = count[i];
      idx = i;
    }
  }
  
  for ( int i = 0; i < 5; i++ ) {
    if( closest[i].get_label() - 48 == idx )
      target_img = closest[i];
      break;
  }
  
  return target_img;
}

int find_max(int diff[])
{
  int max=diff[0];
  int idx=0;
  for(int i=0;i<5;i++)
  {
    if(diff[i]>max)
    {
      max=diff[i];
      idx=i;
    }
  }
  return idx;
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
