#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream statement;
  std::vector<std::string> name;
  //std::vector<std::string> surname;
  std::vector<int> money;
  std::vector<std::string> date;

  std::string buf_name;
  std::string buf_surname;
  int buf_money;
  std::string buf_date;

  statement.open("statement.txt");

  while (!statement.eof()) {
    statement >> buf_name >> buf_surname >> buf_money >> buf_date;
    buf_name += ' ';
    buf_name += buf_surname;
    name.push_back(buf_name);
    //surname.push_back(buf_surname);
    money.push_back(buf_money);
    date.push_back(buf_date);
  }

  statement.close();

  int max = 0;
  int sum = 0;

  for (int i = 0; i < money.size();i++){
    sum += money[i];
    if (money[i] > money[max]){
      max = i;
    }
  }

  std::cout << "The amount of payments: " << sum << std::endl;
  std::cout << name[max] << " " /* << surname[max] */ << " has the highest payouts." << std::endl;

  
}