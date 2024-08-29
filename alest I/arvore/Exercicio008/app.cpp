#include <iostream>
#include <iomanip>
#include "NodeCharTree.hpp"

int main() {
  NodeCharTree *b = new NodeCharTree('B');
  b->addSubtree( new NodeCharTree('E') );
  b->addSubtree( new NodeCharTree('F') );
  NodeCharTree *c = new NodeCharTree('C');
  c->addSubtree( new NodeCharTree('G') );
  c->addSubtree( new NodeCharTree('H') );
  c->addSubtree( new NodeCharTree('I') );
  NodeCharTree *root = new NodeCharTree('A');
  root->addSubtree(b);
  root->addSubtree(c);
  root->addSubtree( new NodeCharTree('D') );
  cout << "pre-order:" << endl << root->preorder() << endl;
  cout << "post-order:" << endl << root->postorder() << endl;
  cout << "level-order:" << endl << root->levelorder() << endl;
  delete root;
  return 0;
}
