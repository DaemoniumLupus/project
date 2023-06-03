#include <iostream>
#include <math.h>
#include <vector>

struct Vector {
  int coord_x[2];
  int coord_y[2];
  int x;
  int y;
};

void Enter2vec(Vector &vec1, Vector &vec2, std::string command, int &num) {

  std::cout << "Enter first vector start: ";
  std::cin >> vec1.coord_x[0] >> vec1.coord_y[0];
  std::cout << "Enter first vector finish: ";
  std::cin >> vec1.coord_x[1] >> vec1.coord_y[1];

  if (command == "add" || command == "subtract") {

    std::cout << "Enter second vector start: ";
    std::cin >> vec2.coord_x[0] >> vec2.coord_y[0];

    std::cout << "Enter second vector finish: ";
    std::cin >> vec2.coord_x[1] >> vec2.coord_y[1];
  }
  if (command == "scale") {
    std::cout << "Enter scale: ";
    std::cin >> num;
  }

  vec1.x = vec1.coord_x[1] - vec1.coord_x[0];
  vec1.y = vec1.coord_y[1] - vec1.coord_y[0];

  if (command == "add" || command == "subtract") {
    vec2.x = vec2.coord_x[1] - vec2.coord_x[0];
    vec2.y = vec2.coord_y[1] - vec2.coord_y[0];
  }
}

void Subtract(Vector vec1, Vector vec2) {
  int ras_vec[2];

  ras_vec[0] = vec1.x - vec2.x;
  ras_vec[1] = vec1.y - vec2.y;

  std::cout << "Difference vectors: ";
  std::cout << "{" << ras_vec[0] << ", " << ras_vec[1] << "}";
}

void Add(Vector vec1, Vector vec2) {
  int sum_vec[2];

  sum_vec[0] = vec1.x + vec2.x;
  sum_vec[1] = vec1.y + vec2.y;

  std::cout << "Sum vectors: ";
  std::cout << "{" << sum_vec[0] << ", " << sum_vec[1] << "}";
}

void Scale(Vector vec1, int num) {
  std::cout << "Product of a vector and a scalar: ";
  std::cout << "{" << vec1.x * num << ", " << vec1.y * num << "}";
}

void Length(Vector vec1) {
  std::cout << "Vector length: ";
  std::cout << (double)std::sqrt(std::pow(vec1.x, 2) + std::pow(vec1.y, 2));
}
void Normalize(Vector vec1){
  double length = std::sqrt(std::pow(vec1.x, 2) + std::pow(vec1.y, 2));
  double invLength = 1 / length;
  std::cout << "Normalize vector: ";
  std::cout << "{" << (double)vec1.x * invLength << ", " << (double)vec1.y * invLength << "}";

}

int main() {
  Vector vec1;
  Vector vec2;
  int num;

  std::string command;
  std::cout << "Enter command: ";
  std::cin >> command;

  Enter2vec(vec1, vec2, command, num);

  if (command == "add") {
    Add(vec1, vec2);
  }
  if (command == "subtract") {
    Subtract(vec1, vec2);
  }
  if (command == "scale") {
    Scale(vec1, num);
  }
  if (command == "length") {
    Length(vec1);
  }
  if (command == "normalize"){
    Normalize(vec1);
  }
}
