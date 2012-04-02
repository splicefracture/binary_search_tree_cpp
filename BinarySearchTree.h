#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "dsexceptions.h"
#include <iostream>       // For NULL
#include <vector>

using namespace std;

// Binary node and forward declaration because g++ does
// not understand nested classes.
template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
  Comparable element;
  BinaryNode *left;
  BinaryNode *right;
  
  BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element( theElement ), left( lt ), right( rt ) { }
  friend class BinarySearchTree<Comparable>;
};


// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

template <class Comparable>
class BinarySearchTree
{
 public:
  explicit BinarySearchTree( const Comparable & notFound );
  BinarySearchTree( const BinarySearchTree & rhs );
  ~BinarySearchTree( );
  
  const Comparable & findMin( ) const;
  const Comparable & findMax( ) const;
  const Comparable & find( const Comparable & x ) const;
  bool isEmpty( ) const;
  void printTree( ) const;
  
  void Union(const BinarySearchTree& rhs);
  void Intersection(const BinarySearchTree& tree1, 
		    const BinarySearchTree& tree2);

  bool IsPerfect();
  bool IsComplete();

  int IPL();
  int EPL();

  bool Same_Shape(const BinarySearchTree& rhs);

  void makeEmpty( );
  void insert( const Comparable & x );
  void remove( const Comparable & x );
  
  const BinarySearchTree & operator=( const BinarySearchTree & rhs );

  int size( ) const;
  
 private:

  BinaryNode<Comparable> *root;
  const Comparable ITEM_NOT_FOUND;

  void Intersection(BinaryNode<Comparable> *t1, BinaryNode<Comparable> *t2);
  void Union(BinaryNode<Comparable> *t);

  bool IsPerfect(BinaryNode<Comparable> *t, bool truth);
  bool IsComplete(BinaryNode<Comparable> *t, bool truth, bool isLeft,
		  int currDepth, int leftDepth);

  int IPL(BinaryNode<Comparable> *t, int counter, int depth);
  int EPL(BinaryNode<Comparable> *t, int counter, int depth);

  void FindShape(BinaryNode<Comparable> *t, vector <int>& shape, int depth);

  const Comparable & elementAt( BinaryNode<Comparable> *t ) const;
  
  void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
  void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
  BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
  BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
  BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
  void makeEmpty( BinaryNode<Comparable> * & t ) const;
  void printTree( BinaryNode<Comparable> *t ) const;


  BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;

  int size(BinaryNode<Comparable> *t) const;

};

#include "BinarySearchTree.cpp"
#endif
