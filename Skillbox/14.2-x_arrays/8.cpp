#include <iostream>

using namespace std;

bool field_1[10][10];
bool field_2[10][10];

bool place_ship(bool field[][10], int size) {
  int x_s, y_s, x_e, y_e;

  cout << "Start X Y: ";
  cin >> x_s >> y_s;
  if (size == 0) {
    cerr << "Invalid size:" << size << endl;
    return false;
  }
  if (size > 1) {
    cout << "End X Y:";
    cin >> x_e >> y_e;
  } else {
    x_e = x_s;
    y_e = y_s;
  }

  if (x_e < x_s) {
    int tmp = x_s;
    x_s = x_e;
    x_e = tmp;
  }

  if (y_e < y_s) {
    int tmp = y_s;
    y_s = y_e;
    y_e = tmp;
  }

  if (x_s < 0 || x_e >= 10 || y_s < 0 || y_e >= 10) {
    cerr << "Out of bounds!" << endl;
    return false;
  }

  int d_x = x_e - x_s;
  int d_y = y_e - y_s;

  if (d_x != 0) {
    if (d_x + 1 != size) {
      cerr << "Invalid ship size:" << size << endl;
      return false;
    }
    if (d_y != 0) {
      cerr << "Diagonal ship not supported!" << endl;
      return false;
    }

    int y = y_s;
    for (int x = x_s; x <= x_e; x++) {
      if (field[x][y]) {
        cerr << "collision detected!" << endl;
        return false;
      }
    }
    for (int x = x_s; x <= x_e; x++) {
      field[x][y] = true;
    }
  } else {

    if (d_y + 1 != size) {
      cerr << "Invalid ship size:" << size << endl;
      return false;
    }
    if (d_x != 0) {
      cerr << "Diagonal ship not supported!" << endl;
      return false;
    }
    int x = x_s;
    for (int y = y_s; y <= y_e; y++) {
      if (field[x][y]) {
        cerr << "collision detected!" << endl;
        return false;
      }
    }
    for (int y = y_s; y <= y_e; y++) {
      field[x][y] = true;
    }
  }
}

void place_ships(bool field[][10]) {
  for (int i = 0; i < 4; i++) {
    cout << "TINY []" << endl;
    while (!place_ship(field, 1)) {
      cout << "Please, try again" << endl;
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << "SMALL [][]" << endl;
    while (!place_ship(field, 2)) {
      cout << "Please, try again" << endl;
    }
  }

  for (int i = 0; i < 2; i++) {
    cout << "MEDIUM [][][]" << endl;
    while (!place_ship(field, 3)) {
      cout << "Please, try again" << endl;
    }
  }

  cout << "BIG [][][][]" << endl;
  while (!place_ship(field, 4)) {
    cout << "Please, try again" << endl;
  }
}
bool attack(bool field[][10]) {
  int x, y;
  cout << "X Y:" << endl;
  cin >> x >> y;
  if (x >= 0 && x < 10 && y >= 0 && y < 10 && field[x][y]) {
    cout << "Damage!" << endl;
    field[x][y] = false;
    return true;
  } else {
    cout << "MISS!" << endl;
    return false;
  }
}

int main() {
  cout << "Player 1, place ships!" << endl;
  place_ships(field_1);
  cout << "Player 2, place ships!" << endl;
  place_ships(field_2);

  int player_1_block_left = 4 * 1 + 3 * 2 + 2 * 3 + 1 * 4;
  int player_2_block_left = 4 * 1 + 3 * 2 + 2 * 3 + 1 * 4;

  while(true){
    cout << "Player 1, attack!" << endl;
    if (attack(field_2)){
      player_2_block_left -= 1;
    }
    if(player_2_block_left == 0){
      cout << "Player 1 Wins!" << endl;
      return 0;
    }
    cout << "Player 2, attack!" << endl;
    if (attack(field_1)) {
      player_1_block_left -= 1;
    }
    if (player_1_block_left == 0) {
      cout << "Player 2 Wins!" << endl;
      return 0;
    }
  }
}