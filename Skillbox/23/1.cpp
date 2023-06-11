#include <iostream>

#define STR(text) #text
#define DAY0 STR(no day)
#define DAY1 STR(Monday)
#define DAY2 STR(Tuesday)
#define DAY3 STR(Wednesday)
#define DAY4 STR(Thursday)
#define DAY5 STR(Friday)
#define DAY6 STR(Saturday)
#define DAY7 STR(Sunday)
#define PRINT(num) std::cout << DAY##num << std::endl

int main() {
  int day;
  std::cout << "enter number of week: ";
  std::cin >> day;
  switch (day) {
  case 1:
    PRINT(1);
    break;
  case 2:
    PRINT(2);
    break;
  case 3:
    PRINT(3);
    break;
  case 4:
    PRINT(4);
    break;
  case 5:
    PRINT(5);
    break;
  case 6:
    PRINT(6);
    break;
  case 7:
    PRINT(7);
    break;
  default:
    PRINT(0);
    break;
  }
}