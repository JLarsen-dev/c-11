// queues.c - C program for circular array implementation of a queue

#include "queuefunctions.h"

/* ---------------------------------------------------------------------
  TODO:
    1. Change the Queue structure to use Fruit instead of ints.
       You may need to reorganize the program a bit to do this
    2. Extend the definition of Fruit to include an enumeration for
       the typical color of the fruit. (E.g., RED, GREEN, YELLOW...)
    3. Update the entire program to work with fruit instead of ints.
       The color of the fruit must be printed by the printOnFruit()
       function
    4. Create a function called calories() that computes the total
       number of calories contained in the queue
    5. Add at least a couple dozen more fruit (they can be 'fruit1',
       'fruit2', 'fruit3', etc., with random numbers of calories (in
       the range 4..400). Store them in an array of fruit
    6. Use the calories function several times with different size
       queues and different contents and display the number of calories
    7. Run your program at least 3 times using capacities of 10, 4, 15
   -------------------------------------------------------------------- */

// Main driver starts here: Demo the queue functions
int main()
{
    printf("\nWorking With a Queue of Capacity %d\n", CAPACITY);
    Queue* queue = createQueue(CAPACITY);

    // Testing simple queue functions
    printQueue("Initially", queue);
    printf("Value returned from overpop is %d\n\n", dequeue(queue));

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue("After enqueuing 4 items", queue);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    printQueue("Now the queue contains", queue);

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    // Try to overflow the queue
    printf("\n");
    int val = 50;
    for (int i = 0; i <= CAPACITY; val += 10, i++)
    {
        if (!enqueue(queue, val))
            break;
    }

    // Final queue tests
    printf("\n%d dequeued from queue\n", dequeue(queue));
    printQueue("At the end, the queue contains", queue);

    // Display the contents of the underlying queue array
    printf("The queue internals:  front=%d  rear=%d  data:\n",
           queue->front, queue->rear);
    for (unsigned i = 0; i < queue->capacity; i++)
        printf("%d ", queue->array[i]);
    printf("\n");

    // Exercise fruit a little bit. This code should be removed
    printf("\nA few fruit:\n");
    Fruit apple = { "apple", 95};
    Fruit pear = { "pear", 100};
    Fruit orange = { "orange", 45};
    printOneFruit(apple, ", ");
    printOneFruit(pear, ", and ");
    printOneFruit(orange, "\n");

    puts("\nDone\n");

    return 0;
} // end main()
