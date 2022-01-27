/*
This program uses structures and the rest of my C knowledge to create a racr simulator.

First I define complex data types using structures. 
Then I create some fun print functions to help update the audience. 
Finally, I implement functions to help with the racing logic and start the race!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[25];
  char firstPlaceRaceCarColor[25];
};

struct RaceCar {
  char driverName[25];
  char raceCarColor[25];
  int totalLapTime;
};

// Print functions section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printIntro()
{
    printf("Welcome to Race Simulator!\n");
}
void printCountDown()
{
    printf("Racers Ready! In...\n");
    for (int i = 5; i > 0; i--)
    {
        printf("%i\n", i);
    }
    printf("Race!\n\n");
}
void printFirstPlaceAfterLap(struct Race race)
{
    printf("After lap number %d\n", race.currentLap);
    printf("First Place is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race)
{
    printf("\n\nLet's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!\n");
}
int calculateTimeToCompleteLap()
{
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
};
// Logic functions section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void updateRaceCar(struct RaceCar *raceCar)
{
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
    {
      strcpy(race->firstPlaceDriverName, raceCar1->driverName);
      strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    }
  else 
    {
      strcpy(race->firstPlaceDriverName, raceCar2->driverName);
      strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
}
void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) 
{
  struct Race race = {5, 0, "", ""};
  for (int i = 0; i < race.numberOfLaps; i++) 
  {
    race.currentLap++;
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}

// main() function section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {
    srand(time(0));
    struct RaceCar raceCar1 = {"Stella", "purple", 0};
    struct RaceCar raceCar2 = {"Mike", "gold", 0};
    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
};
