#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

typedef int Item;

typedef struct {
    int size, front, rear, capacity;
    Item *array;
} Queue;

Queue* createQueue(int size) {
    Queue *queue = malloc(sizeof(Queue));

    queue->rear = size - 1;
    queue->size = queue->front;
    queue->capacity = size;

    queue->array = malloc(queue->capacity * sizeof(Item));

    return queue;
}

int isFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

int enqueue(Queue *queue, Item item) {
    if(isFull(queue))
        return 0;
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;

    return 1;
}

Item front(Queue *queue) {
    return queue->array[queue->front];
}

int dequeue(Queue *queue) {
    if(isEmpty(queue))
        return -1;

    Item aux = front(queue);

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return aux;
}

int main(void) {
    int n;

    scanf("%d", &n);

    Queue *queue = createQueue(n);

    for(int i = 1; i <= n; i++)
        enqueue(queue, i);
    
    printf("Cartas descartadas: 1");

    dequeue(queue);
    enqueue(queue, dequeue(queue));
    
    while(queue->size != 1) {
        printf(", %d", front(queue));

        dequeue(queue);
        enqueue(queue, dequeue(queue));
    }

    printf("\nCarta restante: %d\n", front(queue));
}