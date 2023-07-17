#include "enter.h"
#include "operation.h"

int main() {
  std::string command;
  coord scalpelXY_1, scalpelXY_2;
  coord sutureXY_1, sutureXY_2;
  while (true) {
    std::cout << "Enter command: ";
    std::cin >> command;
    if (command == "scalpel") {
      scalpelXY_1 = EnterCoord();
      scalpelXY_2 = EnterCoord(2);
      Scalpel(scalpelXY_1, scalpelXY_2);
    } else if (command == "hemostat") {
      Hemostat(EnterCoord());
    } else if (command == "tweezers") {
      Tweezers(EnterCoord());
    } else if (command == "suture") {
      sutureXY_1 = EnterCoord();
      sutureXY_2 = EnterCoord(2);
      if (sutureXY_1.x == scalpelXY_1.x && sutureXY_2.x == scalpelXY_2.x &&
          sutureXY_1.y == scalpelXY_1.y && sutureXY_2.y == scalpelXY_2.y) {
        Suture(sutureXY_1, sutureXY_2);
        std::cout << "Operation completed" << std::endl;
        break;
      } else {
        std::cout << "Uncut area sewn up!" << std::endl;
      }
    }
  }
}