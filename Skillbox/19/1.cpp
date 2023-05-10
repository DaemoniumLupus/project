#include <fstream>
#include <iostream>

int main() {
  std::ifstream words;
  words.open("words.txt");
  std::string sWords;
  std::cout << "Enter the search word: ";
  std::cin >> sWords;

  std::string buffer;
  int count = 0;
  while(!words.eof()){
    words >> buffer;
    if (buffer == sWords){
      count++;
    }
  }
  std::cout << count << std::endl;
  words.close();
}