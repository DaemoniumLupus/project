#include <iostream>
#include <map>
#include <string>

void Map() {
  std::map<int, std::string> apartPerson;
  apartPerson[2] = "John";
  apartPerson[5] = "Mary";

  std::cout << apartPerson[2] << std::endl;

  apartPerson[2] = "psix";
  std::cout << apartPerson[2] << std::endl;
}

void Map2() {
  std::pair<std::string, int> oPair("Hello", 5);
  std::map<std::string, int> ourMap;
  ourMap.insert(oPair);

  ourMap.insert(std::pair<std::string, int>("world", 6));
  ourMap.insert(std::pair<std::string, int>("banana", 7));

  std::cout << ourMap["Hello"] << std::endl;

  std::map<std::string, int>::iterator it = ourMap.find("Hello");

  std::cout << it->first << " " << it->second << std::endl;
}

void Map3() {
  std::map<int, std::string> myMap;
  myMap.insert(std::pair<int, std::string>(10, "ten"));
  myMap.insert(std::pair<int, std::string>(11, "eleven"));
  myMap.insert(std::pair<int, std::string>(8, "eight"));
  myMap.insert(std::pair<int, std::string>(6, "six"));
  myMap.insert(std::pair<int, std::string>(7, "seven"));
  myMap.insert(std::pair<int, std::string>(12, "twelve"));
  myMap.insert(std::pair<int, std::string>(2, "two"));

  for (std::map<int, std::string>::iterator it = myMap.begin();
       it != myMap.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }

  std::cout << myMap.begin()->first << std::endl;
}
void Map4() {
  std::map<int, std::string> myMap;
  myMap.insert(std::pair<int, std::string>(10, "ten"));
  myMap.insert(std::pair<int, std::string>(11, "eleven"));
  myMap.insert(std::pair<int, std::string>(8, "eight"));
  myMap.insert(std::pair<int, std::string>(6, "six"));
  myMap.insert(std::pair<int, std::string>(7, "seven"));
  myMap.insert(std::pair<int, std::string>(12, "twelve"));
  myMap.insert(std::pair<int, std::string>(2, "two"));

  std::map<int, std::string>::iterator itf = myMap.find(10);
  myMap.erase(itf);
  myMap.erase(7);

  for (std::map<int, std::string>::iterator it = myMap.begin();
       it != myMap.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}

int main() {
  Map4();
  return 0;
}
