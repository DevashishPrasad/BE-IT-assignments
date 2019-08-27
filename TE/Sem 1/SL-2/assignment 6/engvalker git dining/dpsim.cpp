// CSCI 4100
// Programming Assignment 3
// Main source file for Dining Philosophers simulation

#include "DiningRoom.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  // Check to make sure there are two command line arguments
  if( argc < 2 ) {
    cout << "Usage: dpsimulation num_phils num_cycles" << endl;
    exit(1);
  }

  // Convert the command line arguments to integers
  int num_phils = atoi(argv[1]);
  int num_cycles = atoi(argv[2]);

  // Create DiningRoom monitor object 
  DiningRoom room(num_phils, num_cycles);

  // Run the simulation
  room.run_simulation();
  
  return 0;
}

