#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

const int SIZE = 6;
const int ATM_SIZE = 1000;
const std::string FILE_NAME = "ATM.bin";
const int banknotNominal[SIZE] = {100, 200, 500, 1000, 2000, 5000};
int atm[SIZE];

void printBanknots(int atm[SIZE]);
void fillATM();
void withdrawMoney();
void createFile();

int main() {
  createFile();

  std::ifstream file(FILE_NAME, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error open file\n";
    return 1;
  }
  file.read((char *)atm, SIZE * sizeof(atm[0]));
  file.close();

  while (true) {
    std::cout << "Operation (+, -, p, e): ";
    std::string operation;
    std::cin >> operation;
    if (operation == "+") {
      fillATM();
      printBanknots(atm);
    } else if (operation == "-")
      withdrawMoney();
    else if (operation == "p")
      printBanknots(atm);
    else if (operation == "e")
      break;
    else
      std::cerr << "Invalid operation\n";
  }
}

void printBanknots(int atm[SIZE]) {
  int total = 0;
  int countBanknots = 0;
  for (int i = 0; i < SIZE; i++) {
    std::cout << std::setw(5) << banknotNominal[i] << ": " << std::setw(5)
              << atm[i] << " (" << atm[i] * banknotNominal[i] << ")\n";
    total += atm[i] * banknotNominal[i];
    countBanknots += atm[i];
  }
  std::cout << std::setw(5) << "Total: " << std::setw(5) << countBanknots
            << " (" << total << ")\n\n";
}

void fillATM() {
  // Подсчитываем кол-во купюр в банкомате
  int countBanknots = 0;
  for (int i = 0; i < SIZE; i++)
    countBanknots += atm[i];
  // Дополняем до 1000 купюр
  std::srand(std::time(nullptr));

  while (countBanknots < ATM_SIZE) {
    int value =
        1 +
        rand() %
            (ATM_SIZE -
             countBanknots); // от 0 до оставшегося кол-ва не хватающих банкнот
    countBanknots += value;
    atm[rand() % SIZE] += value;
  }
  std::ofstream out(FILE_NAME, std::ios::binary);
  if (!out.is_open()) {
    std::cerr << "Error open file\n";
    return;
  }
  out.write((char *)atm, SIZE * sizeof(atm[0]));
}

void withdrawMoney() {
  int amount;
  std::cout << "Amount: ";
  std::cin >> amount;

  if (std::cin.fail() || std::cin.peek() != '\n' || (amount % 100) != 0 ||
      amount <= 0) {
    std::cerr << "Invalid amount.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
  }
  int total = 0;
  for (int i = 0; i < SIZE; i++)
    total += atm[i] * banknotNominal[i];

  if (amount > total) {
    std::cerr << "There is not enough money in the ATM\n";
    return;
  }

  // Банкноты клиента, которые будут сняты
  int bills_client[SIZE];
  std::memset(bills_client, 0,
              SIZE * sizeof(bills_client[0])); // обнуляем массив

  // Начинаем снимать с крупных купюр, как заведено у банкоматов
  for (int i = SIZE - 1; i >= 0; --i) {
    while (atm[i] > 0) {
      if (amount < banknotNominal[i])
        break;
      atm[i] -= 1;
      bills_client[i] += 1;
      amount -= banknotNominal[i];
      ;
    }
  }

  std::cout << "Client taken: \n";
  printBanknots(bills_client);

  std::ofstream out(FILE_NAME, std::ios::binary);
  if (!out.is_open()) {
    std::cerr << "Error open file\n";
    return;
  }
  out.write((char *)atm, SIZE * sizeof(atm[0]));
}

void createFile() {
  std::ifstream file(FILE_NAME, std::ios::binary);
  if (!file.is_open()) {
    std::ofstream file(FILE_NAME, std::ios::binary);
    if (!file.is_open()) {
      std::cerr << "Error create file\n";
      exit(1);
    }
    file.close();
  }
  file.close();
}