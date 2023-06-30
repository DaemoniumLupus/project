#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>


int main(){
  std::map<std::string, std::time_t> list;
  std::pair<std::string, std::time_t> workData;
  std::string name;
  std::time_t date;
  while(name != "end"){
    std::cout << "Enter name: ";
    std::cin >> name;
    if (name == "end"){
      break;
    }
    std::cout << "Enter date(YYYY/MM/DD): ";
    std::cin >> date;
    
    workData.first = name;
    workData.second = date;
    list.insert(workData);
  }
}