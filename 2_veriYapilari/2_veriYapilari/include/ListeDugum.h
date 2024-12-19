#ifndef LISTEDUGUM_H
#define LISTEDUGUM_H

#include "BinarySearchTree.h"

class ListeDugum
{
public:
  BinarySearchTree *agac;
  ListeDugum *sonraki;

  ListeDugum(BinarySearchTree *agac)
  {
    this->agac = agac;
    this->sonraki = nullptr;
  }

  ~ListeDugum()
  {
    delete agac;
  }
};

#endif