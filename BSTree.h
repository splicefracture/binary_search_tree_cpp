//*********************
// File : BSTree.h
// Author : Alec Prassinos
// user name : alecp1
// Date : Monday Nov 1 04
//
// Vote Kerry
//
// Wrapper class for a BinarySearchTree<class Comparable>
// Defined in BinarySearchTree.h
// Simply Abstracts code from the orignal tree.
//
//*********************
#ifndef BSTREE_H_
#define BSTREE_H_

#include "BSTree.h"
#include "BinarySearchTree.h"
#include "Proj3Aux.h"
#include "dsexceptions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BSTree
{

   public:

      // default constructor
      BSTree();
      // Named Tree constructor
      BSTree(int sentinel, string name);
      // Copies tree into a tree of a different name
      BSTree(const BSTree& tree, string name);
      // Copies tree with same name
      BSTree(const BSTree& rhs);
      
      // default destructor
      ~BSTree();

      // useless accessors
      string GetName() const;
      BinarySearchTree < int > GetTree();

      // inserts x into the tree
      void insert(int x);
      // removes x from the tree
      void remove(int x);

      // Copies elements of tree into m_tree
      void Union( const BSTree& tree);
      // Copies matching elements in tree1 and tree2 into m_tree
      void Intersection( const BSTree& tree1, const BSTree& tree2);

      // returns true if tree is triangular
      bool IsPerfect();
      // returns true is tree is filled from left to right
      // ** implemented with recursion **
      bool IsComplete();

      // finds sum of the depths of the internal nodes
      int IPL();
      // finds sum of the depths of the external nodes 
      int EPL();

      // Ignores elements and determines if the shapes match
      bool Same_Shape(const BSTree& tree);

      // prints tree with inorder traversal
      void PrintTree();

		
   private:
      string m_name;
      BinarySearchTree<int> m_tree;
                
};





#endif
