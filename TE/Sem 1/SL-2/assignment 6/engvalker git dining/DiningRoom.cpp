// Jeremy Engman
// CSCI 4100
// Programming Assignment 4
// Dining Philosophers

#include "DiningRoom.h"
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void DiningRoom::run_simulation()
{
	//display headings, showing philosopher numbers at the top of the columns
	display_headings();
	//display initial philosopher states
	display_states();
	
	//creates threads for every philosopher
	for (int i = 0; i < num_phils; i++)
	{
		//creates thread for philosopher i, using function start_philosopher and information in args_array[i]
		pthread_create(&phil_threads[i], NULL, start_philosopher, &args_array[i]);
	}
	//wait for all threads to complete
	for (int j = 0; j < num_phils; j++)
	{
		pthread_join(phil_threads[j], NULL);
	}
}

bool DiningRoom::test(int phil)
{
	//checks if current philosopher's state is HUNGRY
	if (phil_state[phil] == 1)
	{
		//checks if either left or right neighbor is eating
		if (phil_state[left_neighbor(phil)] != 2 && phil_state[right_neighbor(phil)] != 2)
		{
			//sets current philosopher's state to EATING
			phil_state[phil] = EATING;
			//display philosophers' states
			display_states();
			return true;
		}
		else
		{
			return false;
		}
	}
	
	else
	{
		return false;
	}
}

void DiningRoom::grab_forks(int phil)
{
	//aquire table lock
	pthread_mutex_lock(&table_lock);
	//set philospher's state to HUNGRY
	phil_state[phil] = HUNGRY;
	//display philosophers' states
	display_states();
	//checks if safe to eat, if not wait for condition to change
	if (!test(phil))
	{
		//tells thread to wait until safe_to_eat condition variable changes
		pthread_cond_wait(&safe_to_eat[phil], &table_lock);
	}
	
	//release table_lock
	pthread_mutex_unlock(&table_lock);
}

void DiningRoom::release_forks(int phil)
{
	//aquire table lock
	pthread_mutex_lock(&table_lock);
	//set philospher's state to THINKING
	phil_state[phil] = THINKING;
	//display philosopher's states
	display_states();
	//check neighbor's states and notifiy them if safe to eat
	if (test(left_neighbor(phil)))
	{
		//safe for left neighbor to eat, change their condition variable
		pthread_cond_signal(&safe_to_eat[left_neighbor(phil)]);
	}
	if (test(right_neighbor(phil)))
	{
		//safe for right neighbor to eat, change their condition variable
		pthread_cond_signal(&safe_to_eat[right_neighbor(phil)]);
	}
	
	//release table_lock
	pthread_mutex_unlock(&table_lock);
}

