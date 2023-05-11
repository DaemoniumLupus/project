#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::srand(std::time(nullptr));
  int height;
  int width;
  std::cout << "Enter heigth: ";
  std::cin >> height;
  std::cout << "Enter width: ";
  std::cin >> width;

  std::vector<std::vector<int>> pic(height, std::vector<int>(width));

  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      pic[i][j] = std::rand() % 2;
    }
  }

  std::ofstream file("picture.txt");
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      file << pic[i][j];
    }
    file << std::endl;
  }
  
}