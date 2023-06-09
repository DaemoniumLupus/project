#include <iostream>
#include <map>
#include <string>

bool anagramm(std::map<std::string, std::string> myMap) {
  std::map<std::string, std::string>::iterator it = myMap.begin();
  std::string str1 = it->first;
  std::string str2 = it->second;
  std::map<char, int> Key1;
  std::map<char, int> Key2;
  if (str1.size() != str2.size()) {
    return false;
  }
  for (size_t i = 0; i < str1.size(); i++) {
    Key1.insert(std::pair<char, int>(str1[i], i));
    Key2.insert(std::pair<char, int>(str2[i], i));
  }
  str1.clear();
  str2.clear();
  for (std::map<char, int>::iterator itf = Key1.begin(); itf != Key1.end();++itf){
    str1 += itf->first;
  }
  for (std::map<char, int>::iterator itf = Key2.begin(); itf != Key2.end();++itf){
    str2 += itf->first;
  }
  if (str1 == str2){
    return true;
  }
  return false;
}

int main(){
  std::string str1, str2;
  std::map<std::string, std::string> myMap;

  std::cout << "Enter first word: ";
  std::cin >> str1;
  std::cout << "Enter second word: ";
  std::cin >> str2;

  myMap.insert(std::pair<std::string, std::string>(str1, str2));

  if (anagramm(myMap)){
    std::cout << "True" << std::endl;
  }else {
    std::cout << "False" << std::endl;
  }
}