#include <iostream>
#include <vector>

struct Vector {
  int coord_x[2];
  int coord_y[2];
  int x;
  int y;
};




void Enter2vec(Vector &vec1,Vector &vec2){
  std::cout << "Enter first vector start: ";
  std::cin >> vec1.coord_x[0] >> vec1.coord_y[0];

  std::cout << "Enter first vector finish: ";
  std::cin >> vec1.coord_x[1] >> vec1.coord_y[1];

  std::cout << "Enter second vector start: ";
  std::cin >> vec2.coord_x[0] >> vec2.coord_y[0];

  std::cout << "Enter second vector finish: ";
  std::cin >> vec2.coord_x[1] >> vec2.coord_y[1];

  vec1.x = vec1.coord_x[1] - vec1.coord_x[0];
  vec1.y = vec1.coord_y[1] - vec1.coord_y[0];

  vec2.x = vec2.coord_x[1] - vec2.coord_x[0];
  vec2.y = vec2.coord_y[1] - vec2.coord_y[0];
}

void Subtract(Vector &vec1,Vector &vec2){
  int ras_vec[2];

  ras_vec[0] = vec1.x - vec2.x;
  ras_vec[1] = vec1.y - vec2.y;

  std::cout << "Difference vectors: ";
  std::cout << "{" << ras_vec[0] << ", " << ras_vec[1] << "}";
}

void Add(Vector& vec1,Vector& vec2) {
  int sum_vec[2];

  sum_vec[0] = vec1.x + vec2.x;
  sum_vec[1] = vec1.y + vec2.y;

  std::cout << "Sum vectors: ";
  std::cout << "{" << sum_vec[0] << ", " << sum_vec[1] << "}";

}

int main() {
  Vector vec1;
  Vector vec2;

  std::string command;
  std::cout << "Enter command: ";
  std::cin >> command;

  if (command == "add") {
    Enter2vec(vec1,vec2);
    Add(vec1,vec2);
  }
  if (command == "subtract") {
    Enter2vec(vec1, vec2);
    Subtract(vec1, vec2);
  }
}
