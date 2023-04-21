#include <iostream>

using namespace std;
//{{1,2,3,4},{2,1,3,4},{3,2,1,4},{4,2,3,1}}
//{{1,2,3,4},{3,2,1,4},{2,1,3,4},{4,2,3,1}}
bool equals(int mas_1[4][4], int mas_2[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (mas_1[i][j] != mas_2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int cast(int mas[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j) {
        mas[i][j] = 0;
      }
    }
  } 
}

int main() {
  int mas1[4][4]  {{1, 2, 3, 4}, {2, 1, 3, 4}, {3, 2, 1, 4}, {4, 2, 3, 1}} ;
  int mas2[4][4]{{1, 2, 3, 4}, {3, 2, 1, 4}, {2, 1, 3, 4}, {4, 2, 3, 1}};
  /*
  cout << "Input fist matrix: " << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> mas1[i][j];
    }
  }
  cout << "Input second matrix: " << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> mas2[i][j];
    }
  } */

  if (equals(mas1, mas2)) {
    mas1[4][4] = cast(mas1);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << mas1[i][j];
      }
      cout << endl;
    }
  }
}