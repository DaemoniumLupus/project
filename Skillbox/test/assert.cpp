#include <cassert>
#include <iostream>

using namespace std;

float travelTime(float distance, float speed) {
  assert(distance > 0 || speed > 0);
  //assert(speed >= 0);
  return distance / speed;
}

int main() {
  float distance, speed;
  cout << "Enter distance: ";
  cin >> distance;
  cout << "Enter speed: ";
  cin >> speed;
  cout << "Time: " << travelTime(distance, speed) << endl;
}