#include <ctime>
#include <fstream>
#include <iostream>

char bank[1000];
int storage[6];
int total;

enum Money {
  ONEHUND = 1,
  TWOHUND = 2,
  FIVEHUND = 4,
  THOUS = 8,
  TWOTHOUS = 16,
  FIVETHOUS = 32,
  PASS = 64,
  FREE = 128
};

int Transform(int num) {
  int bin = 1;
  for (int i = 0; i < num; i++) {
    bin *= 2;
  }
  return bin;
}
void Storage() {
  for (int i = 0; i < 6; i++) {
    storage[i] = 0;
  }
  total = 0;
  for (int i = 0; i < 1000; i++) {
    total += bank[i];
    switch (bank[i]) {
    case ONEHUND:
      storage[5]++;
      break;
    case TWOHUND:
      storage[4]++;
      break;
    case FIVEHUND:
      storage[3]++;
      break;
    case THOUS:
      storage[2]++;
      break;
    case TWOTHOUS:
      storage[1]++;
      break;
    case FIVETHOUS:
      storage[0]++;
      break;

    default:
      break;
    }
  }
}

bool Refil() {

  std::srand(std::time(nullptr));
  

  for (size_t i = 0; i < 1000; i++) {
    if (bank[i] == FREE || bank[i] == 0) {
      bank[i] |= Transform(std::rand() % 6);
      bank[i] &= ~FREE;
    }
  }

  std::ofstream write("bank.bin", std::ios::binary);

  if (!write.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return 0;
  }

  for (size_t i = 0; i < 1000; i++) {
    write << bank[i];
  }
  return true;
}

bool Withdrawal() {
  int sum;
  int count = 0;
  std::cout << "Enter sum(x100): ";
  std::cin >> sum;
  int partition[6];

  if (sum > total){
    std::cerr << "No money!";
    return 0;
  }
  if (sum >= 5000) {
    partition[0] = sum / 5000;
    sum -= partition[0] * 5000;
  }
  if (sum >= 2000) {
    partition[1] = sum / 2000;
    sum -= partition[1] * 2000;
  }
  if (sum >= 1000) {
    partition[2] = sum / 1000;
    sum -= partition[2] * 1000;
  }
  if (sum >= 500) {
    partition[3] = sum / 500;
    sum -= partition[3] * 500;
  }
  if (sum >= 200) {
    partition[4] = sum / 200;
    sum -= partition[4] * 200;
  }
  if (sum >= 100) {
    partition[5] = sum / 100;
    sum -= partition[5] * 100;
  }

  if (sum == 0) {
    return 1;
  } else {
    std::cerr << "Incorrect summ" << std::endl;
    return 0;
  }

  
  

  for (int i = 0; i < 1000; i++) {
    switch (bank[i]) {
    case ONEHUND:
      if (partition[5] > 0) {
      }
      break;
    case TWOHUND:

      break;
    case FIVEHUND:

      break;
    case THOUS:

      break;
    case TWOTHOUS:

      break;
    case FIVETHOUS:

      break;

    default:
      break;
    }
  }
}

int main() {

  char symbol;
  bool err;
  std::ifstream read("bank.bin", std::ios::binary);
  if (!read.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return 0;
  }
  if (read.peek() != EOF) {
    for (size_t i = 0; i < 1000; i++) {
      read >> bank[i];
      if (bank[i] != FREE || bank[i] != 0) {
        bank[i] |= PASS;
      } else {
        bank[i] |= FREE;
      }
    }
  }

  read.close();

  std::cout << "Select an action(+-): ";
  std::cin >> symbol;
  if (symbol == '+') {
    err = Refil();
  } else if (symbol == '-') {
    err = Withdrawal();
  } else {
    std::cerr << "Incorect symbol!" << std::endl;
  }
  if (!err) {
    return 1;
  }
}