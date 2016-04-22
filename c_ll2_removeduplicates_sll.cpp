#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addnode(struct node **q,int num);
void show(struct node *q);
void RemoveDuplicates(struct node *q);
int main(){

struct node *head = NULL;

int UnsortedArray[]={ 5,2,3,3,2,4 };

int l=sizeof(UnsortedArray)/sizeof(UnsortedArray[0]),i;

for(i=0;i<l;i++){
    addnode(&head,UnsortedArray[i]);
}

printf("Before Deleting Duplicates\n");

show(head);

RemoveDuplicates(head);

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


void RemoveDuplicates(struct node *q)   //Removes Duplicates and Store elements in Given Order
{
    int i,nums[100]= {0},nlen=0;
    struct node *temp,*ntemp,*prev;
    temp=ntemp=q;
    while(temp)
    {
        if(nums[temp->data]==0)
        {
            prev=ntemp;
            ntemp->data=temp->data;
            ntemp=ntemp->next;
            nlen++;
        }
        nums[temp->data]++;
        temp=temp->next;
    }
    temp=prev->next;
    prev->next=NULL;
    while(temp)   //making Duplicates Free
    {
        prev=temp;
        temp=temp->next;
        free(prev);
    }
}
