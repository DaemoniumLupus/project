#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> vec, int val) {//Add elements 
  vector<int> newVec(vec.size() + 1);

  for (int i = 0; i < vec.size(); i++) {
    newVec[i] = vec[i];
  }
  newVec[vec.size()] = val;
  return newVec;
}

int main() {
  vector<int> vec = {12, 45, 24, 78};

  int num = 0;
  while (num != -1) {
    cout << "Enter your number: ";
    cin >> num;

    vec = add(vec, num);
  }

  for (int i = 0; i < vec.size();i++){
    cout << vec[i] << " ";
  }
}
