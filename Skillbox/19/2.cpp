#include <fstream>
#include <iostream>

int main() {
  std::ifstream text;
  std::string path;

  do {
    std::cout << "Enter file path: ";
    std::cin >> path;

    text.open(path);

  } while (!text.is_open());
  
  int count = 0;
  char buffer[21];
  while (!text.eof()) {
    text.read(buffer, 20);
    count = text.gcount();
    for (int i = count; i < sizeof(buffer);i++){
      buffer[i] = 0;
    }
      
    std::cout << buffer;
  }
  text.close();
}