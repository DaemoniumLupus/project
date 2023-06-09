#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> myMap;
  std::string command;
  std::cout << "Command: ";
  std::cin >> command;
  while (command != "q") {
    if (command == "list") {
      for (std::map<std::string, int>::iterator it = myMap.begin();
           it != myMap.end(); ++it) {
        std::cout << it->first << ' ' << it->second << std::endl;
      }
    } else if (command == "Next" && !myMap.empty()) {
      std::map<std::string, int>::iterator it = myMap.begin();
      std::cout << it->first << std::endl;
      myMap.erase(it);
    } else {
      myMap.insert(std::pair<std::string, int>(command, 1));
    }

    std::cout << "Command: ";
    std::cin >> command;
  }
}