#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListeDugum.h"

class LinkedList
{
private:
  ListeDugum *bas;
  ListeDugum *secili;

public:
  LinkedList()
  {
    bas = nullptr;
    secili = nullptr;
  }

  ~LinkedList()
  {
    while (bas != nullptr)
    {
      ListeDugum *silinecek = bas;
      bas = bas->sonraki;
      delete silinecek;
    }
  }

  void ekle(BinarySearchTree *yeniAgac);
  void ileri();
  void geri();
  void seciliAgacCiz();
  void seciliAgacSil();
};

#endif
