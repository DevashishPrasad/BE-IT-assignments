// NOTE : PLEASE RUN IT WITH '-lpthread'

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

// Philosopher Number
#define N 5

// States of Pholosoper
enum
{
    THINKING,
    EATING,
    HUNGRY
} state[N];

// Mutexs and Semaphores
pthread_mutex_t lock;
sem_t chopsticks[N];

// Thread function for philosopher
void *philosopher(void *no);

// Other functions
void takeChopstick(int i);
void putChopstick(int i);
void think(int i);
void eat(int i);

// Keep's track of how much each philosopher got chance to eat
int eatCount[N] = {0};

// MAIN START
void main()
{
    int *arg, i, result;

    result = pthread_mutex_init(&lock, NULL);

    //  Philosopher Thread
    pthread_t philosopherThread;

    // Intializing the chopsticks semaphores
    for (i = 0; i < N; i++)
    {
        result = sem_init(&chopsticks[i], 0, 1);
        if (result != 0)
        {
            printf("\nERROR : CHOPSTICKS INTIALIZTION");
        }
    }
    for (i = 0; i < N; i++)
    {
        // Allocating a different memory for each thread id (as 'i' is their id)
        arg = (int *)malloc(sizeof(int));
        *arg = i;

        // Creating the chopsticks semaphores
        result = pthread_create(&philosopherThread, NULL, philosopher, (void *)arg);
        
        if (result != 0)
        {
            printf("\nERROR : PHILOSOPHER THREAD CREATION");
        }
    }

    // Waiting for all Threads to Join
    for (i = 0; i < N; i++)
    {
        result = pthread_join(philosopherThread, NULL);
        if (result != 0)
        {
            printf("\nERROR : PHILOSOPHER THREAD JOINING");
        }
    }
}

// The Philosopher Function
void *philosopher(void *arg)
{
    int i;
    i = *(int *)arg;
    printf("Philosoper %d Entered\n", i);
    while (1)
    {
        think(i);
        eat(i);
    }
}

// Philosopher Thinking
void think(int i)
{
    if (state[i] == THINKING)
    {
        int temp = rand() % 3;
        temp = (temp == 0 ? 2 : temp);
        printf("\nPhilosopsher %d : THINKING \n", i);
        sleep(temp); // Thinking for Random time
        state[i] = HUNGRY; 
    }
}

// Took the Chopsticks
void takeChopstick(int i)
{
    sem_wait(&chopsticks[i]);
    sem_wait(&chopsticks[(i + 1) % N]);
}

// Put the Chopsticks
void putChopstick(int i)
{
    sem_post(&chopsticks[i]);
    sem_post(&chopsticks[(i + 1) % N]);
}

// Want to Eating
void eat(int i)
{
    int temp = rand() % 3;
    temp = temp == 0 ? 1 : temp;
    
    int j;
    if (state[(i + 1) % N] != EATING && state[(i + (N - 1)) % N] != EATING && state[i] == HUNGRY)
    {
        state[i] = EATING;
        printf("\n\tPhilosopsher %d is EATING", i);
        takeChopstick(i);
        sleep(temp);
        eatCount[i]++;

        printf("\n\t\tPhilosopsher %d HAS DONE EATING", i);
        putChopstick(i);
        state[i] = THINKING;

        pthread_mutex_lock(&lock);
        printf("\n========================================");
        printf("\n\nEat Count : [");
        for (j = 0; j < N; j++)
        {
            printf(" %d", eatCount[j]);
        }
        printf("]");
        printf("\n========================================\n");
        pthread_mutex_unlock(&lock);
    }
}
