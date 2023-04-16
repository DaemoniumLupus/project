#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> db(20);
  int x = 0;

  while (x != -2) {

    cout << "Input number: ";
    cin >> x;
    if (x != -1) {
      if (db.capacity() == db.size()) {
        db.erase(db.begin());
      }
      db.push_back(x);
    }

    if (x == -1) {
      cout << "Output: ";
      for (int i = 0; i < db.size(); i++) {
        cout << db[i] << " ";
      }
      cout << endl;
    }
  }
}