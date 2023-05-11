#include <iostream>
#include <fstream>

int main() {
  std::string buf;
  std::string fish;
  int count = 0;
  std::cout << "Enter name fish): ";
  std::cin >> buf;


  std::ifstream read("river.txt");
  std::ofstream write("basket.txt",std::ios::app);

  if (!read.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return 1;
  }
  if (!write.is_open()) {
    std::cerr << "Нельзя открыть файл\n";
    return 1;
  }

  while(!read.eof()){
    read >> fish;
    if (buf == fish){
      count++;
      write << buf << std::endl;
    }
  }
  read.close();
  write.close();

  std::cout << "Fish caught: " << count << std::endl;
}