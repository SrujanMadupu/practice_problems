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
struct node* reverse_every_k_nodes(struct node *head, int k);
int main(){

struct node *head = NULL;

int Array[]={ 5,2,3,8,1,4,6,7,11,14,13 };

int l=sizeof(Array)/sizeof(Array[0]),i;

for(i=0;i<l;i++){
    addnode(&head,Array[i]);
}

printf("Before Reversing elements\n");
show(head);

head = reverse_every_k_nodes(head,3);

printf("After Reversing elements\n");
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

struct node* reverse_every_k_nodes(struct node *head, int k){
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *next = NULL;
    int i = 0;
    while(cur != NULL && i < k){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        i++;
    }
    if(cur != NULL)
        head->next = reverse_every_k_nodes(cur, k);
    return prev;
}


