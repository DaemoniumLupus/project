#include <cstring>
#include <fstream>
#include <iostream>

bool question(int sector, bool &free) {
  std::ifstream file;
  std::string answer;
  std::string true_answer;
  std::string x;
  std::string quest_file = "question\\";
  std::string answer_file = "question\\";
  x = std::to_string(sector);

  quest_file += x;
  answer_file += x;
  quest_file += ".txt";
  answer_file += "ans.txt";

  file.open(quest_file);

 /*  if (file.is_open()) {
    std::cout << "!!!";
  } */

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

  file.close();

  std::cout << "Enter answer: ";
  std::cin >> answer;

  file.open(answer_file);

  file >> true_answer;

  free = false;

  if (answer == true_answer) {
    return true;
  } else {
    return false;
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
      if (volchok > 13) {
        volchok %= 14;
      }
    }

    std::cout << "Sector " << volchok + 1 << " selected" << std::endl;

    if (question(volchok+1, sector[volchok])) {
      player_count++;
    } else {
      viewer_count++;
    }
    /* free_sector = false;
    for (size_t i = 0; i < 13; i++) {
      if (sector[i]) {
        free_sector = true;
        break;
      } */

    if (player_count >= 6 || viewer_count >= 6) {
      if (player_count > viewer_count) {
        std::cout << "Player Win!" << std::endl;
        free_sector = false;
      } else {
        std::cout << "Viewer Win!" << std::endl;
        free_sector = false;
      }
    }
  }
}
