#include <iostream>
#include <map>
#include <string>

bool Examination(std::string str) {
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == ' ') {
      return true;
    }
  }
  return false;
}

std::pair<std::string, std::string> Accommodation(std::string str) {

  std::string buf1, buf2;
  int count = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == ' ') {
      count++;
      continue;
    }
    switch (count) {
    case 0:
      buf1 += str[i];
      break;
    case 1:
      buf2 += str[i];
      break;
    default:
      break;
    }
  }
  std::pair<std::string, std::string> Pr(buf1, buf2);
  return Pr;
}

int main() {
  std::string str;
  std::map<std::string, std::string> oMap;
  std::cout << "Enter: ";
  std::getline(std::cin, str);

  while (str != "q") {
    if(str == "list"){
      for (std::map<std::string,std::string>::iterator itf = oMap.begin(); itf != oMap.end(); ++itf)
      {
        std::cout << itf->first << ' ' << itf->second << std::endl;
      }
      
    }
    if (Examination(str)) {
      oMap.insert(Accommodation(str));
    } else {
      std::map<std::string, std::string>::iterator it = oMap.find(str);
      if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' ||
          str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' ||
          str[0] == '8' || str[0] == '9') {
        if (it->first == str) {
          std::cout << it->second << std::endl;
        }
      } else {
        for (std::map<std::string, std::string>::iterator itf = oMap.begin();
             itf != oMap.end(); ++itf) {
          if (itf->second == str) {
            std::cout << itf->first << ' ';
          }
        }
        std::cout << std::endl;
      }
    }
    std::cout << "Enter: ";
    std::getline(std::cin, str);
  }
}