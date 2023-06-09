#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Функция для печати непрерывного подмассива с наибольшей суммой
// в заданном наборе целых чисел
void kadane(vector<int> arr, int n) {
  // базовый вариант
  if (n <= 0) {
    return;
  }

  // сохраняет максимальный суммарный подмассив, найденный на данный момент
  int max_so_far = INT_MIN;

  // сохраняет максимальную сумму подмассива, заканчивающегося на текущей
  // позиции
  int max_ending_here = 0;

  // сохраняет конечные точки найденного до сих пор подмассива максимальной
  // суммы
  int start = 0, end = 0;

  // сохраняет начальный индекс последовательности с положительной суммой
  int beg = 0;

  // обход заданного массива
  for (int i = 0; i < n; i++) {
    // обновить максимальную сумму подмассива, "заканчивающегося" на индексе `i`
    max_ending_here += arr[i];

    // если максимальная сумма станет меньше текущего элемента,
    // начинаем с текущего элемента
    if (max_ending_here < arr[i]) {
      max_ending_here = arr[i];
      beg = i;
    }

    // обновляем результат, если текущая сумма подмассива больше
    if (max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start = beg;
      end = i;
    }
  }

  cout << "The contiguous subarray with the largest sum is ";
  for (int i = start; i <= end; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << start << endl << end;
}

int main() {
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = arr.size();

  kadane(arr, n);

  return 0;
}