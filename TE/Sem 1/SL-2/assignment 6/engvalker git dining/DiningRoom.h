// CSCI 4100
// Programming Assignment 3
// Header file for Dining Philosophers simulation

#ifndef __DINING_ROOM_H__
#define __DINING_ROOM_H__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>

using namespace std;

class DiningRoom;

// Structure used to pass arguments to start_philosopher function
struct phil_args {
  int phil_num;
  int num_cycles;
  DiningRoom *room;
};

// The DiningRoom class acts as a monitor for the simulation
class DiningRoom
{
 private:

  // Number of philosophers
  int num_phils;

  // Number of times each philosopher tries to eat
  int num_cycles;

  // An array containing the current state of each philosopher
  int *phil_state;

  // A lock used to protect the data in phil_state
  pthread_mutex_t table_lock;

  // An array of conditions used to make sure the philsophers don't eat until
  // it is safe to do so
  pthread_cond_t *safe_to_eat;

  // An array of threads representing the philosophers
  pthread_t *phil_threads;

  // An array of structures used to pass arguments to the start_philosophers
  // function
  phil_args *args_array;

  // Used for display functions
  static const int WIDTH = 10;

  // Used to represent philosopher states
  static const int THINKING = 0;
  static const int HUNGRY = 1;
  static const int EATING = 2;

  // Displays the headings for the state change table
  void display_headings( )
  {
    cout << left;
    for(int phil = 0; phil < num_phils; phil++) {
      cout << "PHIL " << setw(WIDTH - 5) << phil;
    }
    cout << endl;
  }

  // Displays the current state of all philosophers.
  // This should only be called if table_lock has been acquired
  void display_states( )
  {
    for( int phil = 0; phil < num_phils; phil++) {
      cout << left << setw(WIDTH);
      switch(phil_state[phil]) {
      case THINKING: cout << "THINKING"; break;
      case HUNGRY: cout << "HUNGRY"; break;
      case EATING: cout << "EATING"; break;
      default: cout << "CONFUSED";
      }
    }
    cout << endl;
    cout.flush( );
  }

  // Gets the ID of the left neighbor of phil
  int left_neighbor( int phil )
  {
    return phil == num_phils - 1? 0 : phil + 1;
  }

  // Gets the ID of the right neighbor of phil
  int right_neighbor( int phil )
  {
    return phil == 0 ? num_phils - 1 : phil - 1;
  }

  // Tests to see if it is safe for the philosopher with the ID provided to eat
  // If it is safe, it changes the philosopher's state to EATING and returns
  // true, if not it returns false.
  // This function must only be called after table_lock has been acquired
  bool test( int phil ); /* IMPLEMENT THIS FUNCTION IN DiningRoom.cpp */

  // Simulates a philosopher thinking
  static void think( )
  {
    unsigned int seed = time(0);
    srand(seed);
    usleep(rand() % 500000);
  }

  // Simulates a philosopher eating
  static void eat( )
  {
    unsigned int seed = time(0);
    srand(seed);
    usleep(rand() % 500000);
  }

  // Code for a philosopher thread to run.
  // This function should be used when creating a new philosopher thread
  static void *start_philosopher( void *_args )
  {
    phil_args *args = static_cast<phil_args *>(_args);  
    for(int i = 0; i < args->num_cycles; i++) {
      think();
      args->room->grab_forks(args->phil_num);
      eat();
      args->room->release_forks(args->phil_num);
    }
    return NULL;
  }
  

public:

  // Constructor
  // num_phils is the number of philosophers
  // num_cycles is the number of times each philosopher tries to eat
  DiningRoom( int _num_phils, int _num_cycles )
  {
    // Initialize the simulation parameters
    num_phils = _num_phils;
    num_cycles = _num_cycles;

    // Initialize the table lock
    pthread_mutex_init(&table_lock, NULL);

    // Create all of the arrays
    phil_state = new int[num_phils];
    safe_to_eat = new pthread_cond_t[num_phils];
    phil_threads = new pthread_t[num_phils];
    args_array = new phil_args[num_phils];

    // Initialize the data in the arrays
    for(int phil = 0; phil < num_phils; phil++) {
      phil_state[phil] = THINKING;
      pthread_cond_init(&safe_to_eat[phil], NULL);
      args_array[phil].phil_num = phil;
      args_array[phil].num_cycles = num_cycles;
      args_array[phil].room = this;
    }
  }

  // Destructor
  ~DiningRoom( )
    {
      delete [] phil_state;
      delete [] safe_to_eat;
      delete [] phil_threads;
      delete [] args_array;
    }

  // Starts a dining philosopher simulation with parameters provided to the
  // DiningRoom constructor.
  void run_simulation( ); /* IMPLEMENT THIS FUNCTION IN DiningRoom.cpp */

  // Simulates a philosopher picking up forks
  void grab_forks( int phil ); /* IMPLEMENT THIS FUNCTION IN DiningRoom.cpp */

  // Simulates a philosopher putting down forks
  void release_forks( int phil ); /* IMPLEMENT THIS FUNCTION IN DiningRoom.cpp */
  
};

#endif

