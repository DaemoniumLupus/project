#include <iostream>

int rec(int x,int k = 3) {
  int count = 0;
  if (x == 0) {
    return 1;
  }
  for (int i = 1; i <= std::min(x,k); i++) {
    count += rec(x - i,k);
  }
  return count;
}

int main() {
  int n = 3;
  int k = 2;
  /* std::cout << "Enter the number of steps: ";
  std::cin >> n;
  std::cout << "Enter max jump";
  std::cin >> k; */
  
  std::cout << rec(n,k);
}