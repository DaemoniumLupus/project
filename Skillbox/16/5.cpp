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

int Control(std::string buffer,std::string time) {

  int count = 0;
  int time_num;
  int t_outside = 0;
  int t_inside = 0;
  bool lighth_inside;
  bool movement_outside;
  int t_lighth = 5000;
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
    count |= WATER_PIPE_HEATING;
  } else if (t_outside > 5) {
    count &= ~WATER_PIPE_HEATING;
  }
  if ((time_num > 16 || time_num < 5) && movement_outside) {
    count |= LIGHTS_OUTSIDE;
  } else {
    count &= ~LIGHTS_OUTSIDE;
  }
  if (t_inside < 22) {
    count |= HEATERS;
  } else if (t_inside >= 25) {
    count &= ~HEATERS;
  }
  if (t_inside >= 30) {
    count |= CONDITIONER;
  } else if (t_inside <= 25) {
    count &= ~CONDITIONER;
  }
  if (lighth_inside) {
    count |= LIGHTS_INSIDE;
    if (time_num > 16 && time_num <= 20) {
      t_lighth -= 575;
    } else if (time_num == 0) {
      t_lighth = 5000;
    }
  } else {
    count &= ~LIGHTS_INSIDE;
  }

  if (count & LIGHTS_INSIDE && switches_state & ~LIGHTS_INSIDE) {
    std::cout << "The light in the house is on.\nLight temperature: "
              << t_lighth << std::endl;
  } else if (count & ~LIGHTS_INSIDE && switches_state & LIGHTS_INSIDE) {
    std::cout << "The lights in the house are off.\n";
  }
  if (count & LIGHTS_OUTSIDE && switches_state & ~LIGHTS_OUTSIDE) {
    std::cout << "The street light is on";
  } else if (count & ~LIGHTS_OUTSIDE && switches_state & LIGHTS_OUTSIDE) {
    std::cout << "The street light is off.\n";
  }
  if (count & HEATERS && switches_state & ~HEATERS) {
    std::cout << "Heating on.\n";
  }else if (count & ~HEATERS && switches_state & HEATERS){
    std::cout << "Heating off.\n";
  }else if (count & CONDITIONER && switches_state & ~CONDITIONER){
    std::cout << "Air conditioning on.\n";
  }else if (count & ~CONDITIONER && switches_state & CONDITIONER){
    std::cout << "Air conditioning off.\n";
  }
  if (count & WATER_PIPE_HEATING && switches_state & ~WATER_PIPE_HEATING) {
    std::cout << "Plumbing heating on.\n";
  } else if (count & ~WATER_PIPE_HEATING && switches_state & WATER_PIPE_HEATING) {
    std::cout << "Plumbing heating off.\n";
  }


  return count;
}
int main() {
  
  std::string time = "00:00";
  std::string buffer;

  do {
    time = Time(time);
    std::cout << time << std::endl;
    buffer.clear();
    std::getline(std::cin, buffer);
    
    if (buffer != "-1") {
      

      switches_state = Control(buffer,time);
    }
  } while (buffer != "-1");
}