#include<stdio.h>
#include<stdlib.h>


struct list
{
    int data;
    struct list *next;
};

struct list* createNode()
{
    struct list *node;
    node=(struct list*)malloc(sizeof(struct list));
    return node;
}

struct list *start = NULL;

//insert data at first

void insertAtbegin()
{
    printf("Enter the data\n");
    struct list *node,*temp;
    node=createNode();
    if(start==NULL){
     start=node;
     scanf("%d",&start->data);
     start->next=NULL;
    }
   else{
     temp=start;
     start=node;
     start->next=temp;
     scanf("%d",&start->data);
   }
}

void insertAtend()
{
   struct list *node,*temp,*t;
   node = createNode();
   printf("Enter the data\n");
   if(start==NULL){
     start=node;
     scanf("%d",&start->data);
     start->next=NULL;
    }
   else{
     temp=start;
     while(temp->next!=NULL)
      temp=temp->next;
    scanf("%d",&node->data);
    node->next=NULL;
    temp->next=node;   
   }
}

void deleteAtbegin()
{
    struct list *temp;
    if(start==NULL)
     printf("The List is Empty\n");
    else{
        temp=start;
        start=temp->next;
        free(temp);
    }
}

void deleteAtend()
{
   struct list *temp,*ptr;
   if(start==NULL)
    printf("The List is Empty\n");
   else{
    temp=start;
    while(temp->next!=NULL){
    
     ptr = temp;
     temp=temp->next;
    }
     
    ptr->next=NULL;
    free(temp);
   }
}

void viewList()
{
    struct list *temp;
    if(start==NULL)
     printf("The List is Empty\n");  
    else{
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}


int main()
{
    int ch;
    while(1)
    {
    //   system("clear");

      printf("\n1. Insert Data at Begin\n");
      printf("2. Insert Data at End\n");
      printf("3. Delete at Begin\n");
      printf("4. Delete at End\n");
      printf("5. View List\n");
      printf("6. Exit\n");
      printf("\n Enter Your Choice\n");
      scanf("%d",&ch);
      
      switch(ch)
      {
          case 1:
              insertAtbegin();
              break;
          case 2:
              insertAtend();
              break;
          case 3:
              deleteAtbegin();
              break;
         case 4:
              deleteAtend();
              break;
         case 5:
              viewList();
              getchar();
              break;
        case 6:
              exit(0);
         default:
              printf("Invalid choice");
              getchar();
      }
    }
    return 0;
}