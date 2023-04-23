#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void kadane(vector<int> arr, int n) {

  if (n <= 0) {
    return;
  }

  int max_so_far = INT_MIN;
  int max_ending_here = 0;
  int start = 0, end = 0;
  int beg = 0;

  for (int i = 0; i < n; i++) {
    max_ending_here += arr[i];
    if (max_ending_here < arr[i]) {
      max_ending_here = arr[i];
      beg = i;
    }
    if (max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start = beg;
      end = i;
    }
  }

  cout << "The contiguous subarray with the largest sum is ";
 /*  for (int i = start; i <= end; i++) {
    cout << arr[i] << " ";
  } */
  cout  << start << " " << end;
}

int main() {
  vector<int> arr =   {-2, 1, -3, 4, -1, 2, 1, -5, 4} ;
  int n = arr.size();

  kadane(arr, n);

  return 0;
}