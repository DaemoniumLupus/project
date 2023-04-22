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
    if (d_y != 0){
      cerr << "Diagonal ship not supported!" << endl;
      return false;
    }

    int y = y_s;
    for (int i = x_s; i < count; i++)
    {


    }
    
  }
}

int main() { bool plant[10][10]; }