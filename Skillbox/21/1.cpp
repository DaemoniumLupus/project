#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct note {
  std::string name;
  std::string date;
  int sum;
};
bool Valid(std::string str, note &statement) {
  std::string sum_str;
  int count = 0;
  int words_count = 0;

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      words_count++;
    }
  }
  if (words_count >= 4 && words_count < 3) {
    return false;
  }

  bool count2 = true;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      count++;
      continue;
    }

    if (count == 1 && count2) {
      statement.name += ' ';
      count2 = false;
    }
    switch (count) {
    case 0:
      statement.name += str[i];
      break;
    case 1:
      statement.name += str[i];
      break;
    case 2:
      statement.date += str[i];
      break;
    case 3:
      sum_str += str[i];
      break;

    default:
      break;
    }
  }
  statement.sum = std::stoi(sum_str);
  return true;
}

void Add(std::vector<note> &statement) {
  std::string str, str2;
  char len = 0;
  std::cout << "Enter data (name surname DD.MM.YYYY sum): ";
  // std::getline(std::cin,str)//не работает ошибка: terminate called after
  // throwing an instance of 'std::invalid_argument'what() : stoi
  std::cin >> str;
  std::cin >> str2;
  str += ' ';
  str += str2;
  str2.clear();
  std::cin >> str2;
  str += ' ';
  str += str2;
  str2.clear();
  std::cin >> str2;
  str += ' ';
  str += str2;

  statement.resize(1);
  if (Valid(str, statement[0])) {
    std::ofstream file("statement.txt", std::ios::app);
    len = (char)statement[0].name.size();
    file.write((char *)&len, sizeof(len));
    file.write((char *)statement[0].name.c_str(), len);
    file << ' ';
    file.write((char *)statement[0].date.c_str(), 10);
    file << ' ';
    file.write((char *)&statement[0].sum, sizeof(statement[0].sum));
    file << std::endl;
    file.close();
  }
}

void List(std::vector<note> &statement) {
  std::ifstream file("statement.txt", std::ios::binary);

  file.seekg(0);
  char buf;
  int count = 0;
  int len = 0;
  if (file.is_open()) {
    while (!file.eof()) {
      statement.resize(statement.size() + 1);
      // read >> statement[count].name >> statement[count].surname
      file.read((char *)&len, 1);
      statement[count].name.resize(len);
      file.read((char *)statement[count].name.c_str(), len);
      if (statement[count].name.empty()){
        statement.resize(statement.size() - 1);
        break;
      }
      file.read((char *)&buf, 1);
      file >> statement[count].date;
      //file.read((char *) statement[count].date.c_str(), 10);
      // не читает дату
      file.read((char *)&buf, 1);
      //std::cout << sizeof(statement[count].sum) << std::endl << file.tellg();
      
      file.read((char *)&statement[count].sum, sizeof(statement[count].sum));
      //std::cout << std::endl << file.tellg() << std::endl;
      file.read((char *)&buf, 1);
      file.read((char *)&buf, 1);
      len = 0;
      count++;
      if (file.eof()) {
        break;
      }
    }
    for (size_t i = 0; i < statement.size(); i++) {
      std::cout << statement[i].name << ' ' << statement[i].date << ' '
                << statement[i].sum << std::endl;
    }
  } else {
    std::cerr << "ERROR!" << std::endl;
  }
  file.close();
  statement.resize(0);
}

int main() {
  std::vector<note> statement;
  std::string command;
  std::cout << "Choose an action: ";
  std::cin >> command;
  while (command != "-1") {
    if (command == "list") {
      statement.resize(0);
      statement.clear();
      List(statement);
    } else if (command == "add") {
      statement.clear();
      Add(statement);
    } else if (command == "0") {
      std::ofstream file("statement.txt");
      file.clear();
      file.close();
    }
    std::cout << "Choose an action: ";
    std::cin >> command;
  }
}