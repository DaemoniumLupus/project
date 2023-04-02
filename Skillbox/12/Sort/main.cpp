
#include <iostream>

using namespace std;

void heapify(double arr[], int n, int i) {
  int largest = i;

  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapSort(double arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {

    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

void printArray(double arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  double arr[] = {1.2, 2.3,  1.11, 3.4,  5.5,  5.4,  5.3,  5.1,
                  1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n);

  cout << "Sorted array is \n";
  printArray(arr, n);
}