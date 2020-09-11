//========================================================================
// tree-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for table.

#include "Table.h"
#include <cstdio>

int main()
{
  Table<int> table( 8, 0, 10000 );

  for ( int v : { 0, 28, 1,10000,9999 } )
    table.add( v );

  table.print();

  return 0;
}
