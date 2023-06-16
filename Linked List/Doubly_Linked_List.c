#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};

void insertAtbegin(struct node **, int);
void insertAtend(struct node **,int);
void insertAfter(struct node **, struct node*, int);
struct node* find(struct node **,int);
int deleteFirst(struct node **);
int deleteLast(struct node **);
int deleteIntermidiate(struct node **, struct node*);
void viewList(struct node**);
int getFirst(struct node **);


struct node* find(struct node **s, int data)
{
    if(*s==NULL)
     printf("List is Empty");

    else{
      struct node *t;
      t=*s;
      while(t!=NULL)
      {
        if(t->info==data)
         return t;

       t=t->next;
      }

      return NULL;
    }
}


void insertAtbegin(struct node **s, int data)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->prev=NULL;
     p->next=*s;
    if(*s==NULL)
     *s=p;
    else{
        (*s)->prev=p; 
        *s=p;
    }

}

void insertAtend(struct node **s, int data)
{
   struct node *p,*temp;
   p=(struct node*)malloc(sizeof(struct node));
   p->info=data;
   p->next=NULL;
   if(*s==NULL){
    p->prev=NULL;
    *s=p;
   }
   else{
   temp=*s;
   while(temp->next!=NULL)
    temp=temp->next;
   
   p->prev=temp;
   temp->next=p;
   }
}

void insertAfter(struct node **s, struct node *p,int data)
{
  if(p==NULL)
   printf("Invalid insertion");
  else{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->info=data;
    n->prev=p;
    n->next=p->next;
    if(p->next!=NULL)
     p->next->prev=n;

    p->next=n;  
  }
}

int deleteFirst(struct node **s)
{
   struct node *t;
   if(*s==NULL)
    return 0;
   else{
    t=*s;
    *s=t->next;
    (*s)->prev=NULL;
    free(t);
    return 1;
   }
}

int deleteLast(struct node **s)
{
  struct node *t;
  if(*s==NULL)
   return 0;
  else if((*s)->next==NULL){ 
    t=*s;
    *s=NULL;
    free(t);
  }
  else{
    t=*s;
    while(t->next!=NULL)
     t=t->next;

    t->prev->next=NULL;
    free(t);
  }
  return 1;
}




int deleteIntermidiate(struct node **s, struct node *ptr)
{
  struct node *t;
  if(*s==NULL)
   return 0;
  else if(ptr->next==NULL)
  {
    *s=NULL;
    free(ptr);
  }
  else if(ptr->prev==NULL)
  {
    *s=ptr->next;
    (*s)->prev=NULL;
    free(ptr);
  } 
  else if(ptr->next==NULL)
  {
    ptr->prev->next=NULL;
    free(ptr);
  }
  else{
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
  }
  return 1;
}

void viewList(struct node **s)
{
  struct node *t;
  if(*s==NULL)
   printf("List is Empty");
  else{
    t=*s;
    while(t!=NULL)
    {
      printf("%d ",t->info);
      t=t->next;
    }
  }
}


int getFirst(struct node **s)
{
  if(*s==NULL){
   printf("List is Empty");
   return -1;
  }
  else
    return (*s)->info;

}

int getLast(struct node **s)
{
  struct node *t;
  if(*s==NULL)
  {
    printf("List is Empty");
    return -1;
  }
  else
   {
    t=*s;
    while(t->next!=NULL)
     t=t->next;

    return t->info;
   }
}
int main()
{
    struct node *start=NULL;
    insertAtbegin(&start,20);
    viewList(&start);
    return 0;
}
