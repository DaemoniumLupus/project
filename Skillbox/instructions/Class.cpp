/* #include <iostream>

struct robot_t {
  int health;
  int damage;
  int speed;

  void attack() { std::cout << "Attack: " << damage << std::endl; }

  void take_damage() { std::cout << "Damage: " << health << std::endl; }

  void move() { std::cout << "Moving: " << speed << std::endl; }
};

int main() {
  robot_t *robot = new robot_t{50, 100, 10};
  robot->attack();
  delete robot;
} */

#include <iostream>

class PlaneControl {
  double leftAileron = 0;
  double rightAileron = 0;
  double elevator = 0;

public:
  void turnLeft() {
    leftAileron -= 30;
    rightAileron += 30;
  }

  void turnRigth() {
    rightAileron -= 30;
    leftAileron += 30;
  }

  void setElevator(double value) {
    if (value < -30)
      value = -30;
    if (value > 30)
      value = 30;
    if (value == elevator)
      return;
    elevator = value;
  }

  double getLeftAileron() { return leftAileron; }
  double getRigthAileron() { return rightAileron; }
  double getElevator() { return elevator; }

  static void showInfo(PlaneControl *planeControl) {
    std::cout << "Left aileron: " << planeControl->leftAileron << std::endl;
    std::cout << "Rigth aileron: " << planeControl->rightAileron << std::endl;
    std::cout << "Elevator: " << planeControl->elevator << std::endl;
  }
};


int main() {
  PlaneControl *planeControl = new PlaneControl();
  planeControl->turnLeft();
  planeControl->setElevator(13.5);

  PlaneControl::showInfo(planeControl);

  delete planeControl;
  planeControl = nullptr;
}