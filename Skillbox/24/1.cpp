#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>


bool TaskWork = false;
int count = 1;
std::string name;
std::time_t start;

void Finish() {
  std::time_t fin = std::time(nullptr);
  std::time_t res = std::difftime(fin, start);

  std::ofstream file("status.txt", std::ios::app);
  file << count << ' ' << name << ' ' << res << std::endl;
  file.close();
  count++;
}

void Start() {

  if (TaskWork) {
    Finish();
  }
  start = std::time(nullptr);
  std::cout << "Enter name task: ";
  std::cin >> name;
  TaskWork = true;
}

void Status() {
  std::time_t fileTime;
  int fileCount;
  std::string fileName;

  std::ifstream("status.txt");
  
}

int main() {
  std::string command;

  std::ofstream file("status.txt");
  file.clear();
  file.close();

  while (true) {
    std::cout << "Enter command: ";
    std::cin >> command;

    if (command == "exit") {
      return 0;
    } else if (command == "begin") {
      Start();
    } else if (command == "end") {
      Finish();
    } else if (command == "status") {
      Status();
    } else {
      std::cout << "Incorrect command!" << std::endl;
    }
  }
}