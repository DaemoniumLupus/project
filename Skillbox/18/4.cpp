#include <iostream>

void evendigits(long long num, int &ans) {
  if ((num%10)%2 == 0){
    ans++;
  }
  if (num / 10 > 1) {
    evendigits(num / 10, ans);
  }
}

int main() {
  long long num = 9223372036854775806;
  int ans = 0;

  evendigits(num, ans);
  std::cout << ans;
}