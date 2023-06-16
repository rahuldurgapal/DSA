#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};

void insertAtbegin(struct node **, int);
void insertAtend(struct node **,int);
void insertAfter(structn node **, struct node*, int);
struct node* find(struct node **,int);
void deleteFirst(struct node **);


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
    p=(struct node*)malloc(sizeof(structn node));
    p->info=data;
    p->prev=NULL;
     p->next=*s;
    if(*s==NULL)
     *s=p;
    else{
        *s->prev=p; 
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
    *s->prev=NULL;
    free(t);
    return 1;
   }
}

int main()
{
    struct node *start=NULL,*p;
    p=find(&start,20);
    insertAtbegin(&start,10)
    insertAtend(&start,15);
    insertAfter(&start,p,30);
    deleteFirst(&start);
    return 0;
}
