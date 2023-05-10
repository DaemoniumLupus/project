#include <iostream>
#include <string>
#include <fstream> // работа с файлами



int main() {
  std::ifstream bank;
  //bank.open("D:\\Directory\\project\\Skillbox\\test\\bank.txt");//открытие файла
  bank.open("bank.txt");//in the directory with exe file
  int money;
  std::string currency;
  bank >> money >> currency;
  std::cout << money  << " " << currency << std::endl;
  bank.close();


  bank.open("bank.txt", std::ios::binary);//bynary 
  char buffer[20];
  bank.read(buffer, sizeof(buffer));
  buffer[19] = 0;
  std::cout << buffer << std::endl;

  bank.seekg(0);//перемещение на индекс (0 начало файла)
  bank.tellg();//текущая позиция курсора
  bank.eof();//true если файл закончился
  bank.is_open();//true если файл открылся без ошибок
  bank.close(); // закрытие файла
}