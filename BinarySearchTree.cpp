#include "BinarySearchTree.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Implements an unbalanced binary search tree.
 * Note that all "matching" is based on the < method.
 */

/**
 * Construct the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( const Comparable & notFound ) :
   root(NULL), ITEM_NOT_FOUND( notFound )
{
}


/**
 * Copy constructor.
 */
template <class Comparable>
BinarySearchTree<Comparable>::
BinarySearchTree( const BinarySearchTree<Comparable> & rhs ) :
  root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{ 
  *this = rhs;
}

/**
 * Destructor for the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree( )
{
  makeEmpty( );
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x )
{
  insert( x, root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x )
{
  remove( x, root );
}


/**
 * Find the smallest item in the tree.
 * Return smallest item or ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin( ) const
{
  return elementAt( findMin( root ) );
}

/**
 * Find the largest item in the tree.
 * Return the largest item of ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax( ) const
{
  return elementAt( findMax( root ) );
}

/**
 * Find item x in the tree.
 * Return the matching item or ITEM_NOT_FOUND if not found.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
find( const Comparable & x ) const
{
  return elementAt( find( x, root ) );
}

/**
 * Make the tree logically empty.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty( )
{
  makeEmpty( root );
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <class Comparable>
bool BinarySearchTree<Comparable>::isEmpty( ) const
{
  return root == NULL;
}

/**
 * Print the tree contents in sorted order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree( ) const
{
  if( isEmpty( ) )
    cout << "Empty tree" << endl;
  else
    printTree( root );
}

/**
 * Deep copy.
 */
template <class Comparable>
const BinarySearchTree<Comparable> &
BinarySearchTree<Comparable>::
operator=( const BinarySearchTree<Comparable> & rhs )
{
  if( this != &rhs )
    {
      makeEmpty( );
      root = clone( rhs.root );
    }
  return *this;
}

/**
 * Internal method to get element field in node t.
 * Return the element field or ITEM_NOT_FOUND if t is NULL.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
elementAt( BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return ITEM_NOT_FOUND;
  else
    return t->element;
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
  if( t == NULL )
    t = new BinaryNode<Comparable>( x, NULL, NULL );
  else if( x < t->element )
    insert( x, t->left );
  else if( t->element < x )
    insert( x, t->right );
  else
    ;  // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
  if( t == NULL )
    return;   // Item not found; do nothing
  if( x < t->element )
    remove( x, t->left );
  else if( t->element < x )
    remove( x, t->right );
  else if( t->left != NULL && t->right != NULL ) // Two children
    {
      t->element = findMin( t->right )->element;
      remove( t->element, t->right );
    }
  else
    {
      BinaryNode<Comparable> *oldNode = t;
      t = ( t->left != NULL ) ? t->left : t->right;
      delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMin( BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  if( t->left == NULL )
    return t;
  return findMin( t->left );
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMax( BinaryNode<Comparable> *t ) const
{
  if( t != NULL )
    while( t->right != NULL )
      t = t->right;
  return t;
}

/**
 * Internal method to find an item in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 * Return node containing the matched item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  else if( x < t->element )
    return find( x, t->left );
  else if( t->element < x )
    return find( x, t->right );
  else
    return t;    // Match
  
}


/**
 * Internal method to make subtree empty.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty( BinaryNode<Comparable> * & t ) const
{
  if( t != NULL )
    {
      makeEmpty( t->left );
      makeEmpty( t->right );
      delete t;
    }
  t = NULL;
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree( BinaryNode<Comparable> *t ) const
{
  if( t != NULL )
    {
      printTree( t->left );
      cout << t->element << " ";
      printTree( t->right );
    }
}

/**
 * Internal method to clone subtree.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::clone( BinaryNode<Comparable> * t ) const
{
  if( t == NULL )
    return NULL;
  else
    return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}


template <class Comparable> 
int BinarySearchTree<Comparable>::size() const {
  return size(root);
}


template <class Comparable>
int BinarySearchTree<Comparable>::size(BinaryNode<Comparable> *t) const
{
  if( t == NULL )
    return 0;
  else
    return 1 + size(t->left) + size(t->right);
}

/*
 *  Union : Finds the Union of two trees
 */
template <class Comparable>
void BinarySearchTree<Comparable>::Union(const BinarySearchTree& rhs)
{
    if( isEmpty( ) )
    cout << "Empty tree" << endl;
  else
     Union(rhs.root);
}

/*
 * Union : Finds the Union of two trees
 */
template <class Comparable>
void BinarySearchTree<Comparable>::Union(BinaryNode<Comparable> *t)
{
    if( t != NULL )
    {
      Union( t->left );
      insert(t->element);
      Union( t->right );
    }
}

/*
 * Intersection: finds the intersection of two trees
 */
template <class Comparable>
void BinarySearchTree<Comparable>::Intersection(const BinarySearchTree& tree1,
						const BinarySearchTree& tree2)
{
   if ((tree1.isEmpty()) && (!(tree2.isEmpty()))){
      root = clone(tree2.root);
   }
   else if ((tree2.isEmpty()) && (!(tree1.isEmpty()))){
      root = clone(tree1.root);
   }
   else if ((tree2.isEmpty()) && (tree1.isEmpty())){
    cout << "Empty trees" << endl;
   }
  else
     Intersection(tree1.root, tree2.root);
}

/*
 * Intersection: finds the intersection of two trees
 */
