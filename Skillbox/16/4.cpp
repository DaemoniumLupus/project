#include <iostream>

enum { DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64 };
void play(int accord) {
  if (accord & DO) {
    std::cout << "DO ";
  }

  if (accord & RE) {
    std::cout << "RE ";
  }

  if (accord & MI) {
    std::cout << "MI ";
  }

  if (accord & FA) {
    std::cout << "FA ";
  }

  if (accord & SOL) {
    std::cout << "SOL ";
  }

  if (accord & LA) {
    std::cout << "LA ";
  }

  if (accord & SI) {
    std::cout << "SI ";
  }
}
int transform(std::string notes_str) {
  int notes = 0;
  for (int i = 0; i < notes_str.size(); i++) {
    switch (notes_str[i]) {
    case '1':
      notes = notes | DO;
      break;
    case '2':
      notes = notes | RE;
      break;
    case '3':
      notes = notes | MI;
      break;
    case '4':
      notes = notes | FA;
      break;
    case '5':
      notes = notes | SOL;
      break;
    case '6':
      notes = notes | LA;
      break;
    case '7':
      notes = notes | SI;
      break;

    default:
      break;
    }
  }
  return notes;
}

int main() {
  std::string notes_string; /*[12]  = {"125", "125", "125", "125", "125", "125",
                                   "125", "125", "125", "125", "125", "125"}; */
  int melody_transform[12];

  for (int i = 0; i < 12; i++) {
    std::cout << "Input " << i + 1 << " accord: ";
    std::cin >> notes_string;
    std::cout << std::endl;
    melody_transform[i] = transform(notes_string);
  }
  for (int i = 0; i < 12; i++) {
    play(melody_transform[i]);
    std::cout << std::endl;
  }
}