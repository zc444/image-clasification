//========================================================================
// Tree.h
//========================================================================
// Declarations for generic tree.

#ifndef TREE_H
#define TREE_H

#include <cstddef>

template <typename T>
class Tree {
 private:
  struct Node {
    //Node( T v ) : value( v ), left( nullptr ), right( nullptr ) {}
    Node( T v ){
      value = v;
      left = nullptr;
      right = nullptr;
    } 
    T     value;
    Node* left;
    Node* right;
  };

 public:
  Tree( unsigned int K = 0 );
  ~Tree();

  // Copy constructor
  Tree( const Tree<T>& tree );

  // Methods
  size_t   size() const;
  void     add( const T& value );
  bool     find( const T& value ) const;
  const T& find_closest( const T& value ) const;
  void     print() const;
  int      getK() const;
  void     setK(unsigned int K);

  // Operator overloading
  Tree<T>& operator=( const Tree<T>& tree );

 private:
  // helper function
  void RemoveSubtree( Node* node_p );
  void add_h( Node* nodetocheck, T value, Node* parentnode, int leftright );
  void insert( Node* nodetoinsert, T value, Node* parentnode, int leftright );
  //void size_h( Node* node, size_t& count ) const;
  void           find_h( Node* node, const T& value, bool& flag ) const;
  Tree<T>::Node* binary_search( Node* node, int level, const T& value ) const;  //const Tree<T>::Node*
  T*             exhaustive_search( Node* node, const T& value ) const;
  void           print_h( Node* node, int level ) const;
  void           copy( Node*& curr1, Node*& curr2 );
  void           addtree( Node* node );
  Node*          m_root;
  size_t         m_size;
  unsigned int   m_K;
};

// Include inline definitions
#include "Tree.inl"

#endif /* TREE_H */
