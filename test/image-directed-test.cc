//========================================================================
// image-directed-test.cc
//========================================================================
// Test program that includes directed tests for Image.

#include "Image.h"
#include "utst.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// test_case_1_basic
//------------------------------------------------------------------------
// A simple test case that tests Image basics.

void test_case_1_basic()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a image
  int data[] = { 19, 95, 0, 4, 2, 3 };
  Vector<int> vec( data, 6 );
  Image img( vec, 3, 2 );

  // Mutate vec to test deepcopy
  vec = Vector<int>();
  vec.push_back( 10 );
  vec.push_back( 11 );

  // Check ncols and nrows
  UTST_ASSERT_INT_EQ( img.get_ncols(), 3 );
  UTST_ASSERT_INT_EQ( img.get_nrows(), 2 );

  // Check data
  UTST_ASSERT_INT_EQ( img.at( 0, 0 ), 19 );
  UTST_ASSERT_INT_EQ( img.at( 1, 0 ), 95 );
  UTST_ASSERT_INT_EQ( img.at( 2, 0 ), 0  );
  UTST_ASSERT_INT_EQ( img.at( 0, 1 ), 4  );
  UTST_ASSERT_INT_EQ( img.at( 1, 1 ), 2  );
  UTST_ASSERT_INT_EQ( img.at( 2, 1 ), 3  );
}

//------------------------------------------------------------------------
// test_case_2_default_constructor
//------------------------------------------------------------------------
// Test if an empty image is initialized properly.

void test_case_2_default_constructor()
{
  std::printf( "\n%s\n", __func__ );

  // Default constructor
  Image img;

  // Check size, get_ncols and get_nrows
  UTST_ASSERT_INT_EQ( img.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img.get_nrows(), 0 );
}

//------------------------------------------------------------------------
// test_case_3_construct_size_mismatch
//------------------------------------------------------------------------

