#include <iostream>
#include <vector>

using namespace std;

void unic_num() {//уникальные числа
  vector<int> vec = {1, 1, 1, 5, 5, 7, 4, 6, 1, 5};

  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] != -1) {
      for (int j = i + 1; j < vec.size(); j++){
        if (vec[j] == vec[i]){
          vec[j] = -1;
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < vec.size(); i++){
    if (vec[i] != -1){
      ++res;
    }
  }
  cout << res;
}


void rep_nums() {//какое число повторяется больше раз
  vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 3, 3, 3, 3};
  vector<int> temp(vec.size(), 0);

  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] != -1) {
      for (int j = i + 1; j < vec.size(); j++) {
        if (vec[j] == vec[i]) {
          vec[j] = -1;
          temp[i] += 1;
        }
      }
    }
  }

   for (int i = 0; i < vec.size(); i++) {
    cout << temp[i] << " ";
  }
  cout << endl;

  int max_ind = 0;
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] > temp[max_ind]) {
      max_ind = i;
    }
  }
  cout << vec[max_ind];
} 

void birge() {
  vector<int> vec = {7, 1, 5, 4, 6, 3};
  int max_pr = 0;
  int min_w = vec[0];

  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] < min_w) {
      min_w = vec[i];
    }

    if (max_pr < vec[i] - min_w) {
      max_pr = vec[i] - min_w;
    }
  }

  cout << max_pr;
}