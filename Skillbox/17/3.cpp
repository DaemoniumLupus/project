#include <cstring>
#include <iostream>

bool substr(char *a, char *c) {
  int i = 0;
  bool res = true;
  while (*(a + i) != '\0') {
    if (*(a + i) == *c) {
      int j = 0;
      while (*(c + j) != '\0' && *(a + i + j) != '\0') {
        if (*(c + j) != *(a + i + j)) {
          res = false;
        }

        j++;
      }
      return res;
    }else {

    }
    i++;
  }
  res = false;
  return res;
}

int main() {

  char *a = "Hello world";

  char *b = "wor";

  char *c = "Hell";

  std::cout << substr(a, b) << " " << substr(a, c);
}