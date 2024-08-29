#include <iostream>
#include "ABP.hpp"

int main() {
  ABP<int> *abp = new ABP<int>();
  abp->add(8);
  abp->add(2);
  abp->add(10);
  abp->add(6);
  abp->add(5);
  abp->add(15);
  abp->add(7);
  abp->add(3);
  abp->add(20);
  abp->add(11);
  cout << abp->strGraphViz();
  delete abp;
  return 0;
}
