#include <array>
#include <iostream>

using namespace std;

int fourth[7] = {0, 0, 0, 0, 0, 0, 0};

void min(int mas[], int n) { // нахождение минимального элемента массива
  int min = mas[0];
  for (int i = 0; i < n; i++) {
    if (mas[i] < min) {
      min = mas[i];
    }
  }
  cout << min << " ";
}

void zapol(int mas[], int n) { // заполнение массивов с клавиатуры
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
}

void srednee(int x, int y, int mas[]) { // нахождение среднего в интервале
  float sr = 0;
  for (int i = x - 1; i < y; i++) {
    sr += mas[i];
  }
  cout << fixed;
  cout.precision(1);
  cout << sr / (y - x + 1) << endl;
}

void povtor(int mas[], int n) {
  for (int i = 0; i < n; i++) {
  }
}

int main() {
  int first[8];
  int second[7];
  int third[6];

  int x = 0, y = 0;

  while (true) {

    zapol(first, sizeof(first) / sizeof(first[0]));
    zapol(second, sizeof(second) / sizeof(second[0]));
    zapol(third, sizeof(third) / sizeof(third[0]));

    cin >> x >> y; // введение начального и конечного элемента 3-го массива

    min(first, sizeof(first) / sizeof(first[0]));
    min(second, sizeof(second) / sizeof(second[0]));
    min(third, sizeof(third) / sizeof(third[0]));

    povtor(first, sizeof(first) / sizeof(first[0]));
    povtor(second, sizeof(second) / sizeof(second[0]));
    povtor(third, sizeof(third) / sizeof(third[0]));

    printf("\n");
    srednee(x, y, third);

    for (int i = 0; i < sizeof(first) / sizeof(first[0]); i++) {
      for (int j = 0; j < sizeof(second) / sizeof(second[0]); j++) {
        for (int q = 0; q < sizeof(third) / sizeof(third[0]); q++) {
          if (first[i] == second[j] && first[i] == third[q]) {
            fourth[first[i] - 12]++;
          }
        }
      }
    }
    for (int i = 0; i < 7; i++) {
      if (fourth[i] > 0) {
        cout << i + 12 << " ";
      }
    }
  }
}