#include <fstream>
#include <iostream>

int main() {
  std::ifstream type;
  std::string path = " ";

  std::string str;
  std::string str2;
  while (!(path == "-1")) {
    do {
      std::cout << "Enter file path: ";
      std::cin >> path;
      if (path == "-1") {
        break;
      }
      type.open(path, std::ios::binary);

    } while (!type.is_open());

    type >> str;
    str2 = str.substr(0, 4);
    str.clear();
    if ((int)str2[0] == -119 && str2[1] == 'P' && str2[2] == 'N' &&
        str2[3] == 'G') {
      std::cout << "True" << std::endl;
    }else{
      std::cout << "False" << std::endl;
    }
    str2.clear();
    type.close();
  };
}