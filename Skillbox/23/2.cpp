#include <iostream>

#define SPRING 0
#define SUMMER 0
#define AUTUMN 0
#define WINTER 0
#define COUT_SPRING std::cout << "SPRING!" << std::endl;
#define COUT_SUMMER std::cout << "SUMMER!" << std::endl;
#define COUT_AUTUMN std::cout << "AUTUMN!" << std::endl;
#define COUT_WINTER std::cout << "WINTER!" << std::endl;


#if SPRING
int main() {COUT_SPRING }
#endif
#if SUMMER
int main() {COUT_SUMMER }
#endif
#if AUTUMN
int main() {COUT_AUTUMN }
#endif
#if WINTER
int main() {COUT_WINTER }
#endif