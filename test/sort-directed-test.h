//========================================================================
// sort-directed-tests.h
//========================================================================
// This file contains generic directed tests for the sort function. All
// of the generic test functions are templated by an "object creation"
// function which should take as a parameter an integer and return a
// newly created object. For integers, the object creation function can
// just be the identity function. For images, the object creation
// function can create a small image and initialize the pixels based on
// the given integer.

#include "sort.h"
#include "utst.h"

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_helper
//------------------------------------------------------------------------
// Simple test case for the helper function.

template < typename T, typename Func >
void test_case_helper( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Adding at least one test of any helper function is a good idea!
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// test_case_five_element
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_five_element( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(4), f(3), f(5), f(6), f(10)  };
  T a0_ref[] = { f(3), f(4), f(5), f(6), f(10) };
  sort( a0, 5 );
  for ( size_t i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(5), f(9), f(1), f(0), f(13) };
  T a1_ref[] = { f(0), f(1), f(5), f(9), f(13) };
  sort( a1, 5 );
  for ( size_t i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );

  T a2[]     = { f(500), f(16), f(140), f(32), f(1000) };
  T a2_ref[] = { f(16), f(32), f(140), f(500), f(1000) };
  sort( a2, 5 );
  for ( size_t i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( a2[i] == a2_ref[i] );
}

//------------------------------------------------------------------------
// test_case_empty
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_empty( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[] = { f(1), f(2), f(3), f(4) };
  sort( a0, 0 );

  T* a1 = nullptr;
  sort( a1, 0 );
}

//------------------------------------------------------------------------
// test_case_one_element
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_one_element( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[] = { f(3) };
  sort( a0, 1 );
  UTST_ASSERT_TRUE( a0[0] == f(3) );

  T a1[] = { f(5) };
  sort( a1, 1 );
  UTST_ASSERT_TRUE( a1[0] == f(5) );

  T a2[] = { f(4) };
  sort( a2, 1 );
  UTST_ASSERT_TRUE( a2[0] == f(4) );
}

//------------------------------------------------------------------------
// test_case_two_element
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_two_elements( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[] = { f(4), f(3) };
  sort( a0, 2 );
  UTST_ASSERT_TRUE( a0[0] == f(3) );
  UTST_ASSERT_TRUE( a0[1] == f(4) );

  T a1[] = { f(3), f(4) };
  sort( a1, 2 );
  UTST_ASSERT_TRUE( a1[0] == f(3) );
  UTST_ASSERT_TRUE( a1[1] == f(4) );

  T a2[] = { f(-4), f(3) };
  sort( a2, 2 );
  UTST_ASSERT_TRUE( a2[0] == f(-4) );
  UTST_ASSERT_TRUE( a2[1] == f(3) );

  T a3[] = { f(3), f(-4) };
  sort( a3, 2 );
  UTST_ASSERT_TRUE( a3[0] == f(-4) );
  UTST_ASSERT_TRUE( a3[1] == f(3) );
}

//------------------------------------------------------------------------
// test_case_three_element
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_three_elements( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[] = { f(4), f(3), f(2) };
  sort( a0, 3 );
  UTST_ASSERT_TRUE( a0[0] == f(2) );
  UTST_ASSERT_TRUE( a0[1] == f(3) );
  UTST_ASSERT_TRUE( a0[2] == f(4) );

  T a1[] = { f(3), f(4), f(2) };
  sort( a1, 3 );
  UTST_ASSERT_TRUE( a1[0] == f(2) );
  UTST_ASSERT_TRUE( a1[1] == f(3) );
  UTST_ASSERT_TRUE( a1[2] == f(4) );

  T a2[] = { f(4), f(-3), f(2) };
  sort( a2, 3 );
  UTST_ASSERT_TRUE( a2[0] == f(-3) );
  UTST_ASSERT_TRUE( a2[1] == f(2) );
  UTST_ASSERT_TRUE( a2[2] == f(4) );

  T a3[] = { f(-3), f(4), f(2) };
  sort( a3, 3 );
  UTST_ASSERT_TRUE( a3[0] == f(-3) );
  UTST_ASSERT_TRUE( a3[1] == f(2) );
  UTST_ASSERT_TRUE( a3[2] == f(4) );
}

//------------------------------------------------------------------------
// test_case_even_size_array
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_even_size_array( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(17), f(36), f(20), f(59), f(18), f(39), f(84), f(43), f(87), f(25), f(63), f(69), f(31), f(50), f(86), f(34) };
  T a0_ref[] = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  sort( a0, 16 );
  for ( int i = 0; i < 16; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(58), f(29), f(16), f(-18), f(-16), f(-66), f(-1), f(-96), f(-19), f(-13), f(3), f(-88), f(28), f(-80), f(74), f(-34) };
  T a1_ref[] = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(58), f(74) };
  sort( a1, 16 );
  for ( int i = 0; i < 16; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

//------------------------------------------------------------------------
// test_case_odd_size_array
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_odd_size_array( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(17), f(36), f(20), f(59), f(18), f(39), f(84), f(43), f(87), f(25), f(63), f(69), f(31), f(50), f(86), f(34), f(42) };
  T a0_ref[] = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(42), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  sort( a0, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(58), f(29), f(16), f(-18), f(-16), f(-66), f(-1), f(-96), f(-19), f(-13), f(3), f(-88), f(28), f(-80), f(74), f(-34), f(42) };
  T a1_ref[] = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(42), f(58), f(74) };
  sort( a1, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

//------------------------------------------------------------------------
// test_case_almost_sorted
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_almost_sorted( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(17), f(18), f(20), f(25), f(31), f(50), f(36), f(39), f(42), f(43), f(34), f(59), f(63), f(69), f(84), f(86), f(87) };
  T a0_ref[] = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(42), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  sort( a0, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(-96), f(-88), f(-80), f(-66), f(3), f(-19), f(-18), f(-16), f(-13), f(-1), f(-34), f(16), f(28), f(29), f(42), f(58), f(74) };
  T a1_ref[] = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(42), f(58), f(74) };
  sort( a1, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

//------------------------------------------------------------------------
// test_case_sorted_ascending
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_sorted_ascending( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(42), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  T a0_ref[] = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(42), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  sort( a0, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(42), f(58), f(74) };
  T a1_ref[] = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(42), f(58), f(74) };
  sort( a1, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

//------------------------------------------------------------------------
// test_case_sorted_descending
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_sorted_descending( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(87), f(86), f(84), f(69), f(63), f(59), f(50), f(43), f(42), f(39), f(36), f(34), f(31), f(25), f(20), f(18), f(17) };
  T a0_ref[] = { f(17), f(18), f(20), f(25), f(31), f(34), f(36), f(39), f(42), f(43), f(50), f(59), f(63), f(69), f(84), f(86), f(87) };
  sort( a0, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(74), f(58), f(42), f(29), f(28), f(16), f(3), f(-1), f(-13), f(-16), f(-18), f(-19), f(-34), f(-66), f(-80), f(-88), f(-96) };
  T a1_ref[] = { f(-96), f(-88), f(-80), f(-66), f(-34), f(-19), f(-18), f(-16), f(-13), f(-1), f(3), f(16), f(28), f(29), f(42), f(58), f(74) };
  sort( a1, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

//------------------------------------------------------------------------
// test_case_few_unique
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_few_unique( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );

  T a0[]     = { f(2), f(2), f(0), f(3), f(1), f(2), f(2), f(1), f(0), f(1), f(1), f(1), f(1), f(1), f(1), f(1), f(0) };
  T a0_ref[] = { f(0), f(0), f(0), f(1), f(1), f(1), f(1), f(1), f(1), f(1), f(1), f(1), f(2), f(2), f(2), f(2), f(3) };
  sort( a0, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a0[i] == a0_ref[i] );

  T a1[]     = { f(0), f(0), f(-1), f(-1), f(0), f(1), f(0), f(1), f(0), f(1), f(1), f(0), f(1), f(-1), f(-1), f(-1), f(0) };
  T a1_ref[] = { f(-1), f(-1), f(-1), f(-1), f(-1), f(0), f(0), f(0), f(0), f(0), f(0), f(0), f(1), f(1), f(1), f(1), f(1) };
  sort( a1, 17 );
  for ( int i = 0; i < 17; i++ )
    UTST_ASSERT_TRUE( a1[i] == a1_ref[i] );
}

