// queuefunctions.h - Include file for queue functions

#ifndef QUEUEFUNCTIONS_H_INCLUDED
#define QUEUEFUNCTIONS_H_INCLUDED

#include "queuefunctions.h"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10         // The capacity of the queue

// A structure to represent a queue containing ints
typedef struct queue
{
    int  front, rear ,size;
    
    unsigned capacity;
    Fruit *array;     // The queue array of size 'capacity'
} Queue;

// A structure to represent a fruit
typedef struct fruit
{
    char name[20];
    int calories;
    // Add color enumeration field here
} Fruit;

Queue* createQueue(unsigned capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
int size(Queue* queue);
bool enqueue(Queue* queue, Fruit item);
Fruit dequeue(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
void printQueue(char* title, Queue* queue);
void printOneFruit(Fruit fruit, char* sep);

#endif // QUEUEFUNCTIONS_H_INCLUDED