void test_case_3_construct_size_mismatch()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a vector of size 8
  int data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  Vector<int> vec( data, 8 );

  // Try constructing an image that has a size of 9

  bool flag = false;
  try {
    Image img( vec, 3, 3 );
  }
  catch ( ece2400::InvalidArgument e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_4_at_out_of_bound
//------------------------------------------------------------------------
// Test if exception is properly thrown when at is out of bound.

void test_case_4_at_out_of_bound()
{
  std::printf( "\n%s\n", __func__ );

  int data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };

  // Try access an empty image

  bool flag = false;
  try {
    Image img;
    img.at( 0, 0 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // Try out of bound access - right at the boundary

  flag = false;
  try {
    Image img( Vector<int>( data, 8 ), 2, 4 );
    img.at( 2, 4 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // Try out of bound access - beyond the boundary

  flag = false;
  try {
    Image img( Vector<int>( data, 8 ), 2, 4 );
    img.at( 3, 1 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_5_label
//------------------------------------------------------------------------
// Test if label related functions.

void test_case_5_label()
{
  std::printf( "\n%s\n", __func__ );

  // Check if the label for empty image is initialized properly
  Image empty_img;
  UTST_ASSERT_TRUE( empty_img.get_label() == '?' );

  // Construct an image
  int   data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  Image img    = Image( Vector<int>( data, 8 ), 4, 2 );

  // Check if label is initialized properly
  UTST_ASSERT_TRUE( img.get_label() == '?' );

  // Set label and check

  img.set_label( 'o' );

  UTST_ASSERT_TRUE( img.get_label() == 'o' );

  img.set_label( 'y' );
  img.set_label( 'h' );

  UTST_ASSERT_TRUE( img.get_label() == 'h' );
}

//------------------------------------------------------------------------
// test_case_6_intensity
//------------------------------------------------------------------------
// Test get_intensity.

void test_case_6_intensity()
{
  std::printf( "\n%s\n", __func__ );

  // Construct vectors

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  Vector<int> vec0( data0, 8 );

  int data1[] = { 1, 9, 9, 4, 0, 9, 1, 7 }; // sum 40
  Vector<int> vec1( data1, 8 );

  int data2[] = { 1, 9, 9, 3, 0, 8, 2, 0 }; // sum 32
  Vector<int> vec2( data2, 8 );

  // Construct images

  Image img0( vec0, 2, 4 );
  Image img1( vec1, 2, 4 );
  Image img2( vec2, 2, 4 );

  // Check intensity

  UTST_ASSERT_INT_EQ( img0.get_intensity(), 33 );
  UTST_ASSERT_INT_EQ( img1.get_intensity(), 40 );
  UTST_ASSERT_INT_EQ( img2.get_intensity(), 32 );

  // Check the intensity of empty image

  UTST_ASSERT_INT_EQ( Image().get_intensity(), 0 );
}

//------------------------------------------------------------------------
// test_case_7_minus
//------------------------------------------------------------------------
// Test the minus operator.

void test_case_7_minus()
{
  std::printf( "\n%s\n", __func__ );

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  int data1[] = { 1, 9, 9, 4, 0, 9, 1, 7 }; // sum 40

  // Calculate the distance
  int dist = 0;
  for( int i = 0; i < 8; i++ )
    dist += ( data0[i] - data1[i] ) * ( data0[i] - data1[i] );

  // Construct images
  Image img0 = Image( Vector<int>( data0, 8 ), 2, 4 );
  Image img1 = Image( Vector<int>( data1, 8 ), 2, 4 );

  // Check distance
  UTST_ASSERT_INT_EQ( img0 - img1, dist );

  // Check empty images
  UTST_ASSERT_INT_EQ( Image() - Image(), 0 );
}

//------------------------------------------------------------------------
// test_case_8_minus_mismatch
//------------------------------------------------------------------------
// Test if exception is properly thrown when the size of two images does
// not match.

void test_case_8_minus_mismatch()
{
  std::printf( "\n%s\n", __func__ );

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  int data1[] = { 1, 9, 9, 4, 0, 9, 1, 7 }; // sum 40

  // Both dimension does not match

  bool flag = false;
  try {
    Image img0 = Image( Vector<int>( data0, 8 ), 2, 4 );
    Image img1 = Image( Vector<int>( data1, 8 ), 4, 2 );
    img0 - img1;
  }
  catch ( ece2400::InvalidArgument e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // Only ncols does not match

  flag = false;
  try {
    Image img0 = Image( Vector<int>( data0, 8 ), 2, 4 );
    Image img1 = Image( Vector<int>( data1, 4 ), 1, 4 );
    img0 - img1;
  }
  catch ( ece2400::InvalidArgument e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // Only nrows does not match

  flag = false;
  try {
    Image img0 = Image( Vector<int>( data0, 8 ), 2, 4 );
    Image img1 = Image( Vector<int>( data1, 6 ), 2, 3 );
    img0 - img1;
  }
  catch ( ece2400::InvalidArgument e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_9_compare_same_dim
//------------------------------------------------------------------------
// Test <, <=, >, and >= operators on images whose dimensions match.

void test_case_9_compare_same_dim()
{
  std::printf( "\n%s\n", __func__ );

  // Construct images

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  Vector<int> vec0( data0, 8 );
  Image img0( vec0, 2, 4 );

  int data1[] = { 1, 9, 9, 3, 0, 8, 2, 0 }; // sum 32
  Vector<int> vec1( data1, 8 );
  Image img1( vec1, 2, 4 );

  int data2[] = { 1, 9, 9, 6, 0, 4, 2, 1 }; // sum 32
  Vector<int> vec2( data2, 8 );
  Image img2( vec2, 2, 4 );

  // Check comparison

  UTST_ASSERT_TRUE ( img1 <  img0 );
  UTST_ASSERT_FALSE( img2 <  img1 );
  UTST_ASSERT_TRUE ( img1 <= img0 );
  UTST_ASSERT_TRUE ( img2 <= img1 );
  UTST_ASSERT_TRUE ( img0 >  img1 );
  UTST_ASSERT_FALSE( img1 >  img2 );
  UTST_ASSERT_TRUE ( img0 >= img1 );
  UTST_ASSERT_TRUE ( img1 >= img2 );
  UTST_ASSERT_TRUE ( img0 != img2 );
}

//------------------------------------------------------------------------
// test_case_10_compare_diff_dim
//------------------------------------------------------------------------
// Test <, <=, >, and >= operators on images whose dimensions does not
// match.

void test_case_10_compare_diff_dim()
{
  std::printf( "\n%s\n", __func__ );

  // Construct images

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  Vector<int> vec0( data0, 8 );
  Image img0( vec0, 2, 4 );

  int data1[] = { 1, 9, 9, 5, 0, 8, 2, 0 }; // sum 32
  Vector<int> vec1( data1, 6 );
  Image img1( vec1, 2, 3 );

  int data2[] = { 1, 9, 9, 6, 0, 4, 2, 1 }; // sum 32
  Vector<int> vec2( data2, 8 );
  Image img2( vec2, 4, 2 );

  // Check comparison

  UTST_ASSERT_TRUE ( img1 <  img0 );
  UTST_ASSERT_FALSE( img2 <  img1 );
  UTST_ASSERT_TRUE ( img1 <= img0 );
  UTST_ASSERT_TRUE ( img2 <= img1 );
  UTST_ASSERT_TRUE ( img0 >  img1 );
  UTST_ASSERT_FALSE( img1 >  img2 );
  UTST_ASSERT_TRUE ( img0 >= img1 );
  UTST_ASSERT_TRUE ( img1 >= img2 );
  UTST_ASSERT_TRUE ( img0 != img2 );
}

//------------------------------------------------------------------------
// test_case_11_equality_same_dim
//------------------------------------------------------------------------
// Test== and != operator on images whose dimension match.

void test_case_11_equality_same_dim()
{
  std::printf( "\n%s\n", __func__ );

  // Construct images

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  Vector<int> vec0( data0, 8 );
  Image img0( vec0, 2, 4 );

  int data1[] = { 1, 9, 9, 3, 0, 8, 2, 0 }; // sum 32
  Vector<int> vec1( data1, 8 );
  Image img1( vec1, 2, 4 );

  int data2[] = { 1, 9, 9, 6, 0, 4, 2, 1 }; // sum 32
  Vector<int> vec2( data2, 8 );
  Image img2( vec2, 2, 4 );

  // Check inequality and equality

  UTST_ASSERT_TRUE ( img0 != img2 );
  UTST_ASSERT_TRUE ( img1 != img2 );
  UTST_ASSERT_TRUE ( img0 != img1 );

  UTST_ASSERT_TRUE ( img0 == Image( Vector<int>( data0, 8 ), 2, 4 ) );
  UTST_ASSERT_TRUE ( img1 == Image( Vector<int>( data1, 8 ), 2, 4 ) );
  UTST_ASSERT_TRUE ( img2 == Image( Vector<int>( data2, 8 ), 2, 4 ) );
}

//------------------------------------------------------------------------
// test_case_12_equality_diff_dim
//------------------------------------------------------------------------
// Test== and != operator on images whose dimension match.

void test_case_12_equality_diff_dim()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image

  int data[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  Image img = Image( Vector<int>( data, 8 ), 2, 4 );

  // Check inequality

  UTST_ASSERT_TRUE( img != Image( Vector<int>( data, 6 ), 2, 3 ) );
  UTST_ASSERT_TRUE( img != Image( Vector<int>( data, 8 ), 4, 2 ) );
  UTST_ASSERT_TRUE( img != Image( Vector<int>( data, 4 ), 1, 4 ) );
}

//------------------------------------------------------------------------
// test_case_13_copy_v1
//------------------------------------------------------------------------
// Test the copy constructor with first syntax.

void test_case_13_copy_v1()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  int data[] = { 1, 9, 9, 5 };
  Vector<int> vec( data, 4 );
  Image img0( vec, 2, 2 );

  // Mutate the data array
  for ( int& v : data )
    v = 0xfaceb00c;

  // Mutate the vector
  vec = Vector<int>();

  // Set a label to img0
  img0.set_label( '1' );

  // Use copy constructor
  Image img1 = Image( img0 );

  // Check if the data in both images

  UTST_ASSERT_INT_EQ( img0.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 1 ), 5 );

  UTST_ASSERT_INT_EQ( img1.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 1 ), 5 );

  UTST_ASSERT_TRUE( img0.get_label() == '1' );
  UTST_ASSERT_TRUE( img1.get_label() == '1' );
}

//------------------------------------------------------------------------
// test_case_14_copy_v2
//------------------------------------------------------------------------
// Test the copy constructor with second syntax.

void test_case_14_copy_v2()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  int data[] = { 1, 9, 9, 5 };
  Vector<int> vec( data, 4 );
  Image img0( vec, 2, 2 );

  // Mutate the data array
  for ( int& v : data )
    v = 0xfaceb00c;

  // Mutate the vector
  vec = Vector<int>();

  // Set a label to img0
  img0.set_label( '1' );

  // Use copy constructor
  Image img1 = img0;

  // Check if the data in both images

  UTST_ASSERT_INT_EQ( img0.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 1 ), 5 );

  UTST_ASSERT_INT_EQ( img1.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 1 ), 5 );

  UTST_ASSERT_TRUE( img0.get_label() == '1' );
  UTST_ASSERT_TRUE( img1.get_label() == '1' );
}

//------------------------------------------------------------------------
// test_case_15_copy_empty
//------------------------------------------------------------------------
// Test the copy constructor with empty Image.

void test_case_15_copy_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Copy constructor
  Image img0;
  Image img1 = img0;

  // Check both images are empty
  UTST_ASSERT_INT_EQ( img0.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img0.get_nrows(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_nrows(), 0 );
}

//------------------------------------------------------------------------
// test_case_16_assignment
//------------------------------------------------------------------------
// Test assignment operator on non-empty images.

void test_case_16_assignment()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  int data0[] = { 1, 9, 9, 5 };
  Vector<int> vec0( data0, 4 );
  Image img0( vec0, 2, 2 );
  img0.set_label( '1' );

  // Mutate the data array and vector
  for ( int& v : data0 )
    v = 0xfaceb00c;
  vec0 = Vector<int>();

  // Construct image
  int data1[] = { 10, 90, 90, 50 };
  Vector<int> vec1( data1, 4 );
  Image img1( vec1, 2, 2 );
  img1.set_label( '2' );

  // Mutate the data array and vector
  for ( int& v : data1 )
    v = 0xfaceb00c;
  vec1 = Vector<int>();

  // Use assignment operator
  img1 = img0;

  // Check if the data in both images

  UTST_ASSERT_INT_EQ( img0.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 1 ), 5 );

  UTST_ASSERT_INT_EQ( img1.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 1 ), 5 );

  UTST_ASSERT_TRUE( img0.get_label() == '1' );
  UTST_ASSERT_TRUE( img1.get_label() == '1' );
}

//------------------------------------------------------------------------
// test_case_17_assignment_to_empty
//------------------------------------------------------------------------
// Test assignment operator to empty image.

void test_case_17_assignment_to_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  int data0[] = { 1, 9, 9, 5 };
  Vector<int> vec0( data0, 4 );
  Image img0( vec0, 2, 2 );
  img0.set_label( '1' );

  // Mutate the data array and vector
  for ( int& v : data0 )
    v = 0xfaceb00c;
  vec0 = Vector<int>();

  // Use assignment operator
  Image img1;
  img1 = img0;

  // Check if the data in both images

  UTST_ASSERT_INT_EQ( img0.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img0.at( 1, 1 ), 5 );

  UTST_ASSERT_INT_EQ( img1.at( 0, 0 ), 1 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 0 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 0, 1 ), 9 );
  UTST_ASSERT_INT_EQ( img1.at( 1, 1 ), 5 );

  UTST_ASSERT_TRUE( img0.get_label() == '1' );
  UTST_ASSERT_TRUE( img1.get_label() == '1' );
}

