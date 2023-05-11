#include <ctime>
#include <fstream>
#include <iostream>
enum Money {
  ONEHUND = 1,
  TWOHUND = 2,
  FIVEHUND = 4,
  THOUS = 8,
  TWOTHOUS = 16,
  FIVETHOUS = 32,
  PASS = 64
};

int transform(int num) {
  int bin = 1;
  for (int i = 0; i < num; i++) {
    bin *= 2;
  }
  return bin;
}

int main() {
  std::srand(std::time(nullptr));

  int bank[1000];
  int buf;
  char symbol;
  std::cout << "Select an action(+-): ";
  std::cin >> symbol;

  if (symbol == '+') {
    std::ifstream read("bank.bin", std::ios::binary);
    if (!read.is_open()) {
      std::cerr << "Нельзя открыть файл\n";
      return 1;
    }
    for (size_t i = 0; i < 1000; i++) {
      read >> bank[i];
      if (bank[i] != 0){
        bank[i] |= PASS;
      }
    }
    
    read.close();

    for (size_t i = 0; i < 1000; i++) {
      if (bank[i] = 0) {
        bank[i] |= transform(std::rand() % 6);
      }
    }

    std::ofstream write("bank.bin", std::ios::binary);

    if (!write.is_open()) {
      std::cerr << "Нельзя открыть файл\n";
      return 1;
    }

    for (size_t i = 0; i < 1000; i++) {
      write << bank[i];
    }
  }
}