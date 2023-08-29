#pragma once
#include <iostream>
#include <string>


class Contact {
  std::string name;
  std::string number;

public:
  static bool validNumber(std::string numStr) {
    if (numStr[0] != '+' || numStr[1] != '7'){
      return false;
    }
    for (int i = 2; i < numStr.size(); ++i)
      if (numStr[i] > '9' || numStr[i] < '0')
        return false;
    return true;
  }

  static std::string inputString() {
    std::string input;
    std::cin >> input;
    return input;
  }

  void inputNumber() {
    while (true) {
      std::cout << "Number:";
      std::string input = inputString();
      if (validNumber(input)) {
        number = input;
        break;
      } else
        std::cout << "Try again" << std::endl;
    }
  }

  void setName(std::string new_name) { name = new_name; }
  void setNumber(std::string new_number) {
    if (validNumber(new_number))
      number = new_number;
    number = "0";
  }
  std::string inputName() {
    std::cout << "Name:";
    std::string input;
    std::cin >> input;
    name = input;
    return input;
  }

  std::string getName() { return name; }
  std::string getNumber() { return number; }
};