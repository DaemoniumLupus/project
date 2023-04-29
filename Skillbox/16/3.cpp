#include <iostream>
#include <sstream>

int main() {
  std::string buffer;
  double a, b;
  char operation;
  do {

    std::cout << "Input expression: ";
    std::cin >> buffer;
    if (buffer != "-1") {
      std::stringstream buffer_stream(buffer);

      buffer_stream >> a >> operation >> b;

      switch (operation) {
      case '+':
        std::cout << a + b << std::endl;
        break;
      case '-':
        std::cout << a - b << std::endl;
        break;
      case '*':
        std::cout << a * b << std::endl;
        break;
      case '/':
        std::cout << a / b << std::endl;
        break;

      default:
        break;
      }
    }
  } while (buffer != "-1");
}