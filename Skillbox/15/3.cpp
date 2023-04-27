#include <iostream>
#include <vector>

int ascending_order(std::vector<int> vec) {

  for (int i = 1; i < vec.size(); i++) {
    for (int j = i; j > 0 && vec[j - 1] > vec[j]; j--) {
      int temp;
      temp = vec[j - 1];
      vec[j - 1] = vec[j];
      vec[j] = temp;
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
    vec.clear();
    while (std::cin >> n && n != -1) {
      // std::cin >> n;
      if (n == -2) {
        break;
      }
      vec.push_back(n);
    }

    // vec.pop_back();

    if (vec.size() >= 5 && n == -1) {

      std::cout << ascending_order(vec) << std::endl;

    } else if (n != -2) {
      std::cerr << "insufficient array size" << std::endl;
    }
  }
}