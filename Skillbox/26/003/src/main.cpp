#include "Window.h"
#include <iostream>


int main() {
  Window window;
  window.init();
  window.control();
  std::cout << "End.." << std::endl;
}