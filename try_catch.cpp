#include <iostream>

struct SolarEclipse {};
struct Fire {};

bool learn_ds() {
  // Something important
  if (rand() % 2) 
    throw SolarEclipse{};
  if (rand() % 2) 
    throw Fire{};
  // Something else. Also important
  return true;
}

void go_out_and_look_at_sun() {}
void call_fireman() {}

int main() {
  srand(time(0));
  bool result = false;

  while (!result) {
    try {
      result = learn_ds();
    }
    catch(SolarEclipse) {
      go_out_and_look_at_sun();  
    }
    catch(Fire) {
      call_fireman();
      break;
    }
  }

  std::cout << result;
}