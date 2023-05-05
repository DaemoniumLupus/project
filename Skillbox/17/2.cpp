#include <iostream>

void Swap_Mas(int *mas) {
  int masReverse[10];
  for (int i = 0; i < 5; i++) {
    masReverse[i] = *(mas + i);
    *(mas + i) = *(mas + 9 - i);
    *(mas + 9 - i) = masReverse[i];
  }
}

int main() {
  int mas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *pmas = mas;
  for (int i = 0; i < 10; i++) {
    std::cout << *(mas + i) << " ";
  }
  Swap_Mas(pmas);
  std::cout << std::endl;
  for (int i = 0; i < 10;i++){
    std::cout << *(mas + i) << " ";
  }
}