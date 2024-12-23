#include "BinarySearchTree.h"

void BinarySearchTree::draw(int depth) const
{
  if (this)
  {
    if (right)
      right->draw(depth + 1);
    for (int i = 0; i < depth; ++i)
      std::cout << "   ";
    std::cout << "." << value << ".\n";
    if (left)
      left->draw(depth + 1);
  }
}
