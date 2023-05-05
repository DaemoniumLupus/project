#include <iostream>
#include <fstream> // работа с файлами
int main() {
  std::ifstream bank;
  bank.open("D:\\Directory\\project\\Skillbox\\test\\bank.txt");//открытие файла
  int money;
  bank >> money;
  bank >> money;
  std::cout << money << std::endl;
  bank.close();//закрытие файла


}