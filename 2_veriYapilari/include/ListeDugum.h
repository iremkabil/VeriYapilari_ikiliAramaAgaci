#ifndef LISTEDUGUM_H
#define LISTEDUGUM_H

#include "BinarySearchTree.h"

class ListeDugum
{
public:
  BinarySearchTree *tree;
  ListeDugum *next;

  ListeDugum *head = nullptr;
  ListeDugum *selectedNode = nullptr;

  ListeDugum(BinarySearchTree *tree) : tree(tree), next(nullptr) {}
  ~ListeDugum() { delete tree; }
};

#endif
