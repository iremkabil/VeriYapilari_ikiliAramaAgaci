#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  LinkedList liste;

  char secim;
  do
  {
    std::cout << "1. Agac Ekle\n";
    std::cout << "2. Secili Agaci Ciz\n";
    std::cout << "3. Secili Agaci Sil\n";
    std::cout << "4. Agaclari Gez\n";
    std::cout << "5. Toplam Degeri Goster\n";
    std::cout << "6. Cikis\n";
    std::cout << "Seciminizi yapin: ";
    std::cin >> secim;

    switch (secim)
    {
    case '1':
    {
      char veri;
      std::cout << "Agac eklemek icin karakter girin: ";
      std::cin >> veri;
      BinarySearchTree *yeniAgac = new BinarySearchTree();
      yeniAgac->ekle(veri);
      liste.ekle(yeniAgac);
      break;
    }
    case '2':
      if (liste.getSecili() != nullptr)
        liste.getSecili()->agac->inorder();
      else
        std::cout << "Secili agac yok." << std::endl;
      break;
    case '3':
      liste.seciliAgacSil();
      break;
    case '4':
      liste.ileri();
      break;
    case '5':
      if (liste.getSecili() != nullptr)
        std::cout << "Secili agacin toplam degeri: " << liste.getSecili()->agac->toplamDeger() << std::endl;
      else
        std::cout << "Secili agac yok." << std::endl;
      break;
    case '6':
      std::cout << "Cikis yapiliyor..." << std::endl;
      break;
    default:
      std::cout << "Gecersiz secim." << std::endl;
      break;
    }

  } while (secim != '6');

  return 0;
}
