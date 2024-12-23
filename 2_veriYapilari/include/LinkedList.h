#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListeDugum.h"
#include <string>
#include <iostream>

class LinkedList
{
private:
  ListeDugum *head;
  ListeDugum *selectedNode;

public:
  LinkedList() : head(nullptr), selectedNode(nullptr) {}
  ~LinkedList();

  void addTree(const std::string &data);
  void drawList() const;
  void moveSelection(char direction);
  void deleteSelected();
  void rotateTree() const;
};

#endif
