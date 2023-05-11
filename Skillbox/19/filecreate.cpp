#include <fstream>
#include <iostream>
#include <string>

int main() {
  int sector = 0;
  std::ofstream file;
  for (; sector < 13; sector++) {
    std::string quest_file = "question\\";
    std::string answer_file = "question\\";
    std::string x = std::to_string(sector);
    quest_file += x;
    answer_file += x;
    quest_file += ".txt";
    answer_file += "ans.txt";

    file.open(quest_file);
    file << sector << "\nvopros\n";
    file.close();

    file.open(answer_file);
    file << "otvet";
    file.close();
  }
}