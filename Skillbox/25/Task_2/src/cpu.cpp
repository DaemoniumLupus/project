#include "cpu.h"
#include "ram.h"
#include <iostream>

void Compute() {
  int sum = 0;
  for (int i = 0; i < 8; i++) {
    sum += Read(i);
  }
  std::cout << "Sum = " << sum << std::endl;
}