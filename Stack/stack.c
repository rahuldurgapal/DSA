#include<stdio.h>
#include<stdlib.h>
struct arrayStack{
    int top;
    int capacity;
    int *arr;
};

struct arrayStack* createStack(int cap)  //cap is used to create the size of the array
{
    struct arrayStack *stack;         //stack is used to store the address of the sturct arrayStack
    stack=malloc(sizeof(struct arrayStack));     //creates memory for struct arrayStack
    stack->capacity=cap;               
    stack->top=-1;                        //initialise the value of top=-1
    stack->arr=malloc(sizeof(int)*stack->capacity);    // cretes array memory for stack->arr

    return stack;
}

int isFull(struct arrayStack *stack)     //check function is stack is full
{
   if(stack->top==stack->capacity-1)   
    return 1;
   else
     return 0;
}
int isEmpty(struct arrayStack *stack)     //check function is stack is empty
{
    if(stack->top==-1)
     return 1;
    else
     return 0;
}

void push(struct arrayStack *stack, int item)     //push operation function in stack
{
   if(!isFull(stack))
   {
    stack->top++;
    stack->arr[stack->top]=item;
   }
}

int pop(struct arrayStack *stack)          //pop operation function in stack
{
    int item;
    if(!isEmpty(stack))
    {
        item=stack->arr[stack->top];
        stack->top--;
        return item;
    }
    return -1;
}

int main()
{
    int item;
    int choice;
    struct arrayStack *stack;
    stack=createStack(4);
    while(1)
    {
        system("clear");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("\n Enter your choice\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
               printf("\n Enter a number\n");
               scanf("%d",&item);
               push(stack,item);
               break;
            
            case 2:
               item=pop(stack);
               if(item!=-1)
               printf("\n Poped value is %d \n",item);
               else
                printf("Stack is Empty\n");
               break;

            case 3:
              exit(0);
               
        }
    }
    return 0;
}