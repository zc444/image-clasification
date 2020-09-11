//========================================================================
// Vector.h
//========================================================================
// Declarations for Vector.
// return type:
// int-> const T&
// VectorInt -> Vector<T>
//int    at( size_t idx ) const;
//       -> const T& at( size_t idx ) const;
//       ->  T&       at( size_t idx );

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <iostream>

template <typename T>
class Vector {
 public:
  Vector();
  ~Vector();

  // Copy constructor
  Vector( const Vector<T>& vec );

  // Construct from an array
  Vector( T* array, size_t size );

  // Methods
  size_t   size() const;
  void     push_back( const T& value );
  const T& at( size_t idx ) const;
  T&       at( size_t idx );
  bool     find( const T& value ) const;
  const T& find_closest( const T& value ) const;
  // void     find_closest_parallel( const T& value, size_t lo, size_t hi, Vector<T>& res ) const;
  void find_closest_parallel( const T& value, size_t lo, size_t hi, int* res ) const;
  void     sort();
  void     print() const;

  // Operator overloading
  const T&   operator[]( size_t idx ) const;
  T&         operator[]( size_t idx );
  Vector<T>& operator=( const Vector<T>& vec );
  T* get_array_p();

 private:
  size_t m_size;
  size_t m_maxsize;
  T*     m_array;
};

// Include inline definitions
#include "Vector.inl"

#endif  // VECTOR_H
