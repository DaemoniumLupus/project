#include "player.h"
#include <iostream>


int main() {
  Player *player = new Player;
  player->addTrack(Track::createTrack("Sting", std::time(nullptr), 200));
  player->addTrack(Track::createTrack("Scorpions", std::time(nullptr), 300));
  player->addTrack(Track::createTrack("Rammstein", std::time(nullptr), 250));
  player->turnOn();
  delete player;
  player = nullptr;
}