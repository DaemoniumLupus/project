#include <iostream>
#include <vector>




int ascending_order(std::vector<int> vec) {
  int max = 0;
  int max_ind = 0;
  for (int i = 1; i < vec.size(); i++) {
    for (int j = 1; j < vec.size(); j++)
    {
        
    
    
      if (vec[i] > vec[i-1]) {
        int temp;
        temp = vec[i - 1];
        vec[i - 1] = vec[i];
        vec[i] = temp;
      }
    
    }
  }
  std::cout << std::endl;
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  return vec[4];
}

int main() {
  std::vector<int> vec;
  int n = 0;

  std::cout << "Input number: ";

  while (n != -2) {
    n = 0;
    while (n != -1) {
      std::cin >> n;
      if (n != -1 || n != -2) {
        vec.push_back(n);
      }
    }
    vec.pop_back();
    std::cout << ascending_order(vec);
  }
}