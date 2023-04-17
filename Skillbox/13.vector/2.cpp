#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<float> price = {2.5, 4.25, 3.0, 10.0};
  vector<int> items = {1, 1, 0, 3};
  float summ = 0.0;
  for (int i = 0; i < items.size(); i++) {
    assert(items[i] < price.size());
    summ += price[items[i]];
  }
  cout << "The total cost will be: " << summ;
}