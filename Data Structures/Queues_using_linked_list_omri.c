#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// first in is to first out - like a line in supermarket

struct Qnode
{
    int key;
    struct Qnode *next;
};

struct Queue
{
struct Qnode *front, *rear;
};

struct Qnode *NewNode(int k)
{
  struct Qnode *temp = (struct Qnode *)malloc(sizeof(struct Qnode));
  temp->key = k;
  temp->next = NULL;
  return temp;
};


struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
};


void enQueue(struct Queue *q, int k) // Insert an element to the back of the Queue
{
    struct Qnode *temp = NewNode(k);

    //If the Queue is empty then the new node is front and rear both
    if(q->rear == NULL)
    {
       q->front = q->rear = temp;
        return;
    }
    //If the Queue is not empty, Add new node at the end of the Queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}


struct Qnode *deQueue (struct Queue *q)// Remove an n element from the front of the Queue
{
    //If Queue is empty
    if(q->front == NULL)
    {
        return NULL;
    }

    //store previous front and move front one node ahead
    struct Qnode *temp = q->front;
    q->front = q->front->next;

    //If front becomes NULL, set rear also to NULL
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    return temp;
};


int main()
{
    struct Queue *q = createQueue();
    enQueue(q,1);
    enQueue(q,2);
    deQueue(q);
    deQueue(q);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    struct Qnode *n = deQueue(q);
    if(n!=NULL)
    {
        printf("Dequeue item is :%d \n", n->key); // FIFO - first in is first out, thats why 3 is deleted.
    }
    return 0;

}
