#include "LinkedList.h"

void LinkedList::ekle(BinarySearchTree *yeniAgac)
{
  ListeDugum *yeniDugum = new ListeDugum(yeniAgac);
  if (bas == nullptr)
  {
    bas = yeniDugum;
    secili = bas;
  }
  else
  {
    ListeDugum *temp = bas;
    while (temp->sonraki != nullptr)
    {
      temp = temp->sonraki;
    }
    temp->sonraki = yeniDugum;
  }
}

void LinkedList::ileri()
{
  if (secili != nullptr && secili->sonraki != nullptr)
  {
    secili = secili->sonraki;
  }
}

void LinkedList::geri()
{
  if (secili != nullptr && secili != bas)
  {
    ListeDugum *temp = bas;
    while (temp->sonraki != secili)
    {
      temp = temp->sonraki;
    }
    secili = temp;
  }
}

void LinkedList::seciliAgacCiz()
{
  if (secili != nullptr && secili->agac != nullptr)
  {
    secili->agac->inorder();
  }
  else
  {
    cout << "Secili agac yok." << endl;
  }
}

void LinkedList::seciliAgacSil()
{
  if (secili == nullptr)
    return;

  if (secili == bas)
  {
    bas = bas->sonraki;
    delete secili;
    secili = bas;
  }
  else
  {
    ListeDugum *temp = bas;
    while (temp->sonraki != secili)
    {
      temp = temp->sonraki;
    }
    temp->sonraki = secili->sonraki;
    delete secili;
    secili = temp->sonraki;
  }
}
