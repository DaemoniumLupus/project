#include <iostream>

void Swap_pointer(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

int main() {
  int a, b;
  int *pa = &a;
  int *pb = &b;
  std::cout << "Enter a: ";
  std::cin >> a;
  std::cout << "Enter b: ";
  std::cin >> b;

  Swap_pointer(pa, pb);

  std::cout << a << " " << b << std::endl;
}