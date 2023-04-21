#include <iostream>
#include <vector>

using namespace std;
/*
vector<float> multiplication(float mas[4][4], vector<float> vec, vector<float> res) {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      res[j] += vec[i] * mas[j][i];
    }
  }
  return res;
}
*/
int main() {
  vector<float> b(4);
  vector<float> c = {0, 0, 0, 0};
  float a[4][4];

  cout << "Input vector b: ";
  for (int i = 0; i < 4; i++) {
    cin >> b[i];
  }
  cout << "Input matrix a: ";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }

  // c = multiplication(a, b, c);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      c[j] += b[i] * a[j][i];
    }
  }

  for (int i = 0; i < 4; i++) {
    cout << c[i] << " ";
  }
}