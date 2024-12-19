#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Dugum.h"
#include <iostream>
using namespace std;

class BinarySearchTree
{
private:
  Dugum *kok;

  void ekle(Dugum *&dugum, char veri);
  void inorder(Dugum *dugum);
  int toplamDeger(Dugum *dugum);
  void temizle(Dugum *&dugum);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  void ekle(char veri);
  void inorder();
  int toplamDeger();
  void temizle();
};

#endif