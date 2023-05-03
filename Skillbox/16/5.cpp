#include <iostream>
#include <sstream>
#include <string>

enum switches {
  LIGHTS_INSIDE = 1,
  LIGHTS_OUTSIDE = 2,
  HEATERS = 4,
  WATER_PIPE_HEATING = 8,
  CONDITIONER = 16
};

std::string Time(std::string time) {
  std::string str_1 = "", str;
  int x;
  /* for (int i; i < 2; i++) {
    str_1 += time[i];
  } */

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


int main() {
  int switches_state = 0;
  int t_outside = 0;
  int t_inside = 0;
  bool lights_inside;
  bool movement_outside;
  std::string lighth;
  std::string movement;
  std::string time = "00:00";
  std::string buffer;

  do {
    time = Time(time);
    std::cout << time << std::endl;
    std::cin >> buffer;
    if (buffer != "-1") {
      std::stringstream temp_sream(buffer);
      temp_sream >> t_inside >> t_outside >> movement >> lighth;
        if (movement == "yes"){
          movement_outside = 1;
        }else {
          movement_outside = 0;
        }
        if(lighth == "on"){
          lights_inside = 1;
        }else{
          lights_inside = 0;
        }


    }
  } while (buffer != "-1");
}