#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};

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
int main()
{
    struct node *start=NULL;
    insertAtbegin(&start,10)
    insertAtend(&start,15);
    return 0;
}
