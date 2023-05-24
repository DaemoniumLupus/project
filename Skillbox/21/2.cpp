#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

enum class Room_type { Living, Children, Bathroom, Kitchen, Bedroom };

enum class Build_type { Bath, Garage, Barn };

struct room {
  Room_type name_room;
  int square_room;
};

struct floors {
  int num_floor;
  int ceiling_height;
  std::vector<room> rooms_on_the_floor;
};

struct house {
  int square_house;
  std::vector<floors> floor;
  bool pipe = false;
};

struct building {
  Build_type name;
  int square_bild;
  bool pipe = false;
};

struct plots {
  int num;
  int square_plots;
  house house_on_plots;
  std::vector<building> build;
};

// #define PB plot[count].build[build_count]

int main() {
  int n;

  std::cout << "Enter the number of plots: ";
  std::cin >> n;
  std::vector<plots> plot(n); // участки
  for (int count = 0; count < n; count++) {
    int buf_int;
    std::string buf_str;
    std::vector<std::string> build;

    plot[count].num = count + 1; // номер участка
    std::cout << "Enter square plot: ";
    std::cin >> buf_int;
    plot[count].square_plots = buf_int; // площадь участков
    std::cout << "Buildings other than the house(Bath, Garage, Barn): "
              << std::endl;
    buf_int = 0;
    int number_of_builds;
    while (true) { // количество строений помимо дома
      std::cout << "Enter quantity: ";
      std::cin >> number_of_builds;
      if (number_of_builds <= 0 || number_of_builds > 3) {
        std::cerr << "Incorrect number!" << std::endl;
      }else{
        break;
      }
    }
    plot[count].build.resize(number_of_builds);
    for (int build_count = 0; build_count < number_of_builds;
         build_count++) { // строения
      std::cout << "Enter name " << build_count + 1
                << " build: "; 
      std::cin >> buf_str;
      if (buf_str == "Bath") {
        plot[count].build[build_count].name = Build_type::Bath;
      } else if (buf_str == "Garage") {
        plot[count].build[build_count].name = Build_type::Garage;
      } else if (buf_str == "Barn") {
        plot[count].build[build_count].name = Build_type::Barn;
      }

      std::cout << "Enter square build: ";
      std::cin >> buf_int;

      if (buf_str == "Bath") { // если есть баня есть ли у нее труба
        std::string buf;
        std::cout << "Bath have pipe?(YES/NO)";
        std::cin >> buf;
        if (buf == "YES") {
          plot[count].build[build_count].pipe = true; // труба
        }
      }
    }

    std::string buf;
    std::cout << "House have pipe?(YES/NO)";
    std::cin >> buf;
    if (buf == "YES") {
      plot[count].house_on_plots.pipe = true; // труба
    }

    int number_of_floors = 1;
    std::cout << "Enter the number of floors: ";
    std::cin >> number_of_floors; // этажи в доме
    plot[count].house_on_plots.floor.resize(number_of_floors);

    for (int floor_count = 0; floor_count < number_of_floors; floor_count++) {
      plot[count].house_on_plots.floor[floor_count].num_floor = floor_count + 1;
      std::cout << "Enter the height of the ceiling on the " << floor_count + 1
                << " floor: ";
      float ceiling;
      std::cin >>  ceiling;
      plot[count].house_on_plots.floor[floor_count].ceiling_height =
          ceiling; // высота потолков

      int number_of_room;

      std::cout << "Enter the number of rooms on the " << floor_count + 1
                << " floor: ";
      std::cin >> number_of_room; // количество комнат
      plot[count].house_on_plots.floor[floor_count].rooms_on_the_floor.resize(
          number_of_room);
      for (int room_count = 0; room_count < number_of_room;
           room_count++) { // комнаты
        std::cout << "Enter name " << room_count + 1 << " rooms: ";
        std::cin >> buf_str;
        if (buf_str == "Living") {
          plot[count]
              .house_on_plots.floor[floor_count]
              .rooms_on_the_floor[room_count]
              .name_room = Room_type::Living;
        } else if (buf_str == "Children") {
          plot[count]
              .house_on_plots.floor[floor_count]
              .rooms_on_the_floor[room_count]
              .name_room = Room_type::Children;
        } else if (buf_str == "Bathroom") {
          plot[count]
              .house_on_plots.floor[floor_count]
              .rooms_on_the_floor[room_count]
              .name_room = Room_type::Bathroom;
        } else if (buf_str == "Kitchen") {
          plot[count]
              .house_on_plots.floor[floor_count]
              .rooms_on_the_floor[room_count]
              .name_room = Room_type::Kitchen;
        } else if (buf_str == "Bedroom") {
          plot[count]
              .house_on_plots.floor[floor_count]
              .rooms_on_the_floor[room_count]
              .name_room = Room_type::Bedroom;
        }

        std::cout << "Enter square room: ";
        std::cin >> buf_int; // площадь комнаты
        plot[count]
            .house_on_plots.floor[floor_count]
            .rooms_on_the_floor[room_count]
            .square_room = buf_int;
      }
    }
  }

  int sum_S= 0;
  int sum_S_build = 0;
  for (int i = 0; i < plot.size();i++){
    sum_S += plot[i].square_plots;
    sum_S_build += plot[i].house_on_plots.square_house;
    for (int j = 0; j < plot[i].build.size(); j++)
    {
      sum_S_build += plot[i].build[j].square_bild;
    }
  }
  
  float attitude;
  attitude = sum_S_build / sum_S;
  std::cout << attitude << std::endl;
}
