#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
  kok = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
  temizle(kok);
}

void BinarySearchTree::ekle(Dugum *&dugum, char veri)
{
  if (dugum == nullptr)
  {
    dugum = new Dugum(veri);
  }
  else if (veri < dugum->veri)
  {
    ekle(dugum->sol, veri);
  }
  else
  {
    ekle(dugum->sag, veri);
  }
}

void BinarySearchTree::ekle(char veri)
{
  ekle(kok, veri);
}

void BinarySearchTree::inorder(Dugum *dugum)
{
  if (dugum != nullptr)
  {
    inorder(dugum->sol);
    cout << dugum->veri << " ";
    inorder(dugum->sag);
  }
}

void BinarySearchTree::inorder()
{
  inorder(kok);
  cout << endl;
}

int BinarySearchTree::toplamDeger(Dugum *dugum)
{
  if (dugum == nullptr)
  {
    return 0;
  }
  int solDeger = toplamDeger(dugum->sol);
  int sagDeger = toplamDeger(dugum->sag);
  return (2 * solDeger) + static_cast<int>(dugum->veri) + sagDeger;
}

int BinarySearchTree::toplamDeger()
{
  return toplamDeger(kok);
}

void BinarySearchTree::temizle(Dugum *&dugum)
{
  if (dugum != nullptr)
  {
    temizle(dugum->sol);
    temizle(dugum->sag);
    delete dugum;
    dugum = nullptr;
  }
}

void BinarySearchTree::temizle()
{
  temizle(kok);
}
