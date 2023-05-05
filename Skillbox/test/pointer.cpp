#include <iostream>

void Main() {
  int i = 10;
  std::cout << &i << std::endl;
  i = 15;
  std::cout << &i << std::endl;
  int *pi = &i;
  std::cout << pi << std::endl;
  std::cout << *pi << std::endl;
  *pi = 20;
  std::cout << i << std::endl;
}
void point() {
  int a = 5;
  double b = 4.2;
  int *pa = &a;
  double *pb = &b;
  std::cout << sizeof(a) << " " << sizeof(pa) << std::endl;
  std::cout << sizeof(b) << " " << sizeof(pb) << std::endl;
}

void mas() {
  int ar[5] = {1, 2, 3, 4, 5};
  std::cout << ar << std::endl;
  std::cout << ar + 1 << std::endl;

  int *pb = ar + 1;
  std::cout << *pb << std::endl;
  std::cout << pb << std::endl;

  double br[5] = {1, 2, 3, 4, 5};
  std::cout << "\n" << br << std::endl;
  std::cout << br + 1 << std::endl;
}

void masPointer() {
  double ar[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    *(ar + i) *= 2;
  }
  for (int i = 0; i < 5; i++)
  {
    std::cout << *(ar + i) << " ";
  }
  
}

void PointerzaGranizy() { double ar[5] = {1, 2, 3, 4, 5};
  double *pb = ar + 10;

  std::cout << pb << std::endl << *pb;
}