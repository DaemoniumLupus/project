#include <iostream>
#include <vector>

using namespace std;

void sum_pair(vector<int> vec, int sum) {

  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[i] + vec[j] == sum) {
        cout << vec[i] << " " << vec[j];
        return;
      }
    }
  }
}

int main() {
  // vector<int> vec = { 7, 11, 15,2};
  // int sum = 9;

  int num;
  int sum;
  int size;

  cout << "Input masive size: ";
  cin >> size;

  vector<int> vec(size);

  cout << "Input massive: ";
  for (int i = 0; i < vec.size(); i++) {
    cin >> vec[i];  
  }
  cout << "Input sum: ";
  cin >> sum;

  sum_pair(vec, sum);
}