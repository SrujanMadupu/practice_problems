#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void addnode(struct node **q,int num);
void show(struct node *q);
int count(struct node *q);
void ConvertSLLtoDLL(struct node *q);
int main(){

struct node *head = NULL;

int Array[]={ 5,2,3,3,2,4 };

int l=sizeof(Array)/sizeof(Array[0]),i;

for(i=0;i<l;i++){
    addnode(&head,Array[i]);
}

show(head);
ConvertSLLtoDLL(head);
show(head);

return 0;
}
void addnode(struct node **q,int num)
 {
    struct node *r=*q;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
    if(*q==NULL)
    {
        *q=temp;
    }
    else
    {
        while(r->next!=NULL)
        {
            r=r->next;
        }
        r->next=temp;
    }
}


void show(struct node *q)
{
    struct node *temp;
    temp=q;
    printf("Elements in the linked list are\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int count(struct node *q)
{
    struct node *temp;
    temp=q;
    int c=0;
    while(temp!=NULL)
    {
        c=c+1;
        temp=temp->next;
    }
    return c;
}

void ConvertSLLtoDLL(struct node *q){
    struct node *first,*second;
    first=q;
    second=first->next;
    while(second!=NULL){
        second->prev=first;
        first=first->next;
        second=second->next;
    }
}
