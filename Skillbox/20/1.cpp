#include <fstream>
#include <iostream>

bool valid(std::string note, std::string &name, std::string &surname,
           std::string &date, int &sum_int) {
  std::string sum;
  int count = 0;
  int words_count = 0;

  for (size_t i = 0; i < note.length(); i++) {
    if (note[i] == ' ') {
      words_count++;
    }
  }
  if (words_count >= 4 && words_count < 3) {
    return false;
  }

  for (int i = 0; i < note.length(); i++) {
    if (note[i] == ' ') {
      count++;
      continue;
    }
    switch (count) {
    case 0:
      name += note[i];
      break;
    case 1:
      surname += note[i];
      break;
    case 2:
      date += note[i];
      break;
    case 3:
      sum += note[i];
      break;

    default:
      break;
    }
  }
if (sum[0] <'0' || sum[0] > '9' ){
    std::cerr << "Invalid data!" << std::endl;
    return 0;
}
  sum_int = std::stoi(sum);

  int mounth;
  int day;
  int year;

  day = std::stoi(date.substr(0, 2));
  if (day > 31 || day <= 0){
    std::cerr << "Invalid date!" << std::endl;
    return 0;
  }
  mounth = std::stoi(date.substr(3, 2));
  if (mounth > 12 || mounth <= 0) {
    std::cerr << "Invalid date!" << std::endl;
    return 0;
  }
  year = std::stoi(date.substr(6));
  if (year > 2050 || year <= 0) {
    std::cerr << "Invalid date!" << std::endl;
    return 0;
  }

  return 1;
}

bool write_in_file(std::string note) {
  std::string name;
  std::string surname;
  std::string date;
  int sum;

  if (valid(note, name, surname, date, sum)) {

    std::ofstream file("statement.txt",std::ios::app);
    file << name << ' ' << surname << ' ' << date << ' ' << sum << std::endl;
    file.close();
  } else {
    
    return 0;
  }
  return 1;
}

int main() {
  std::string note;

  while (note != "-1") {
    std::cout << "Enter the data(name surname DD.MM.YYYY sum): ";
    std::getline(std::cin, note);

    if (note != "-1") {
      if (write_in_file(note)) {
        std::cout << "Entry added.\n";
      }
    } else {
      break;
    }
  }
}