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

struct Queue* deleteQueue(struct Queue *q)
{
    free(q->arr);
    free(q);

    return NULL;
}


int isEmptyQueue(struct Queue *q)
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

void deQueue(struct Queue *q)
{
   int i,j,size=0;


   if(isEmptyQueue(q)){
    printf("Queue is Empty");
    return;
   }

   else if(q->front==q->rear)
    q->front=-1, q->rear=-1;

   else if(q->front==q->capacity-1)
    q->front=0;

   else 
    q->front=q->front+1;

    if(q->front>-1)
    {
        for(i=q->front;i!=q->rear;)
        {
            size++;
            if(i==q->capacity-1)
               i=0;
            else
             i++;
        }
        size++;
    }
    if(size==q->capacity/2)
     halfQueue(q);
}

int menu()
{
    int choice;
    // system("clear");
    printf("\n1. See the Status of Queue");
    printf("\n2. Insert a data in Queue");
    printf("\n3. Remove a data from Queue");
    printf("\n4. End Program");
    printf("\n\nEnter Your Choice\n");
    scanf("%d",&choice);
    return choice;


}

int main()
{
    struct Queue *q;
    q=createQueue(4);
    while(1)
    {
        switch(menu())
        {
            case 1:
               printf("\nCapacity: %d",queueCapacity(q));
               printf("\nFront= %d  Rear= %d",q->front,q->rear);
               break;
            case 2:
               int value;
               printf("\nEnter a number\n");
               scanf("%d",&value);
               enQueue(q,value);
               break;
            case 3:
               deQueue(q);
               break;
            case 4:
                  q=deleteQueue(q);
                  exit(0);
            default:
              printf("Invalid Choice, Retry");
        }
    }

    return 0;
}