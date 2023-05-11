#include <cstdlib>
#include <cstring>
#include <fstream> // работа с файлами
#include <iostream>
#include <string>
#include <vector>

void bynary_write() {
  int number;
  std::cin >> number;
  std::ofstream file("text.bin", std::ios::binary);
  file.write((char *)&number, sizeof(number));
  file.close();

  std::ifstream file2("text.bin", std::ios::binary);
  file2.read((char *)&number, sizeof(number));
  std::cout << number;
  file2.close();
}

void bynary_write_words() {
  char *title = "Skillbox";
  std::ofstream file("title.bin", std::ios::binary);
  file.write(title, std::strlen(title));
  file << 23;
  file.close();
}

void massive() {
  int control_sum = 0;
  std::vector<int> bildings;
  int count = rand() % 901 + 100;
  for (size_t i = 0; i < count; i++) {
    bildings.push_back(std::rand() % 51);
    control_sum += bildings[i];
  }
  std::cout << control_sum << std::endl;
  std::ofstream file("bildings.txt");
  file << count << std::endl;
  for (size_t i = 0; i < count; i++) {
    file << bildings[i] << std::endl;
  }
  file << "Skillsity" << std::endl;

  file.close();

  std::vector<int> in_bildings;
  int in_count;
  
  std::ifstream in_file("bildings.txt");
  in_file >> in_count;
  for (size_t i = 0; i < in_count; i++) {
    int in_people;
    in_file >> in_people;
    in_bildings.push_back(in_people);
  }
  std::string in_city;
  in_file >> in_city;
  in_file.close();

  int sum = 0;
  for (size_t i = 0; i < in_count; i++) {
    sum += in_bildings[i];
  }
  if (sum == control_sum) {
    std::cout << in_city<< " population: " << sum  << std::endl;

  } else {
    std::cout << "Invalid control sum: " << sum << std::endl;
  }
}

void write_in_file() {
  std::ofstream file;
  file.open("phrase.txt", std::ios::app); // запись в конец файла
  file.setf(std::ios::showpos); // добавляет знак + к положительным числам
  file.setf(std::ios::boolalpha); // записывает булевы значиния как true или
                                  // false а не 1 и 0
  file.setf(std::ios::showpoint); // показывает точку на целых числах
  file.setf(std::ios::fixed); // если включен то file.precision(3) будет
                              // отвечать только за цифры после точки
  file.precision(
      3); // определяет количество цифр из числа которые будут записаны

  file << "It's never too late to learn";
  file.close();

  file.width(5); // выделяет пространство для записи
}

void read_file() {
  std::ifstream bank;
  // bank.open("D:\\Directory\\project\\Skillbox\\test\\bank.txt");//открытие
  // файла
  bank.open("bank.txt"); // in the directory with exe file
  int money;
  std::string currency;
  bank >> money >> currency;
  std::cout << money << " " << currency << std::endl;
  bank.close();

  bank.open("bank.txt", std::ios::binary); // bynary
  char buffer[20];
  bank.read(buffer, sizeof(buffer)); // поток на чтение
  buffer[19] = 0;
  std::cout << buffer << std::endl;

  bank.seekg(0); // перемещение на индекс (0 начало файла)
  bank.tellg();   // текущая позиция курсора
  bank.eof();     // true если файл закончился
  bank.is_open(); // true если файл открылся без ошибок
  bank.close();   // закрытие файла
}
int main() { massive(); }