#include <iostream>
#include <sstream>
#include <string>

int switches_state = 0;


enum switches {
  LIGHTS_INSIDE = 1,
  LIGHTS_OUTSIDE = 2,
  HEATERS = 4,
  WATER_PIPE_HEATING = 8,
  CONDITIONER = 16
};

std::string Time(std::string time) {
  std::string str_1, str;
  int x;
  x = std::stoi(time);
  x++;
  if (x == 24) {
    x = 0;
  }
  if (x >= 10) {
    str_1 = std::to_string(x);
  } else {
    str_1 = '0';
    str_1 += std::to_string(x);
  }
  time = str_1 + ":00";
  return time;
}

int Control(std::string buffer,std::string time/* int t_outside, int t_inside, bool movement, bool lighth,
             std::string time, int count */) {

  int count;
  int count_2;
  int time_num;
  int t_outside = 0;
  int t_inside = 0;
  bool lighth_inside;
  bool movement_outside;
  std::string lighth;
  std::string movement;

  time_num = std::stoi(time);
  std::stringstream temp_sream(buffer);
  temp_sream >> t_inside >> t_outside >> movement >> lighth;
  if (movement == "yes") {
    movement_outside = 1;
  } else {
    movement_outside = 0;
  }
  if (lighth == "on") {
    lighth_inside = 1;
  } else {
    lighth_inside = 0;
  }

  if (t_outside < 0) {
    switches_state |= WATER_PIPE_HEATING;
  } else if (t_outside > 5 && count & WATER_PIPE_HEATING) {
    switches_state &= ~WATER_PIPE_HEATING;
  }else{

  }

  return count_2;
}
int main() {
  /* int count;
  int switches_state = 0;
  int t_outside = 0;
  int t_inside = 0;
  bool lighth_inside;
  bool movement_outside;
  std::string lighth;
  std::string movement; */
  std::string time = "00:00";
  std::string buffer;

  do {
    time = Time(time);
    std::cout << time << std::endl;
    std::cin >> buffer;
    if (buffer != "-1") {
      /* std::stringstream temp_sream(buffer);
      temp_sream >> t_inside >> t_outside >> movement >> lighth;
      if (movement == "yes") {
        movement_outside = 1;
      } else {
        movement_outside = 0;
      }
      if (lighth == "on") {
        lighth_inside = 1;
      } else {
        lighth_inside = 0;
      } */

      count = Control(buffer,time/* t_inside, t_outside, movement_outside, lighth_inside, time,
              count */);
    }
  } while (buffer != "-1");
}