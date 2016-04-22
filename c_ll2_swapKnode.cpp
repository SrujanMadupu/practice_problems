#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addnode(struct node **q,int num);
void show(struct node *q);
int count(struct node *q);
void SwappingKthnodes(struct node **q,int k);
int main(){

struct node *head = NULL;

int Array[]={ 5,6,3,3,2,4 };

int l=sizeof(Array)/sizeof(Array[0]),i;

for(i=0;i<l;i++){
    addnode(&head,Array[i]);
}

printf("Before Deleting Duplicates\n");

show(head);

SwappingKthnodes(&head,7);

printf("After Deleting Duplicates\n");

show(head);

return 0;
}
void addnode(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->next=NULL;
        *q=temp;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        r=malloc(sizeof(struct node));
        r->data=num;
        temp->next=r;
        r->next=NULL;

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
void SwappingKthnodes(struct node **q,int k){
  int len = count(*q);
  if(k>len){
    return;
  }
  if(k==len){
    k=1;
  }
  struct node *front,*last,*kfront,*klast;
  front=last = *q;


int t = k;
while(t>2){
    front= front->next;
    t--;
}
t = len - k - 1;
while(t>0){
    last = last->next;
    t--;
}
  if(k==1){
    klast = last->next;
    klast->next = front->next;
    front->next= NULL;
    last->next=front;
    *q=klast;
  }
  else{
 kfront= front->next;
 klast = last->next->next;
 front->next=last->next;
 front->next->next=kfront->next;
 last->next=kfront;
 kfront->next =klast;
}
}
