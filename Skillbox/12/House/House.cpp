#include <iostream>

using namespace std;

int main() {
  string surname[10];
  int aparts;
  for (int i = 0; i < 10; i++) {
    cout << "\nEnter surname who life in " << i + 1 << " aparts: ";
    cin >> surname[i];
  }
  for (int i = 0; i < 3; i++) {
    cout << "\nEnter number aparts: ";
    cin >> aparts;
    if (aparts > 0 && aparts <= 10) {
      cout << surname[aparts - 1];
    } else {
      cout << "\nIncorrect!";
      i--;
    }
  }
}