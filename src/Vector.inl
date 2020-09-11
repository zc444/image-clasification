//========================================================================
// Vector.inl
//========================================================================
// Implementation of Vector.

#include "ece2400-stdlib.h"
#include "sort.h"
#include "Vector.h"
class Image;

//========================================================================
// Vector<T>::Vector()
//========================================================================
// default constructor

template <typename T>
Vector<T>::Vector()
{
  m_size    = 0;
  m_maxsize = 0;
  m_array   = nullptr;
}

//========================================================================
// Vector<T>::Vector( T* arr, size_t size )
//========================================================================
// non-default constructor

template <typename T>
Vector<T>::Vector( T* arr, size_t size )
{
  if ( size == 0 ) {
    m_size    = 0;
    m_maxsize = 0;
    m_array   = nullptr;
  }
  else {
    // init m_array
    m_array = new T[size];
    for ( size_t i = 0; i < size; i++ )
      m_array[i] = arr[i];

    // init m_size and m_maxsize
    m_size    = size;
    m_maxsize = size;
  }
}

//========================================================================
// Vector<T>::~Vector()
//========================================================================
// Destructor for Vector<T>

template <typename T>
Vector<T>::~Vector()
{
  delete[] m_array;
  m_size    = 0;
  m_maxsize = 0;
}

//========================================================================
// Vector<T>::Vector( const Vector<T>& vec )
//========================================================================
// Copy constructor

template <typename T>
Vector<T>::Vector( const Vector<T>& vec )
{
  m_size    = vec.m_size;
  m_maxsize = vec.m_maxsize;
  m_array   = new T[m_maxsize];
  for ( size_t i = 0; i < m_size; i++ )
    m_array[i] = vec.m_array[i];
}

//========================================================================
// Vector<T>& Vector<T>::operator=( const Vector<T>& vec )
//========================================================================
// Overloads the assignment operator, copy the values stored in vec

template <typename T>
Vector<T>& Vector<T>::operator=( const Vector<T>& vec )
{
  if ( vec.m_array == m_array )
    return *this;

  delete[] m_array;

  m_size    = vec.m_size;
  m_maxsize = vec.m_maxsize;
  m_array   = new T[m_maxsize];
  for ( size_t i = 0; i < m_size; i++ )
    m_array[i] = vec.m_array[i];
  return *this;
}

//========================================================================
// size_t Vector<T>::size() const
//========================================================================
// Return the current number of elements in the vector

template <typename T>
size_t Vector<T>::size() const
{
  return m_size;
}

//========================================================================
// void Vector<T>::push_back( const T& value )
//========================================================================
// Push a new element with the given value value onto the end of the Vector<T>

template <typename T>
void Vector<T>::push_back( const T& value )
{
  if ( m_maxsize == 0 ) {
    // init m_maxsize as 1, m_size as 1, m_array[0] as value
    delete[] m_array;
    T* data   = new T[1];
    data[0]   = value;
    m_array   = data;
    m_maxsize = 1;
    m_size    = 1;
  }
  else if ( m_maxsize == m_size ) {
    // double space
    T* data = new T[m_maxsize * 2];
    // copy old values
    for ( size_t i = 0; i < m_size; i++ )
      data[i] = m_array[i];
    // enter the new value
    data[m_size] = value;
    // delete old m_array's space
    delete[] m_array;
    // update fields
    m_array = data;
    m_size += 1;
    m_maxsize = m_maxsize * 2;
  }
  else if ( m_maxsize > m_size ) {
    m_array[m_size] = value;
    m_size++;
  }
}

//========================================================================
// const T& Vector<T>::at( size_t idx ) const
//========================================================================
// access an element in the vector for _reading_
//https://piazza.com/class/jzxjad5243k1kl?cid=517

template <typename T>
const T& Vector<T>::at( size_t idx ) const
{
  if ( idx >= m_size ) {
    char const* err_msg = "Access out of bound";
    throw ece2400::OutOfRange( err_msg );
  }
  return m_array[idx];
}

//========================================================================
// T& Vector<T>::at( size_t idx )
//========================================================================
// access an element in the vector for _writing_
//https://piazza.com/class/jzxjad5243k1kl?cid=517