//------------------------------------------------------------------------
// test_case_18_assignment_from_empty
//------------------------------------------------------------------------
// Test assignment operator from empty image.

void test_case_18_assignment_from_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  Image img0;

  // Construct image
  int data1[] = { 10, 90, 90, 50 };
  Vector<int> vec1( data1, 4 );
  Image img1( vec1, 2, 2 );
  img1.set_label( '2' );

  // Mutate the data array and vector
  for ( int& v : data1 )
    v = 0xfaceb00c;
  vec1 = Vector<int>();

  // Use assignment operator
  img1 = img0;

  // Check both images are empty
  UTST_ASSERT_INT_EQ( img0.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img0.get_nrows(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_nrows(), 0 );
}

//------------------------------------------------------------------------
// test_case_19_assignment_empty
//------------------------------------------------------------------------
// Test assignment operator to/from empty image.

void test_case_19_assignment_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Construct image
  Image img0;
  Image img1;

  // Use assignment operator
  img1 = img0;

  // Check both images are empty
  UTST_ASSERT_INT_EQ( img0.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img0.get_nrows(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_ncols(), 0 );
  UTST_ASSERT_INT_EQ( img1.get_nrows(), 0 );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1  ) ) test_case_1_basic();
  if ( ( __n == 0 ) || ( __n == 2  ) ) test_case_2_default_constructor();
  if ( ( __n == 0 ) || ( __n == 3  ) ) test_case_3_construct_size_mismatch();
  if ( ( __n == 0 ) || ( __n == 4  ) ) test_case_4_at_out_of_bound();
  if ( ( __n == 0 ) || ( __n == 5  ) ) test_case_5_label();
  if ( ( __n == 0 ) || ( __n == 6  ) ) test_case_6_intensity();
  if ( ( __n == 0 ) || ( __n == 7  ) ) test_case_7_minus();
  if ( ( __n == 0 ) || ( __n == 8  ) ) test_case_8_minus_mismatch();
  if ( ( __n == 0 ) || ( __n == 9  ) ) test_case_9_compare_same_dim();
  if ( ( __n == 0 ) || ( __n == 10 ) ) test_case_10_compare_diff_dim();
  if ( ( __n == 0 ) || ( __n == 11 ) ) test_case_11_equality_same_dim();
  if ( ( __n == 0 ) || ( __n == 12 ) ) test_case_12_equality_diff_dim();
  if ( ( __n == 0 ) || ( __n == 13 ) ) test_case_13_copy_v1();
  if ( ( __n == 0 ) || ( __n == 14 ) ) test_case_14_copy_v2();
  if ( ( __n == 0 ) || ( __n == 15 ) ) test_case_15_copy_empty();
  if ( ( __n == 0 ) || ( __n == 16 ) ) test_case_16_assignment();
  if ( ( __n == 0 ) || ( __n == 17 ) ) test_case_17_assignment_to_empty();
  if ( ( __n == 0 ) || ( __n == 18 ) ) test_case_18_assignment_from_empty();
  if ( ( __n == 0 ) || ( __n == 19 ) ) test_case_19_assignment_empty();

  printf("\n");
  return 0;
}
