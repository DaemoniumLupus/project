#include <iostream>
#include <vector>

using namespace std;

vector<int> add_2(vector<int> vec, int val) { // Add elements
  vec.resize(vec.size() + 1);
  vec[vec.size() - 1] = val;
  return vec;
}

vector<int> add(vector<int> vec, int val) { // Add elements
  vector<int> newVec(vec.size() + 1);

  for (int i = 0; i < vec.size(); i++) {
    newVec[i] = vec[i];
  }
  newVec[vec.size()] = val;
  return newVec;
}

vector<int> resize(vector<int> vec) { // remove last element
  vec.resize(vec.size() - 1);
  return vec;
}

vector<int> remove_last(vector<int> vec) { // remove last element
  vector<int> newVec(vec.size() - 1);
  for (int i = 0; i < newVec.size(); i++) {
    newVec[i] = vec[i];
  }
  return newVec;
}

int main() {
  vector<int> vec = {12, 45, 24, 78};

  vec.capacity(); // вместилище вектора
  vec.size();     // занятое место вектора
  vec.push_back(10); // добавление в конец вектора числа 10
  vec.pop_back(); // удаление последнего элемента из вектора
  vec.empty(); // == if (vec.size() == 0)
  vec.front(); // first element of vector
  vec.back();  // last element of vector
  vec.clear(); // clear all element of vector

  int num = 0;
  while (num != -1) {
    cout << "Enter your number: ";
    cin >> num;

    vec = add(vec, num);
  }

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
}
