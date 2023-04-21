#include <assert.h>
#include <iostream>
using namespace std;

bool Pop(bool pop[12][12], int x[2], int y[2]) {
  for (int i = x[0]; i <= y[0];i++) {
    for (int j = x[1]; j <= y[1];j++) {
      pop[i][j] = 0;
      cout << "Pop!\n";
    }
  }
  return pop;
}

bool paint(bool pop[12][12]) {
  bool count = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      if (pop[i][j]) {
        cout << "o";
        count = 1;
      } else
        cout << "x";
    }
    cout << endl;
  }
  return count;
}

int main() {
  bool pop_it[12][12];
  int x[2], y[2];

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      pop_it[i][j] = 1;
    }
  }
  while (paint(pop_it)) {
    while (1) {
      cout << "Enter coord:\n 1: ";
      cin >> x[0] >> x[1];
      cout << "\n2: ";
      cin >> y[0] >> y[1];
      if (x[0] >= 0 && x[0] < 12 && x[1] >= 0 && x[1] < 12 && y[0] >= 0 &&
          y[0] < 12 && y[1] >= 0 && y[1] < 12) {
        break;
      } else {
        cout << "\n!!!invalid coord!!!\n";
      }
    }
    Pop(pop_it, x, y);
  }
  /* if (paint(pop)){
    break;
  } */
}