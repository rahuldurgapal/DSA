#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

struct node* createNode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));

    return n;
}

void insertAtFirst()
{
    struct node *temp,*t;
   temp=createNode();
   printf("Enter a number\n");
   scanf("%d",&temp->info);
   temp->link=NULL;

   if(start==NULL)
    start=temp;

  else{
      temp->link=start;
      start=temp;
  }
}
// void insertNode()
// {
//    struct node *temp,*t;
//    temp=createNode();
//    printf("Enter a number\n");
//    scanf("%d",&temp->info);
//    temp->link=NULL;

//    if(start==NULL)
//     start=temp;

//   else{
//      t=start;
//      while(t->link!=NULL)
//         t=t->link;

//     t->link=temp;
//   }
// }

void deleteNode()
{
    struct node *r;

    if(start==NULL)
     printf("List is Empty");
    else{
    r=start;
    start=start->link;
    free(r);
    }
    
}

void viewList()
{
    struct node *t;
    if(start==NULL)
     printf("List is Empty");
    else{
    t=start;
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t=t->link;
    }
    }
}

int menu()
{
    int ch;
    printf("\n1. Add value to the list");
    printf("\n2. Delete First Value");
    printf("\n3. View List");
    printf("\n4. Exit\n\n");
    printf("Enter Your Choice\n");
    scanf("%d",&ch);
    
    return ch;
}

int main()
{
    while(1)
    {
        switch(menu())
        {
            case 1:
                insertAtFirst();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                viewList();
                break;
            case 4:
                exit(0);
                break;
            default:
              printf("Invalid Choice");
        }
    }
    return 0;
}
