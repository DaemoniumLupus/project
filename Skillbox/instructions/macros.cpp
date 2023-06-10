#include <iostream>

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

#define UP (1 << 0)
#define DOWN (1 << 1)
#define LEFT (1 << 2)
#define RIGHT (1 << 3)
  void a() {
    if (command == UP) {
      std::cout << "UP!" << std::endl;
    }
  }
}