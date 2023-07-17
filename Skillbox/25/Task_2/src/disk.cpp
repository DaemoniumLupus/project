#include "ram.h"
#include "disk.h"
#include <iostream>
#include <fstream>

void Save() {
  std::ofstream save_file("data.txt");
  for (int i = 0; i < 8; i++) {
    save_file << Read(i) << std::endl;
  }
  save_file.close();
}

void Load() {
  std::ifstream load_file("data.txt");
  if (load_file.is_open()) {
    for (int i = 0; i < 8; i++) {
      int num;
      load_file >> num;
      Write(i, num);
    }
    load_file.close();
  } else
    std::cout << "Save file does not exist!!!" << std::endl;
}