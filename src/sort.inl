//========================================================================
// sort.inl
//========================================================================
// Definition of generic sort algorithm.
// Use quicksort algorithm
// Add template < typename T > , change _int_ into _T_

#include"sort.h"

template < typename T >
void swap(T* x, T* y)// not effective when T is Image type
{
  T temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

template < typename T >
size_t partition( T* arr, size_t begin, size_t end )
{
  T    pivot = arr[end - 1];
  size_t idx   = begin;
  for ( size_t i = begin; i < end; i++ ) {
    if ( arr[i] <= pivot ) {
      swap(&arr[i],&arr[idx]);
      idx++;
    }
  }
  return idx - 1;// arr[i] <= pivot , so, idx - 1
}

//------------------------------------------------------------------------
// quick_sort_h
//------------------------------------------------------------------------
// Sorts the array with quick sort in recursive method.

template < typename T >
void quick_sort_h( T* arr, size_t begin, size_t end )
{
  if ( begin >= end )
    return;// deal with when size = 0, simply do nothing
  size_t p = partition( arr, begin, end );
  quick_sort_h( arr, begin, p );
  quick_sort_h( arr, p + 1, end );
}

template < typename T >
void sort( T* a, size_t size )
{
  quick_sort_h( a, 0, size );
}
