#include "LinkedList.h"
#include <iomanip>

using namespace std;
int boslukMiktari = 2;
int index = 0;
LinkedList::~LinkedList()
{
  while (head)
  {
    ListeDugum *temp = head;
    head = head->next;
    delete temp;
  }
}

void LinkedList::addTree(const std::string &data)
{
  BinarySearchTree *tree = new BinarySearchTree(data[0]); // İlk karakterin ASCII değeriyle ağaç oluştur
  ListeDugum *newNode = new ListeDugum(tree);

  if (!head)
  {
    head = newNode;
    selectedNode = head;
  }
  else
  {
    ListeDugum *temp = head;
    while (temp->next)
      temp = temp->next;
    temp->next = newNode;
  }
}
//-----------------------------------------------
// Satır çizme fonksiyonu
void satirCiz()
{
  for (int i = 0; i < 10; i++)
    cout << "------------  ";
  cout << endl;
}
void isaretYaz(int indeks)
{
  if (indeks != 0)
  {
    for (int i = 0; i < indeks; i++)
    {
      for (int i = 0; i < boslukMiktari; i++)
        cout << " ";
      cout << "            ";
    }
  }
  cout << "^^^^^^^^^^^^";
  for (int i = 0; i < boslukMiktari; i++)
    cout << " ";
}

// Düğümdeki adresleri yazma fonksiyonu
void adresYaz(ListeDugum *dugum)
{
  if (dugum != nullptr)
  {
    cout << "." << std::setw(10) << dugum << ".  ";
  }
  else
  {
    for (int i = 0; i < boslukMiktari; i++)
      cout << " ";
    cout << "NULL ";
  }
}
// Düğümdeki değeri (ASCII) yazma fonksiyonu
void degerYaz(ListeDugum *dugum)
{
  if (dugum != nullptr && dugum->tree != nullptr)
  {
    cout << "." << std::setw(10) << int(dugum->tree->value) << ".  "; // ASCII değeri
  }
}
// Bağlı listeyi yazdırma fonksiyonu
void LinkedList::drawList() const
{
  ListeDugum *temp = head;
  satirCiz();

  while (temp != nullptr)
  {
    adresYaz(temp);
    temp = temp->next;
  }
  cout << endl;
  satirCiz();

  temp = head;
  while (temp != nullptr)
  {
    degerYaz(temp); // Düğümdeki ağacın ASCII değerini yaz
    temp = temp->next;
  }
  std::cout << std::endl;

  satirCiz();

  // Sonraki düğümlerin adreslerini yaz
  temp = head;
  while (temp != nullptr)
  {
    adresYaz(temp->next);
    temp = temp->next;
  }
  cout << endl;

  satirCiz();
  isaretYaz(index);
  cout << endl;
}

//-----------------------------------------------
void LinkedList::moveSelection(char direction)
{
  if (selectedNode)
  {
    if (direction == 'd' && selectedNode->next)
    {
      selectedNode = selectedNode->next;
      index++;
    }
    else if (direction == 'a')
    {
      ListeDugum *temp = head;
      while (temp && temp->next != selectedNode)
      {
        temp = temp->next;
      }
      if (temp)
      {
        selectedNode = temp;
      }
      index--;
    }
  }
}

void LinkedList::deleteSelected()
{
  if (!selectedNode)
    return;

  if (selectedNode == head)
  {
    head = head->next;
    delete selectedNode;
    selectedNode = head;
  }
  else
  {
    ListeDugum *temp = head;
    while (temp->next != selectedNode)
    {
      temp = temp->next;
    }
    if (temp)
    {
      temp->next = selectedNode->next;
      delete selectedNode;
      selectedNode = temp->next;
    }
  }
}

void LinkedList::rotateTree() const
{
  if (selectedNode && selectedNode->tree)
  {
    selectedNode->tree->draw(0);
  }
}
