#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

/* int GetRandomNumber(int min, int max) {
  // Установить генератор случайных чисел
  srand(time(NULL));

  // Получить случайное число - формула
  int num = min + rand() % (max - min + 1);

  return num;
}

void rand_file() {
  string condition = "abcdefghijklmnopqrstuvwxyz";
  ofstream outfile("test.txt");
  for (int i = 0; i < GetRandomNumber(1, 30); i++) {
    for (int j = 0; j < GetRandomNumber(1, 20); j++) {
      for (int q = 0; q < GetRandomNumber(1, 8); q++) {
        outfile << condition[GetRandomNumber(0, 26)];
      }
      outfile << " ";
    }
    outfile << "\n";
  }
} */

int main() {

 // rand_file();

 ofstream outfile("test.txt");
 outfile << "I sometimes wish me were a mermaid\n";
 outfile << "I could raise me in the tub at home\n";
 outfile << "We could take a swim together\n";
 outfile << "On weekly day trips to the bay\n";
 outfile << "Oh me and you\n";
 outfile << "It would be only me and you\n";
 outfile << "Oh me and you\n";
 outfile << "It would be only\n";
 outfile << "Me and\n";
 outfile << "You\n"; 

 
}
