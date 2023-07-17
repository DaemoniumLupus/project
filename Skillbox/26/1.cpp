#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

class Track {
  std::string name;
  std::tm *time;
  int duration;

public:
  std::string getName() { return name; }
  void getInfo() {
    std::cout << name << std::endl;
    std::cout << time->tm_year << "/" << time->tm_mon << "/" << time->tm_mday
              << std::endl;
    std::cout << duration << " sec." << std::endl;
  }
};

class Player {
  std::vector<Track> playList;
  std::string playerStatus;
  int numberTrack;

  void Play(int num) {

    playerStatus = "play";
    playList[num].getInfo();
  }
public:
  void setPlay() {
    int num;
    if (playerStatus != "play") {
      std::cout << "Enter track: " << std::endl;
      for (int i = 0; i < playList.size(); i++) {
        std::cout << i + 1 << ". " << playList[i].getName() << std::endl;
      }
      std::cin >> num;
      numberTrack = num;
      Play(num);
    }
  }

  void Pause() {
    if (playerStatus == "play") {
      std::cout << "Player pause!" << std::endl;
      playerStatus = "pause";
    }
  }

  void Next() {
    int num;
    while (true) {
      num = rand() % (playList.size() + 1);
      if (num != numberTrack) {
        break;
      }
    }
    Play(num);
  }
  void Stop() {
    if (playerStatus != "stop") {
      std::cout << "Player stop!" << std::endl;
      playerStatus = "stop";
    }
  }

}

int main() {
  Player player;
  std::string command;
  std::cout << "Enter command: ";
  std::cin >> command;
  while (command != "exit") {
    if (command == "play") {
      
}
    std::cout << "Enter command: ";
    std::cin >> command;
  }
}