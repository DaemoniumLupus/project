#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

/*  std::vector<int> sort(std::vector<int> vec) {
  for (int i = 1; i < vec.size(); i++) {
    for (int j = i; j > 0 && vec[j - 1] > vec[j]; j++) {
      int temp;
      temp = vec[j - 1];
      vec[j - 1] = vec[j];
      vec[j] = temp;
    }
  }
   return vec;
}  */

int main() {
  std::vector<int> vec = {-50, -5, 1, 10, 15,-100};
  // bool x = true;
   /*int n;
   while (true) {
    std::cin >> n;
    vec.push_back(n);
    if (std::cin.get() == '\n') {
      // x = false;
      break;
    }
  }  */

   //sort(vec); // вылет то ли за пределы памяти, то ли еще что то
   //остановка на строчке:
   //_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
   // файл new_allocator.h
   
     for (int q = 0; q < vec.size(); q++) {
      for (int i = 1; i < vec.size(); i++) {
        for (int j = i; j > 0 && std::abs(vec[j - 1]) > std::abs(vec[j]); j++) {
          int temp;
          temp = vec[j - 1];
          vec[j - 1] = vec[j];
          vec[j] = temp;
        }
      }
    } 

   for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
}