template <class Comparable>
void BinarySearchTree<Comparable>::Intersection(BinaryNode<Comparable> *t1,
						BinaryNode<Comparable> *t2)
{
    if( (t1 != NULL)  && (t2 != NULL) )
    {
       Intersection( t1->left, t2 );
       
       if((find(t1->element, t2)) != NULL ){
	  insert(t1->element);
       }
       
       Intersection( t1->right, t2 );
    }
}

/*
 * IsPerfect : determines is tree is triangular
 */
template <class Comparable>
bool BinarySearchTree<Comparable>::IsPerfect()
{
   if ( isEmpty() ){ 
      cout << "Empty Tree" << endl;
      return true;
   }
   else if ( (root->right == NULL) && (root->left ==NULL))
      return true;
   else
      return (IsPerfect(root, true));
}

/*
 * IsPerfect : determines is tree is triangular
 */
template <class Comparable>
bool BinarySearchTree<Comparable>::IsPerfect(BinaryNode<Comparable> *t, 
					     bool truth)
{
   if (t != NULL)
   {
      if ((t->right != NULL) && (t->left != NULL))
      {
	 truth = IsPerfect(t->left, truth);
	 truth = IsPerfect(t->right, truth);
      }
      else if (((t->right != NULL) && (t->left == NULL)) ||
	       ((t->right == NULL) && (t->left != NULL)))
      {
	 truth = false;
      }
   }
   return truth;
}

/*
 *  IsComplete : determines if the tree is file left to right
 */
template <class Comparable>
bool BinarySearchTree<Comparable>::IsComplete()
{
 if ( isEmpty() ){ 
      cout << "Empty Tree" << endl;
      return true;
   }
   else if ( (root->right == NULL) && (root->left ==NULL))
      return true;
   else
      return (IsComplete(root, true, true, -1, -1));
}
// Calculates if the tree is perfect
// * USES RECURSION ** EXTRA CREDIT ** :)
//
template <class Comparable>
bool BinarySearchTree<Comparable>::IsComplete(BinaryNode<Comparable> *t, 
					      bool truth, bool isLeft,
					      int currDepth, int leftDepth)
{
   if ( t!= NULL)
   {
      if (t->left == NULL && t->right != NULL)
      	 return false;
      else
      {
	 currDepth++;
	 if (isLeft)
	    truth = IsComplete(t->left, truth, true, currDepth, leftDepth);
	 else if (t->left != NULL)
	    truth = IsComplete(t->left, truth, false, currDepth, leftDepth);
	 
	 if ( (t->left == NULL) && (t->right == NULL) && (isLeft))
	    leftDepth = currDepth;
	 
	 
	 if ((!(isLeft)) && (leftDepth <= currDepth) && 
	     ((t->left != NULL) || (t->right != NULL)))
	    return false;
	 	 
	 truth = IsComplete(t->right, truth, false, currDepth, leftDepth);
      }
   }  
   return truth;
}


/*
 * IPL : Calculates internal path length
 */
template <class Comparable>
int BinarySearchTree<Comparable>::IPL()
{
   if( isEmpty( ) )
      cout << "Empty tree" << endl;
   else
      return (IPL(root, 0, 0));
   return 0;
}

/*
 * IPL : Calculates internal path length
 */
template <class Comparable>
int BinarySearchTree<Comparable>::IPL(BinaryNode<Comparable> *t, 
				      int counter, int depth)
{
   if (t != NULL)
   {
      counter = IPL(t->left, counter, depth + 1);
      if ((t->right != NULL) || (t->left != NULL))
     	 counter += depth;
      counter = IPL(t->right, counter, depth + 1);
   }
   return counter;
}

/*
 * EPL : calculates external path length
 */
template <class Comparable>
int BinarySearchTree<Comparable>::EPL()
{
   if( isEmpty( ) )
      cout << "Empty tree" << endl;
   else{
      return (EPL(root, 0, -1));
   }   
   return 0;

}

/*
 * EPL : calculates external path length
 */
template <class Comparable>
int BinarySearchTree<Comparable>::EPL(BinaryNode<Comparable> *t, 
				      int counter, int depth)
{
   if (t != NULL)
   {
      int cDepth = depth + 1;
      
      counter = EPL(t->left, counter, cDepth);
     
      if ((t->right == NULL) && (t->left == NULL))
	 counter += cDepth;
     
      counter = EPL(t->right, counter, cDepth);      
   }
   return counter;
}

/*
 * Same_Shape : checks to see if to shape vectors are the same
 */

template <class Comparable>
bool BinarySearchTree<Comparable>::Same_Shape(const BinarySearchTree& rhs)
{
   vector <int> shape1;
   vector <int> shape2;

   if (isEmpty() && rhs.isEmpty())
      return true;
   else if (isEmpty() || rhs.isEmpty())
      return false;
   else
   {

      FindShape(rhs.root, shape1, -1);
      FindShape(root, shape2, -1);

      if (shape1.size() != shape2.size())
      	 return false;
      else
      {
	 for (unsigned int x = 0; x < shape1.size(); x++)
	 {
	    if (shape1.at(x) != shape2.at(x))
	       return false;
	 } 
      }
   }
   return true;
}

/*****
 * FindShape : records the depths of each node from left to right
 *             in a vector, root and NULL recorded as 0      
 *
 *****/
template <class Comparable>
void BinarySearchTree<Comparable>::FindShape(BinaryNode<Comparable> *t, 
					      vector <int>& shape, int depth)
{
    if (t != NULL)
   {
      depth++;
      shape.push_back(depth);
      FindShape(t->left, shape, depth);
      FindShape(t->right, shape, depth);
   }
    else 
      shape.push_back(0);
}
