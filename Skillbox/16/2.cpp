#include <iostream>

int main() {
  std::string str_1, str_2;
  std::string str;
  double num;
  std::cout << "Input first part: ";
  std::cin >>  str_1;
  std::cout << "Input second part: ";
  std::cin >> str_2;

  str = str_1;
  str += '.';
  str += str_2;

  num = std::stod(str);

  std::cout << num;
}