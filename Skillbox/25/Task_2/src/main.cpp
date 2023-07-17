#include "head.h"
#include <iostream>

int main() {
  std::string command;

  std::cout << "Enter command: ";
  std::cin >> command;
  
  while (command != "exit") {

    if (command == "input") {
      Input();
    } else if (command == "display") {
      Display();
    } else if (command == "save") {
      Save();
    } else if (command == "load") {
      Load();
    } else if (command == "sum") {
      Compute();
    } else {
      std::cout << "Enter command again!" << std::endl;
    }

    std::cout << "Enter command: ";
    std::cin >> command;
  }
}
