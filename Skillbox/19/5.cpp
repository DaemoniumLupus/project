#include <cstring>
#include <fstream>
#include <iostream>

void question(int sector) {
  std::ifstream file;
  std::string quest = std::to_string(sector);
  std::string answer = std::to_string(sector);

  quest += ".txt";
  answer += "ans.txt";

  file.open(quest);

  int count = 0;
  char buffer[21];
  while (!file.eof()) {
    file.read(buffer, 20);
    count = file.gcount();
    for (int i = count; i < sizeof(buffer); i++) {
      buffer[i] = 0;
    }
    std::cout << buffer;
  }

  
}

int main() {
  int player_count = 0;
  int viewer_count = 0;
  bool sector[13];
  memset(sector, 1, 13);
  int volchok = 0;
  int ofset = 0;
  bool free_sector = true;
  while (free_sector) {
    std::cout << "Enter ofset: ";
    std::cin >> ofset;
    volchok += ofset;
    if (volchok > 12) {
      volchok %= 13;
    }
    while (!sector[volchok]) {
      volchok++;
      if (volchok > 12) {
        volchok %= 13;
      }
    }

    std::cout << "Sector " << volchok + 1 << "selected";

    if (question) {
      player_count++;
    } else {
      viewer_count++;
    }
    free_sector = false;
    for (size_t i = 0; i < 13; i++) {
      if (sector[i]) {
        free_sector = true;
      }
    }
    if (!free_sector){
        if (player_count > viewer_count){
        std::cout << "Player Win!" << std::endl;
        }else{
        std::cout << "Viewer Win!" << std::endl;
        }
    }
  }
}