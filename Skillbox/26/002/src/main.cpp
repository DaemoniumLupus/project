#include "phone.h"
#include <iostream>


int main() {
  Cellphone *cellphone = new Cellphone;
  cellphone->turnOn();
  delete cellphone;
  cellphone = nullptr;
}