#include "gpu.h"
#include "ram.h"
#include <iostream>

void Display() {
  for (int j = 0; j < 8; j++) {
    std::cout << Read(j) << ' ';
  }
  std::cout << std::endl;
}