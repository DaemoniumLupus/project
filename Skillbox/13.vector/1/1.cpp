#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  int n;
  int q;
  int x;
  cout << "Input vector size: ";
  cin >> n;
  cout << "Input numbers: ";
  for (int i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
  }
  cout << "Input number to delete: ";
  cin >> q;
  for (int i = n-1; i >= 0; i--) {
    if (vec[i] == q) {
      swap(vec.back(), vec[i]);
      vec.pop_back();
    }
  }
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
}