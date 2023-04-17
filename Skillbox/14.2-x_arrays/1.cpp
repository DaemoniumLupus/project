#include <iostream>

using namespace std;

/* void print(int mas[2][6]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6;j++){
      cout << mas[i][j] << " ";
    }
    cout << endl;
  }
  cout << "-------------" << endl;
} */

int main() {
  int knife[2][6];
  int spoon[2][6];
  int fork[2][6];
  int teespoon[2][6];
  //  int cutlery[2][6];
  int dishes[2][6];
  int chairs[2][6];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      // cutlery[i][j] = 3;
      knife[i][j] = 1;
      spoon[i][j] = 1;
      fork[i][j] = 1;
      dishes[i][j] = 2;
      chairs[i][j] = 1;
      if (j == 0) {
        // cutlery[i][j]++;
        teespoon[i][j]++;
        dishes[i][j]++;
      }else
        teespoon[i][j] = 0;
    }
  }

  chairs[0][4]++; // стул для ребенка
  // cutlery[1][2]--;
  spoon[1][2]--; // украденная ложка
  // cutlery[1][0]--;
  spoon[1][0]--;  // Вип поделился ложкой
  spoon[1][2]++;  // ложка передана от Вип
  dishes[1][0]--; // забрали десертную тарелку

  /* print(knife);
  print(spoon);
  print(fork);
  print(dishes);
  print(chairs); */
}


