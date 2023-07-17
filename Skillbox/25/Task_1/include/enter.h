#pragma once
#include "struct.h"

inline coord EnterCoord(int i = 1) {

  coord XY;

  std::cout << "Enter XY_" << i << " -> x: ";
  std::cin >> XY.x;
  std::cout << "Enter XY_" << i << " -> y: ";
  std::cin >> XY.y;
  return XY;
}