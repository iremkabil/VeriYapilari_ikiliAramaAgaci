#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

class BinarySearchTree
{
public:
  char value;
  BinarySearchTree *left;
  BinarySearchTree *right;

  BinarySearchTree(char val) : value(val), left(nullptr), right(nullptr) {}

  // Ağacın çizilmesi için bir fonksiyon
  void draw(int depth) const;
};

#endif
