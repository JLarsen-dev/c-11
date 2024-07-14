// queuefunctions.c - Sources for queue support functions

#include "queuefunctions.h"
Fruit none = {"none", 0};
// Creates an empty queue of a specified capacity
Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // Allocate the data array for the queue contents
    queue->rear = capacity - 1;
    queue->array = (Fruit*)malloc(queue->capacity * sizeof(Fruit));
    return queue;
} // end createQueue()

// The queue is full when size becomes equal to the capacity
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

// The queue is empty when size is 0
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

// Returns the current size of the queue
int size(Queue* queue)
{
    return queue->size;
}

// Add an item to the queue. Changes rear and size
bool enqueue(Queue* queue, Fruit *item)
{
    if (isFull(queue))
    {
        printf("Queue capacity (%u) has been reached\n", queue->capacity);
        return false;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    *(queue->array + queue->rear) = *item;
    queue->size = queue->size + 1;
    printf("%s enqueued to queue\n", item);
    return true;
} // end enqueue()

// Remove (and return) an item from queue. Changes front and size
Fruit dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return none;
    Fruit *item = &queue->array[queue->front];
    queue->array[queue->front] = none;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return *item;
} // end dequeue()

// Get the value at the front of the queue
Fruit front(Queue* queue)
{
    if (isEmpty(queue))
        return none;
    return queue->array[queue->front];
}

// Get the value at the rear of the queue
Fruit rear(Queue* queue)
{
    if (isEmpty(queue))
        return none;
    return queue->array[queue->rear];
}

// Print the entire queue
void printQueue(char* title, Queue* queue)
{
    printf("\n%s:\n", title);
    if (isEmpty(queue))
    {
        printf("The queue is empty\n\n");
        return;
    }
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity)
        printf("%d ", queue->array[i]);
    printf("%d\n\n", queue->array[i]);
} // end printQueue()

// Print a fruit with 'sep' as separator after the fruit is displayed
void printOneFruit(Fruit fruit, char* sep)
{
    // Modify to include fruit color after calories
    printf("[%s, %d calories]%s", fruit.name, fruit.calories, sep);
}
