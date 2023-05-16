#include <ctime>
#include <fstream>
#include <iostream>

char bank[1000];
int storage[6];
int total;
int partition[6];
int sum;
enum Money {
  ONEHUND = 1,
  TWOHUND = 2,
  FIVEHUND = 4,
  THOUS = 8,
  TWOTHOUS = 16,
  FIVETHOUS = 32,
  PASS = 64
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
    if (bank[i] & ONEHUND) {
      storage[5]++;
      total += 100;
    } else if (bank[i] & TWOHUND) {
      storage[4]++;
      total += 200;
    } else if (bank[i] & FIVEHUND) {
      storage[3]++;
      total += 500;
    } else if (bank[i] & THOUS) {
      storage[2]++;
      total += 1000;
    } else if (bank[i] & TWOTHOUS) {
      storage[1]++;
      total += 2000;
    } else if (bank[i] & FIVETHOUS) {
      storage[0]++;
      total += 5000;
    }
  }
}
bool Rebuilding() {
  for (int i = 0; i < 6; i++) {
    if (storage[i] < partition[i]) {
      if (i == 0 || i == 3) {
        partition[i + 1] += 2 * (partition[i] - storage[i]);
        partition[i + 2] += (partition[i] - storage[i]);
        partition[i] -= partition[i] - storage[i];
      } else if (i == 1 || i == 2 || i == 4) {

        partition[i + 1] += 2 *( partition[i] - storage[i]);
        partition[i] -= partition[i] - storage[i];
      }
      if (i == 5 && !(partition[5] <= storage[5])) {
        return false;
      }
    }
  }
  return true;
}
bool Refil() {

  std::srand(std::time(nullptr));
  std::ofstream write("bank.bin", std::ios::binary);
  if (!write.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return false;
  }

  for (size_t i = 0; i < 1000; i++) {
    if (bank[i] == 0) {
      bank[i] |= Transform(std::rand() % 6);
    }
    bank[i] &= ~PASS;
    write << bank[i];
  }
  return true;
}
void Withdrawal_of_banknotes() {

  for (int i = 0; i < 1000; i++) {
    if (bank[i] & ONEHUND && partition[5] > 0) {
      partition[5]--;
      bank[i] &= ~ONEHUND;
      bank[i] &= ~PASS;
      sum -= 100;
    } else if (bank[i] & TWOHUND && partition[4] > 0) {
      partition[4]--;
      bank[i] &= ~TWOHUND;
      bank[i] &= ~PASS;
      sum -= 200;
    } else if (bank[i] & FIVEHUND && partition[3] > 0) {
      partition[3]--;
      bank[i] &= ~FIVEHUND;
      bank[i] &= ~PASS;
      sum -= 500;
    } else if (bank[i] & THOUS && partition[2] > 0) {
      partition[2]--;
      bank[i] &= ~THOUS;
      bank[i] &= ~PASS;
      sum -= 1000;
    } else if (bank[i] & TWOTHOUS && partition[1] > 0) {
      partition[1]--;
      bank[i] &= ~TWOTHOUS;
      bank[i] &= ~PASS;
      sum -= 2000;
    } else if (bank[i] & FIVETHOUS && partition[0] > 0) {
      partition[0]--;
      bank[i] &= ~FIVETHOUS;
      bank[i] &= ~PASS;
      sum -= 5000;
    }
    if (sum == 0) {
      break;
    }
  }
}

bool Withdrawal() {

  int buf_sum;
  std::cout << "Enter sum(x100): ";
  std::cin >> sum;
  buf_sum = sum;
  /* std::cout << total << std::endl;
  for (int i = 0; i < 6; i++) {
    std::cout << storage[i] << std::endl;
  } */
  if (sum % 100 != 0) {
    std::cerr << "Incorrect summ" << std::endl;
  }
  if (!(sum <= total)) {
    std::cerr << "No money!" << std::endl;
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
  if (!Rebuilding()) {
    std::cerr << "No money! 173" << std::endl;
  };
  sum = buf_sum;
  Withdrawal_of_banknotes();
  sum = buf_sum;
  return true;
}
bool Read_file() {
  std::ifstream read("bank.bin", std::ios::binary);

  if (!read.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return false;
  }
  if (read.peek() != EOF) {
    for (size_t i = 0; i < 1000; i++) {
      read >> bank[i];
      if (bank[i] & ONEHUND || bank[i] & TWOHUND || bank[i] & FIVEHUND ||
          bank[i] & THOUS || bank[i] & TWOTHOUS || bank[i] & FIVETHOUS) {
        bank[i] |= PASS;
      }
    }
    Storage();
    read.close();
  }
  return true;
}
bool Write() {
  std::ofstream write("bank.bin", std::ios::binary);

  if (!write.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return false;
  }

  for (size_t i = 0; i < 1000; i++) {

    bank[i] &= ~PASS;
    write << bank[i];
  }
  return true;
}

int main() {

  char symbol;
  bool err;
  /*  std::ofstream clear("bank.bin");
clear.clear();  */
  if (!Read_file()) {
    std::cerr << "File not read" << std::endl;
    return 1;
  }
  std::cout << "Total: " << total << std::endl;
  
  std::cout << "Select an action(+-): ";
  std::cin >> symbol;
  if (symbol == '+') {
    err = Refil();
  } else if (symbol == '-') {
    err = Withdrawal();
    if (err) {
      std::cout << "Withdrawn money: " << sum << std::endl;
    }
    if (!Write()) {
      std::cerr << "Failed to write to file" << std::endl;
    }
  } else {
    std::cerr << "Incorect symbol!" << std::endl;
  }
  if (!err) {
    return 1;
  }
}