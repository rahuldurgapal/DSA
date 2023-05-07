#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int capacity;
    int front;
    int rear;
    int *arr;
};

struct Queue* createQueue(int cap)
{
    struct Queue *q;
    q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=cap;
    q->front=-1;
    q->rear=-1;
    q->arr=(int*)malloc(sizeof(int)*q->capacity);

    return q;
}

int isEmptyQueue(struct Queue* q)
{
  if(q->front==-1)
   return 1;
  else
   return 0;
}

int isFullQueue(struct Queue *q)
{
    if(q->front==0 &&  q->rear==q->capacity-1)
     return 1;
    else if(q->front==q->rear+1)
     return 1;
    else 
     return 0;
}

int queueCapacity(struct Queue *q)
{
    return q->capacity;
}



void halfQueue(struct Queue *q)
{
    int i,j,l;
    int *temp;
    l=q->capacity/2;
    temp=(int*)malloc(sizeof(int)*l);
    for(i=0,j=q->front;i<l;i++)
    {
        temp[i]=q->arr[j];
        if(j==l-1)
         j=0;
        else
         j++;

        free(q->arr);
        q->arr=temp;

        q->capacity=l;
        q->front=0;
        q->rear=l-1;
    }

}

void doubleQueue(struct Queue *q)
{
    int i,j,l;
    int *temp;
    q->capacity=q->capacity*2;
    temp=(int*)malloc(sizeof(int)*l);
    for(i=q->front,j=0;i!=q->rear;j++)
    {
        temp[j]=q->arr[i];
        if(i==q->capacity/2-1 && q->rear!=i)
         i=0;
        else
         i++;
    }
    free(q->arr);
    q->arr=temp;

    q->front=0;
    q->rear=q->capacity/2-1;
    q->capacity=q->capacity;

}

void enQueue(struct Queue *q, int val)
{
    if(q->capacity<1)
     printf("Invalid Capacity");
    
    else if(isEmptyQueue(q))
    {
        q->front++;
        q->rear++;
        q->arr[q->rear]=val;
    }

    else if(isFullQueue(q))
    {
        doubleQueue(q);
        q->rear++;
        q->arr[q->rear]=val;
    }

    else
    {
        if(q->rear==q->capacity-1)
         q->rear=0;
        else
         q->rear++;

        q->arr[q->rear]=val;
    }
}

int main()
{
    struct Queue *q;
    q=createQueue(4);
    enQueue(q,12);
    printf("\ncapacity is %d front=%d rear=%d",q->capacity,q->front,q->rear);
    enQueue(q,3);
    printf("\ncapacity is %d front=%d rear=%d",q->capacity,q->front,q->rear);
    enQueue(q,15);
    printf("\ncapacity is %d front=%d rear=%d",q->capacity,q->front,q->rear); 
    enQueue(q,20);
    printf("\ncapacity is %d front=%d rear=%d",q->capacity,q->front,q->rear);
    enQueue(q,42);
    printf("\ncapacity is %d front=%d rear=%d",q->capacity,q->front,q->rear);
    return 0;
}