template <typename T>
T& Vector<T>::at( size_t idx )
{
  if ( idx >= m_size ) {
    char const* err_msg = "Access out of bound";
    throw ece2400::OutOfRange( err_msg );
  }
  return m_array[idx];
}

//========================================================================
// bool Vector<T>::find( const T& value ) const
//========================================================================
// Search the Vector<T> for the given value
// Returns true if the value is found and false otherwise.

template <typename T>
bool Vector<T>::find( const T& value ) const
{
  for ( size_t i = 0; i < m_size; i++ ) {
    if ( m_array[i] == value )
      return true;
  }
  return false;
}

//========================================================================
// const T& Vector<T>::find_closest( const T& value ) const
//========================================================================
// Search the Vector<T> and returns the value that has the smallest difference from the given value.
// If multiple values have the same difference, return the one that has the lowest index.

template <typename T>
const T& Vector<T>::find_closest( const T& value ) const
{
  if ( m_size == 0 ) {
    char const* err_msg = "the VectorInt is empty, cannot find closest";
    throw ece2400::OutOfRange( err_msg );
  }

  // init min value and number to return
  int    min = ece2400::abs_dist( m_array[0], value );
  int    tmp;
  size_t idx = 0;

  // iterate through vector, update min and number
  for ( size_t i = 0; i < m_size; i++ ) {
    tmp = ece2400::abs_dist( m_array[i], value );
    if ( tmp < min ) {
      min = tmp;
      idx = i;
    }
  }
  return m_array[idx];
}

template <typename T>
void Vector<T>::find_closest_parallel( const T& value, size_t lo, size_t hi, int* res ) const
{
  if ( m_size == 0 ) {
    char const* err_msg = "the VectorInt is empty, cannot find closest";
    throw ece2400::OutOfRange( err_msg );
  }

  // init min value and number to return
  int    min = ece2400::abs_dist( m_array[0], value );
  int    tmp;
  size_t res_idx = 0;

  // iterate through vector, update min and number
  for ( size_t i = lo; i < hi; i++ ) {
    tmp = ece2400::abs_dist( m_array[i], value );
    if ( tmp < min ) {
      min     = tmp;
      res_idx = i;
    }
  }
  // res.push_back( this->at(res_idx) );
  *res = res_idx;
}

// template <typename T>
// void Vector<T>::find_closest_parallel( const T& value, size_t lo, size_t hi, Vector<T>& res ) const
// {
//   if ( m_size == 0 ) {
//     char const* err_msg = "the VectorInt is empty, cannot find closest";
//     throw ece2400::OutOfRange( err_msg );
//   }

//   // init min value and number to return
//   int    min = ece2400::abs_dist( m_array[0], value );
//   int    tmp;
//   size_t res_idx = 0;

//   // iterate through vector, update min and number
//   for ( size_t i = lo; i < hi; i++ ) {
//     tmp = ece2400::abs_dist( m_array[i], value );
//     if ( tmp < min ) {
//       min     = tmp;
//       res_idx = i;
//     }
//   }
//   // std::cout << "-------------print img----------" << std::endl;
//   // this->at( res_idx ).print();
//   res.push_back( this->at( res_idx ) );
// }

//========================================================================
// void Vector<T>::sort()
//========================================================================
// Sort the internal array in ascending order

template <typename T>
void Vector<T>::sort()
{
  ::sort( m_array, m_size );
}

//========================================================================
// const T& Vector<T>::operator[]( size_t idx ) const
//========================================================================
// Return the value at the given index idx of the vector without any boundary check.
// for _reading_

template <typename T>
const T& Vector<T>::operator[]( size_t idx ) const
{
  return m_array[idx];
}

//========================================================================
// const T& Vector<T>::operator[]( size_t idx ) const
//========================================================================
// Return the value at the given index idx of the vector without any boundary check.
// for _writing_

template <typename T>
T& Vector<T>::operator[]( size_t idx )
{
  return m_array[idx];
}

//========================================================================
// void Vector<T>::print() const
//========================================================================
// For debugging

template <typename T>
void Vector<T>::print() const
{
  // ece2400::print_array( m_array, m_size );
}

//----------------------------------------


template <typename T>
T* Vector<T>::get_array_p()
{
  return m_array;
}
