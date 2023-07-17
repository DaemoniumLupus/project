#include "kdb.h"
#include "ram.h"
#include <iostream>

void Input() {
  for (int i = 0; i < 8; i++) {
    int num;
    std::cout << "Input Num #" << i << ":";
    std::cin >> num;
    Write(i, num);
  }
}