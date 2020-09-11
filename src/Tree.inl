//========================================================================
// Tree.inl
//========================================================================
// Implementation of Tree.

#include "ece2400-stdlib.h"
#include <cassert>
#include <iostream>
#include "Tree.h"

#define LEFT 0
#define RIGHT 1
// – Step 3a. Implement and test the default constructor, destructor, add, size, find
// – Step 3b. Implement and test find_closest
// – Step 3c. Implement and test the copy constructor
// – Step 3d. Implement and test the assignment operator

//========================================================================
// Tree<T>::Tree<T>( unsigned int K )
//========================================================================
// Default constructor for Tree<T>

template <typename T>
Tree<T>::Tree( unsigned int K )
    : m_root( nullptr ), m_size( 0 ), m_K( K )
{
}

//========================================================================
// Tree<T>::Tree( const Tree<T>& tree )
//========================================================================
// Copy constructor
// deep copy
template <typename T>
Tree<T>::Tree( const Tree<T>& tree )
{
  // // m_size = tree.m_size;
  // m_K    = tree.m_K;
  // m_root = nullptr;  // why do I need to reassign field's value
  // m_size = 0;
  // addtree( tree.m_root );

  // deep copy the tree using recursion
  // copy from curr1 to curr2
  m_root      = nullptr;
  Node* curr1 = tree.m_root;
  // Node* curr2 = m_root;
  copy( curr1, m_root );
  m_K    = tree.m_K;
  m_size = tree.m_size;
}

template <typename T>
void Tree<T>::addtree( Node* node )
{
  if ( node != nullptr ) {
    add( node->value );
    addtree( node->left );
    addtree( node->right );
  }
}

//========================================================================
// Tree<T>::˜Tree<T>
//========================================================================
// Destructor for Tree<T>
// need to make pointer point to 0x0
// [][][]when we call delete, it's deleting
template <typename T>
Tree<T>::~Tree<T>()
{
  RemoveSubtree( m_root );
  // m_root = nullptr;
  m_K    = 0;  // unnecessary
  m_size = 0;
  // std::cout<<"-----tree deconstructed-----"<<std::endl;
  // print();
  // std::cout<<"-----tree deconstructed-----"<<std::endl;
}

template <typename T>
void Tree<T>::RemoveSubtree( Node* node_p )
{
  if ( node_p != nullptr ) {
    RemoveSubtree( node_p->left );
    RemoveSubtree( node_p->right );
    // node_p->left  = nullptr;
    // node_p->right = nullptr;
    delete node_p;
    // m_size--;  // actually unnecessary
  }
}

//========================================================================
// void Tree<T>::add( const T& value )
//========================================================================
// Destructor for Tree<T>
// be careful of < > = when type is Image:
//    if image intensity is equal to the nodetocheck, but the image is not == to the nodevalue
//    the image will be add to the right of the nodetocheck
template <typename T>
void Tree<T>::add( const T& value )
{
  if ( m_root == nullptr ) {
    m_root = new Node( value );
    m_size++;
    // print();
    return;
  }

  if ( m_root->value == value )
    return;

  if ( value < m_root->value ) {
    add_h( m_root->left, value, m_root, LEFT );
  }
  else {  // don't forget this else!! we didn't find this bug because the add test was in the increasing order!!
    add_h( m_root->right, value, m_root, RIGHT );
  }
}

template <typename T>
void Tree<T>::add_h( Node* nodetocheck, T value, Node* parentnode, int leftright )
{
  // base case
  if ( nodetocheck == nullptr ) {
    insert( nodetocheck, value, parentnode, leftright );
    // print();
    return;
  }
  if ( nodetocheck->value == value ) {
    return;  //duplicate
  }
  // recursion
  if ( value < nodetocheck->value ) {
    add_h( nodetocheck->left, value, nodetocheck, LEFT );  //node to check, value, parent node, leftorright
  }
  else {
    add_h( nodetocheck->right, value, nodetocheck, RIGHT );
  }
}

template <typename T>
void Tree<T>::insert( Node* nodetoinsert, T value, Node* parentnode, int leftright )
{
  nodetoinsert = new Node( value );
  m_size++;
  // connect to parent node
  if ( leftright == LEFT ) {
    parentnode->left = nodetoinsert;
  }
  else {
    parentnode->right = nodetoinsert;
  }
}

//========================================================================
// size_t   Tree<T>::size() const;
//========================================================================
template <typename T>
size_t Tree<T>::size() const
{
  return m_size;
}

