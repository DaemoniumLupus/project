#include "operation.h"
#include "struct.h"

void Scalpel(coord XY_1, coord XY_2) {
  std::cout << "Creat incision (" << XY_1.x << ", " << XY_1.y << ") and ("
            << XY_2.x << ", " << XY_2.y << ")" << std::endl;
}

void Hemostat(coord XY) {
  std::cout << "Clamp on point (" << XY.x << ", " << XY.y << ")" << std::endl;
}

void Tweezers(coord XY) {
  std::cout << "Tweezers on point (" << XY.x << ", " << XY.y << ")"
            << std::endl;
}

void Suture(coord XY_1, coord XY_2) {
  std::cout << "Sewn up (" << XY_1.x << ", " << XY_1.y << ") and (" << XY_2.x
            << ", " << XY_2.y << ")" << std::endl;
}