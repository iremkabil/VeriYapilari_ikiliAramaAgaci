#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "ListeDugum.h"
#include "LinkedList.h"

using namespace std;

int main()
{
  LinkedList list;
  ifstream file("benioku.txt");
  if (!file.is_open())
  {
    cerr << "Dosya acilamadi!" << endl;
    return 1;
  }

  string line;
  while (getline(file, line))
  {
    if (!line.empty())
    {
      list.addTree(line); // Her bir satırı bir ağaca dönüştür ve listeye ekle
    }
  }
  file.close();
  char command;
  do
  {
    // Listeyi çizdir
    list.drawList();
    cout << "Komut giriniz (a: sola git, d: saga git, s: secili dugumu sil, w: agaci dondur, q: cikis): ";
    cin >> command;
    switch (command)
    {
    case 'a':
      list.moveSelection('a');
      break;
    case 'd':
      list.moveSelection('d');
      break;
    case 's':
      list.deleteSelected();
      break;
    case 'w':
      list.rotateTree();
      break;
    }
  } while (command != 'q');

  return 0;
}
