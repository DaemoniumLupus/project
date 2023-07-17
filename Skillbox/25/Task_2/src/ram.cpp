#include "ram.h"

int buffer[8];

void Write(int &iterator, int &num) { buffer[iterator] = num; }

int Read(int &iterator) { return buffer[iterator]; }