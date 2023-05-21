#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

enum class Room_type { Living, Children, Bath, Kitchen, Bedroom };

enum class Build_type { Bath, Garage, Barn };

struct plots {
  int num;
  int square_plots;
  house house_on_plots;
  std::vector<building> build;
};
struct house {
  int square_house;
  std::vector<floors> floor[4];
};
struct floors {
  int num;
  int ceiling_height;
  std::vector<room> rooms_on_the_floor[4];
};

struct room {
  Room_type name;
  int square;
};
struct building {
  Build_type name;
  int square_bild;
  bool pipe = false;
};

// #define PB plot[count].build[build_count]

int main() {
  int n;

  std::cout << "Enter the number of plots: ";
  std::cin >> n;
  std::vector<plots> plot(n);
  for (int count = 0; count < n; count++) {
    int buf_int;
    std::string buf_str;
    std::vector<std::string> build;

    plot[count].num = count + 1;
    std::cout << "Enter square plot: ";
    std::cin >> buf_int;
    plot[count].square_plots = buf_int;
    std::cout << "Buildings other than the house(Bath, Garage, Barn): "
              << std::endl;
    buf_int = 0;
    while (!(buf_int > 0 && buf_int <= 3)) {
      std::cout << "Enter quantity: ";
      std::cin >> buf_int;
      if (buf_int <= 0 || buf_int > 3) {
        std::cerr << "Incorrect number!" << std::endl;
        continue;
      }
      bool corr = true;
      for (int build_count = 0; build_count < buf_int; build_count++) {
        std::cout << "Enter name "<< build_count + 1 << " build: ";
        std::cin >> buf_str;
        if (buf_str == "Bath") {
          plot[count].build[build_count].name = Build_type::Bath;
        } else if (buf_str == "Garage") {
          plot[count].build[build_count].name = Build_type::Garage;
        } else if (buf_str == "Barn") {
          plot[count].build[build_count].name = Build_type::Barn;
        }
        if (buf_str == "Barn") {
          std::string buf;
          std::cout << "Barn have pipe?(YES/NO)";
          std::cin >> buf;
          if (buf == "YES") {
            plot[count].build[build_count].pipe = true;
          }
        }
      }
      int number_of_floors = 1;
      std::cout << "Enter the number of floors: ";
      std::cin >> number_of_floors;

      for (int floor_count = 0; floor_count < number_of_floors; floor_count++) {
        std::cout << "Enter the number of rooms on the " << floor_count << " floor";
        std::cin >> buf_int;
        for (int  room_count = 0; room_count < buf_int; room_count++)
        {
          plot[count].house_on_plots.floor[floor_count].num = room_count;
          plot[count].house_on_plots.floor[floor_count];
          std::cout << "Enter name " << floor_count + 1 << " rooms: ";
          std::cin >> buf_str;
          if (buf_str == "Living") {
            plot[count].house_on_plots.floor[floor_count]
            } else if (buf_str == "Garage") {
            plot[count].house_on_plots.floor[floor_count];
          } else if (buf_str == "Barn") {
            plot[count].house_on_plots.floor[floor_count];
          }
        }
        
      }
    }
  }
}
