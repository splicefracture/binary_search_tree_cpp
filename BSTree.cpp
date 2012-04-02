//*********************
// File : BSTree.cpp
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

#include "BinarySearchTree.h"
#include "Proj3Aux.h"
#include "dsexceptions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// default constructor
BSTree::BSTree()
   :m_name(" "), m_tree(BinarySearchTree<int> (-1)){}

// Named Tree constructor
BSTree::BSTree(int sentinel, string name)
   : m_name(name), m_tree(BinarySearchTree<int> (sentinel))
{
   //no code
}

// Copies tree into a tree of a different name
BSTree::BSTree(const BSTree& tree, string name)
   : m_name(name), m_tree(tree.m_tree)
{
   //no code
}

// Copies tree with same name
BSTree::BSTree(const BSTree& rhs)
   : m_name(rhs.m_name), m_tree(rhs.m_tree)
{
   // no code
}


// default destructor
BSTree::~BSTree()
{

}

// useless accessors
string BSTree::GetName() const
{
   return m_name;
}

// useless accessors
BinarySearchTree<int> BSTree::GetTree()
{
   return m_tree;
}

// inserts x into the tree
void BSTree::insert(int x)
{
   m_tree.insert(x);
}

 // removes x from the tree
void BSTree::remove(int x)
{
   m_tree.remove(x);
}

// Copies elements of tree into m_tree
void BSTree::Union( const BSTree& tree)
{
   m_tree.Union(tree.m_tree);
}

// Copies matching elements in tree1 and tree2 into m_tree
void BSTree::Intersection( const BSTree& tree1, const BSTree& tree2)
{
   m_tree.Intersection(tree1.m_tree, tree2.m_tree);
}

// prints tree with inorder traversal
void BSTree::PrintTree()
{
   m_tree.printTree();
   cout << endl;
}

// returns true is tree is filled from left to right
// ** implemented with recursion **
bool BSTree::IsComplete()
{
   return m_tree.IsComplete(); 
}

// returns true if tree is triangular
bool BSTree::IsPerfect()
{
   return m_tree.IsPerfect();
}

  // finds sum of the depths of the internal nodes
int BSTree::IPL()
{
   return m_tree.IPL();
}

// finds sum of the depths of the external nodes 
int BSTree::EPL()
{
   return m_tree.EPL();
}

// Ignores elements and determines if the shapes match
bool BSTree::Same_Shape(const BSTree& tree)
{
   return m_tree.Same_Shape(tree.m_tree);
}
