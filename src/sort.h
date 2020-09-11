//========================================================================
// sort.h
//========================================================================
// Declarations for generic sort algorithm.

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

template < typename T >
void sort( T* a, size_t size );

// Include inline definitions
#include "sort.inl"

#endif  // SORT_H

