#include <iostream>
#include <stdio.h>

using namespace std;

/*  1 2 3
  1|X|X|X
  2|O|O|O
  3|X|X|X */

void paint(char mas[3][3]) {
  cout << "  " << 1 << " " << 2 << " " << 3 << " y"<<endl;
  for (int i = 0; i < 3; i++) {
    cout << i + 1 << "|";
    for (int j = 0; j < 3; j++) {
      cout << mas[i][j];
      if (j < 2) {
        cout << "|";
      }
    }
    cout << endl;
  }
  cout << "x" << endl;
}
/* bool busy_element(bool mas[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!mas[i][j]) {
        return true;
      }
    }
  }
  return false;
} */
char whoVin(char mas[3][3]) {
  int gorX[3]{0, 0, 0}, vertX[3]{0, 0, 0};
  int gorO[3]{0, 0, 0}, vertO[3]{0, 0, 0};
  bool X = 0;
  bool O = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mas[i][j] == 'X') {
        gorX[i]++;
      }
      if (mas[i][j] == 'O') {
        gorO[i]++;
      }
      if (mas[j][i] == 'X') {
        vertX[i]++;
      }
      if (mas[j][i] == 'O') {
        vertO[i]++;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (gorX[i] == 3 || vertX[i] == 3) {
      X = 1;
    }
    if (gorO[i] == 3 || vertO[i] == 3) {
      O = 1;
    }
  }

  if (X) {
    return 'X';
  } else if (O) {
    return 'O';
  } else {
    return ' ';
  }
}

int main() {
  bool busy[3][3]{
      {false, false, false}, {false, false, false}, {false, false, false}};
  char symbol[3][3];
  char gamer_name = 'X';
  int x, y;
  int count = 9;
  char winner = ' ';

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      symbol[i][j] = '\'';
    }
  }
  paint(symbol);
  while (/* busy_element(busy) */ count > 0) {
    cout << "Player turn " << gamer_name <<" (x y): ";
    do {
      cin >> x >> y;
      if (x <= 0 || x >= 4 || y <= 0 || y >= 4) {
        cout << "Again\n";
      }
      x--;
      y--;

      if (busy[x][y] == true) {
        cout << "Busy! Again\n";
      }
    } while (busy[x][y] == true || x < 0 || x > 2 || y < 0 || y > 2);

    busy[x][y] = true;
    symbol[x][y] = gamer_name;
    count--;
    winner = whoVin(symbol);
    paint(symbol);

    if (winner != ' ') {
      count = 0;
      cout << winner << " winner!";
    }
    if (gamer_name == 'X') {
      gamer_name = 'O';
    } else {
      gamer_name = 'X';
    }
  }
}