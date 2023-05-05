#include <iostream>

int rec(int x) {
  int count = 0;
  const int jump = 3;
  if (x == 0) {
    return 1;
  }
  for (int i = 1; i <= x; i++) {
    count += rec(x - i);
  }
  return count;
}

int main() {
  int x;
  std::cout << "Enter x: ";
  std::cin >> x;

  std::cout << rec(x);
}