//========================================================================
// bool Tree<T>::find( const T& value ) const
//========================================================================
template <typename T>
bool Tree<T>::find( const T& value ) const
{
  if ( m_root == nullptr )
    return false;
  bool flag = false;
  find_h( m_root, value, flag );
  return flag;
}

template <typename T>
void Tree<T>::find_h( Node* node, const T& value, bool& flag ) const
{
  if ( node == nullptr )
    return;
  if ( flag == true )
    return;
  if ( node->value == value )
    flag = true;
  find_h( node->left, value, flag );
  find_h( node->right, value, flag );
}

//========================================================================
// const T& Tree<T>::find_closest( const T& value ) const
//========================================================================
// return the value that has (approximately) the smallest difference
// from the given value
// binary search and exhaustive search
// ece2400::abs_dist
// work for both int and Image

template <typename T>
const T& Tree<T>::find_closest( const T& value ) const
{
  int N = size();
  if ( N == 0 ) {
    const char* err_msg = "Tree is empty, can't exec find_closest";
    throw ece2400::OutOfRange( err_msg );
  }
  int K       = getK();
  int b_level = 0;
  if ( N > K ) {
    b_level = ece2400::log2( N ) - ece2400::log2( K );
  }
  else {  // when K is too large
    b_level = 0;
  }

  Node* b_res_node = binary_search( m_root, b_level, value );
  if ( b_res_node->value == value )
    return value;
  const T* e_res = exhaustive_search( b_res_node, value );

  return *e_res;
}

template <typename T>
int Tree<T>::getK() const
{
  return m_K;
}

template <typename T>
void Tree<T>::setK( unsigned int K )
{
  m_K = K;
}

// binary search
// through levels: logN - logK
// intensity
//https://stackoverflow.com/questions/6571381/dependent-scope-and-nested-templates/6571836
template <typename T>
typename Tree<T>::Node* Tree<T>::binary_search( Node* node, int level, const T& value ) const
{
  //base case
  if ( level == 0 )
    return node;
  if ( node->value == value )
    return node;

  //recursion
  if ( value < node->value )
    return binary_search( node->left, level - 1, value );

  return binary_search( node->right, level - 1, value );
}

// exhaustive search
// through levels: logK
// Euclidean distance
// return the value!
// use preorder traverse
// assume the tree to be perfectly balanced
//
template <typename T>
T* Tree<T>::exhaustive_search( Node* node, const T& value ) const
{
  T* lvalue = &( node->value );
  T* rvalue = &( node->value );
  if ( node->left != nullptr )
    lvalue = exhaustive_search( node->left, value );
  if ( node->right != nullptr )
    rvalue = exhaustive_search( node->right, value );

  int ldist = ece2400::abs_dist( *lvalue, value );
  int rdist = ece2400::abs_dist( *rvalue, value );
  int pdist = ece2400::abs_dist( node->value, value );

  T* result = lvalue;
  if ( ldist > rdist ) {
    result = rvalue;
    if ( rdist > pdist ) {
      result = &node->value;
    }
  }
  else {
    if ( ldist > pdist ) {
      result = &node->value;
    }
  }
  return result;
}

//========================================================================
//  void Tree<T>::print() const
//========================================================================

template <typename T>
void Tree<T>::print() const
{
  print_h( m_root, 0 );
}

template <typename T>
void Tree<T>::print_h( Node* node, int level ) const
{
  if ( node == nullptr )
    return;

  print_h( node->right, level + 1 );

  for ( int i = 0; i < level; i++ )
    std::cout << "|";
  std::cout << node->value << std::endl;

  print_h( node->left, level + 1 );
}

//========================================================================
//  Tree<T>& operator=( const Tree<T>& tree )
//========================================================================

template <typename T>
Tree<T>& Tree<T>::operator=( const Tree<T>& tree )
{
  // self assignment
  if ( m_root == tree.m_root )
    return *this;

  // Delete original tree
  if ( m_root != nullptr ) {
    RemoveSubtree( m_root );
    //print();
  }

  m_K    = tree.m_K;
  m_root = nullptr;
  m_size = 0;
  addtree( tree.m_root );

  return *this;
}

template <typename T>
void Tree<T>::copy( Node*& curr1, Node*& curr2 )
{
  if ( curr1 == nullptr )
    return;
  curr2 = new Node( curr1->value );  // wrong but should have one node
  std::cout << "-----new Node-----" << std::endl;
  print_h( curr2, 0 );  // nothing in here
  std::cout << "------------------" << std::endl;
  // m_size++;
  //print();
  copy( curr1->left, curr2->left );
  copy( curr1->right, curr2->right );
}
// didn't connect left right pointers to nodes! why??