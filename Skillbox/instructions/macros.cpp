#include <iostream>
#include <math.h>

#define TITLE "Skillbox"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int main() {
  std::cout << TITLE << std::endl;
  std::cout << "Enter command: ";
  int command;
  std::cin >> command;

  if (command == UP) {
    std::cout << "UP!" << std::endl;
  } else if (command == DOWN) {
    std::cout << "DOWN!" << std::endl;
  } else if (command == LEFT) {
    std::cout << "LEFT!" << std::endl;
  } else if (command == RIGHT) {
    std::cout << "RIGHT!" << std::endl;
  } else {
    std::cerr << "No such command!";
  }

#define MIN(a, b) ((a < (b)) ? (a) : (b))
#define MAX(a, b) ((a > (b)) ? (a) : (b))

  std::cout << MIN(20, 10) << std::endl;          // 10
  std::cout << MAX(30, MIN(40, 10)) << std::endl; // 30
}

#define UP (1 << 0)
#define DOWN (1 << 1)
#define LEFT (1 << 2)
#define RIGHT (1 << 3)
#define UP_RIGTH (UP | RIGHT)
void a() {
  int command;
  if (command == UP_RIGTH) { // 9
    std::cout << "UP!" << std::endl;
  }
}

#define TANK(model, name) model ## _ ## name

void armata_shot(int count) { std::cout << "Shot!" << std::endl; }

void Armata() {
  double armata_weight = 49.5;
  int armata_capacity = 3;
  double armata_max_speed = 90;

#if 0
  std::cout << TANK(armata, weight) << std::endl;
  TANK(armata, weight) = 55;
  std::cout << TANK(armata, weight) << std::endl;
#endif
  TANK(armata, shot)(5);
}