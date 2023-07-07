#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};

struct node *start=NULL;
struct node *temp;

struct node* createNode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}

void insert(int data)
{
    struct node *n;
    n=createNode();
    n->next=NULL;
    n->val=data;
    if(start==NULL)
    {
        start=n;
        temp=n;
    }
    else{
     temp->next=n;
     temp=n;
    }
}

void viewList()
{
    struct node *t;
    t=start;
    while(t!=NULL)
    {
        printf("%d ",t->val);
        t=t->next;
    }
}

int main()
{
    int ch;

    while(1)
    {
    printf("\n1. Insert data\n");
    printf("2. ViewList\n");
    printf("3. Exit\n");

    printf("\nEnter Your Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
          insert(1);
          insert(2);
          break;
        case 2:
          viewList();
          getchar();
          break;
        case 3:
         exit(0);
    }
}
return 0;
}