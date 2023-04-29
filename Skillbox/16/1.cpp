#include <iostream>

int main() {
  float speed = 0.0;
  float delta;
  std::string speed_str;

  char speed_char[5];

  do {
    std::cout << "Input delta speed: ";
    std::cin >> delta;
    if (speed + delta > 150.0) {
      std::cout << "Max speed 150 km/h!\n";
      continue;
    }
    speed += delta;
    if (speed < 0.1) {
      std::sprintf(speed_char, "%.2f", speed);
      speed_str = speed_char;
    } else {
      std::sprintf(speed_char, "%.1f", speed);
      speed_str = speed_char;
    }
    speed_str += " km/h";
    std::cout << speed_str << std::endl;
  } while (speed > 0.01);
}